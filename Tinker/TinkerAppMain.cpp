//
//	TinkerAppMain.cpp
//	Tinker v0.1
//
//	Copyright © 2017-2019 Julius Oklamcak. All rights reserved.
//

#include "stdafx.hpp"
#include "TinkerAppMain.hpp"

//#include <crtdbg.h>

using namespace UXReader;

//
//	Globals
//

static std::unique_ptr<UXReaderMainWindow> g_UXReaderMainWindow;

//
//	Constants
//

static wchar_t *const kApplicationName = L"Tinker";

static wchar_t *const kTinkerApplicationMutex = L"TinkerApplicationMutex";

//
//	Tinker functions
//

static BOOL CALLBACK ForegroundReaderWindow(const HWND hWnd, const LPARAM lParam)
{
	//DBLog(L"%S 0x%p 0x%p\n", __FUNCSIG__, hWnd, lParam);

	BOOL status = TRUE; // Enumerate windows procedure result status

	wchar_t className[MAX_PATH] {}; GetClassNameW(hWnd, className, MAX_PATH);

	if (_wcsicmp(className, UXReaderMainWindow::WindowClassName()) == 0) // Found Reader window
	{
		status = FALSE; if (IsIconic(hWnd)) ShowWindow(hWnd, SW_RESTORE); SetForegroundWindow(hWnd);
	}

	return status;
}

static bool InitApplicationInstance(const HINSTANCE hInstance, const wchar_t *pCmdLine, const int nCmdShow)
{
	//DBLog(L"%S 0x%p '%s' (%i)\n", __FUNCSIG__, hInstance, pCmdLine, nCmdShow);

	bool status = false; // Initialize application instance result status

	CreateMutexW(nullptr, TRUE, kTinkerApplicationMutex); // Atomic

	switch (GetLastError()) // Process CreateMutex result
	{
		case ERROR_SUCCESS: // Initial Tinker instance
		{
			UXReaderLibrary::Module(hInstance); // Set module

			g_UXReaderMainWindow = std::make_unique<UXReaderMainWindow>();

			status = g_UXReaderMainWindow->Create(pCmdLine, nCmdShow);

			if (status == false) g_UXReaderMainWindow = nullptr;
			break;
		}

		case ERROR_ALREADY_EXISTS: // Subsequent Tinker instance
		{
			Sleep(125); // Hack to allow for initial instance to start up fully

			if (const HWND hWnd = FindWindowExW(nullptr, nullptr, UXReaderMainWindow::WindowClassName(), nullptr))
			{
				if ((pCmdLine != nullptr) && (wcslen(pCmdLine) > 0)) // Send command line
				{
					COPYDATASTRUCT cds; RtlSecureZeroMemory(&cds, sizeof(cds)); cds.dwData = 0x0042;

					cds.lpData = (void *)pCmdLine; cds.cbData = DWORD(sizeof(wchar_t) * (wcslen(pCmdLine) + 1));

					SendMessageW(hWnd, WM_COPYDATA, WPARAM(HWND_MESSAGE), LPARAM(&cds));
				}

				EnumWindows(ForegroundReaderWindow, LPARAM(hWnd));
			}
			else // Could not find initial instance error
			{
				MessageBoxW(nullptr, L"Could not find initial instance.", kApplicationName, (MB_ICONSTOP | MB_OK));
			}
			break;
		}

		default: // Unexpected CreateMutex error
		{
			MessageBoxW(nullptr, L"Unexpected CreateMutex error.", kApplicationName, (MB_ICONSTOP | MB_OK));
			break;
		}
	}

	return status;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, wchar_t *pCmdLine, int nCmdShow)
{
	//DBLog(L"%S 0x%p '%s' (%i)\n", __FUNCSIG__, hInstance, pCmdLine, nCmdShow);

	int status = 0; //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	if (InitApplicationInstance(hInstance, pCmdLine, nCmdShow) == true)
	{
		int bStatus = 0; MSG msg; RtlSecureZeroMemory(&msg, sizeof(msg));

		while (((bStatus = GetMessageW(&msg, nullptr, 0, 0)) != 0) && (bStatus != -1))
		{
			if (g_UXReaderMainWindow->PreTranslateMessage(&msg) == false)
			{
				TranslateMessage(&msg); DispatchMessageW(&msg);
			}
		}

		status = int(msg.wParam); g_UXReaderMainWindow = nullptr;
	}

	return status;
}
