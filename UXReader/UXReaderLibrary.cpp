//
//	UXReaderLibrary.cpp
//	UXReader v0.1
//
//	Copyright � 2017-2019 Julius Oklamcak. All rights reserved.
//

#include "stdafx.hpp"
#include "UXReaderLibrary.hpp"
#include "UXReaderMainWindow.hpp"
#include "UXReaderDocumentPane.hpp"
#include "UXReaderDocumentView.hpp"
#include "UXReaderToolbarPane.hpp"
#include "UXReaderToolbarItem.hpp"
#include "UXReaderToolbarText.hpp"
#include "UXReaderToolbarEdit.hpp"
#include "UXReaderStatusPane.hpp"

using namespace UXReader;

//
//	UXReaderLibrary methods
//

UXReader::UXReaderLibrary::UXReaderLibrary(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);

	OleInitialize(nullptr);

	INITCOMMONCONTROLSEX icc; icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_STANDARD_CLASSES; InitCommonControlsEx(&icc);

	Gdiplus::GdiplusStartupInput gdiPlusStartupInput;
	Gdiplus::GdiplusStartup(&m_GdiPlusToken, &gdiPlusStartupInput, nullptr);

	const FPDF_LIBRARY_CONFIG config {2, nullptr, nullptr, 0};
	FPDF_InitLibraryWithConfig(&config);
}

UXReader::UXReaderLibrary::~UXReaderLibrary(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);

	Gdiplus::GdiplusShutdown(m_GdiPlusToken); m_GdiPlusToken = 0;

	FPDF_DestroyLibrary(); UnRegisterWindowClasses(); OleUninitialize();

	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);
}

//
//	Module methods
//

void UXReader::UXReaderLibrary::hModule(const HMODULE hModule)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, hModule);

	if ((hModule != nullptr) && (m_Module == nullptr))
	{
		m_Module = hModule; DoRegisterWindowClasses();
	}
}

void UXReader::UXReaderLibrary::Module(const HMODULE hModule)
{
	//DBLog(L"%S\n", __FUNCSIG__);

	UXReaderLibrary& Instance = UXReaderLibrary::Instance();

	Instance.hModule(hModule);
}

HMODULE UXReader::UXReaderLibrary::hModule(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, m_Module);

	if (m_Module == nullptr) // Default
	{
		m_Module = GetModuleHandleW(nullptr);

		DoRegisterWindowClasses();
	}

	//DBLog(L"%S 0x%p\n", __FUNCSIG__, m_Module);

	return m_Module;
}

HMODULE UXReader::UXReaderLibrary::Module(void)
{
	//DBLog(L"%S\n", __FUNCSIG__);

	UXReaderLibrary& Instance = UXReaderLibrary::Instance();

	return Instance.hModule();
}

//
//	Window methods
//

void UXReader::UXReaderLibrary::DoRegisterWindowClasses(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, m_Module);

	if (m_Module != nullptr)
	{
		UXReaderMainWindow::DoRegisterWindowClass(m_Module);

		UXReaderDocumentPane::DoRegisterWindowClass(m_Module);
		UXReaderDocumentView::DoRegisterWindowClass(m_Module);

		UXReaderToolbarPane::DoRegisterWindowClass(m_Module);
		UXReaderToolbarItem::DoRegisterWindowClass(m_Module);
		UXReaderToolbarText::DoRegisterWindowClass(m_Module);
		UXReaderToolbarEdit::DoRegisterWindowClass(m_Module);

		UXReaderStatusPane::DoRegisterWindowClass(m_Module);
	}
}

void UXReader::UXReaderLibrary::UnRegisterWindowClasses(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, m_Module);

	if (m_Module != nullptr)
	{
		UXReaderMainWindow::UnRegisterWindowClass(m_Module);

		UXReaderDocumentPane::UnRegisterWindowClass(m_Module);
		UXReaderDocumentView::UnRegisterWindowClass(m_Module);

		UXReaderToolbarPane::UnRegisterWindowClass(m_Module);
		UXReaderToolbarItem::UnRegisterWindowClass(m_Module);
		UXReaderToolbarText::UnRegisterWindowClass(m_Module);
		UXReaderToolbarEdit::UnRegisterWindowClass(m_Module);

		UXReaderStatusPane::UnRegisterWindowClass(m_Module);
	}
}
