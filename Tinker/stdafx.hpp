//
//	stdafx.hpp
//	Tinker v0.1
//
//	Copyright © 2017-2019 Julius Oklamcak. All rights reserved.
//
//	Master include file for standard system include files, or project specific
//	include files that are used frequently, but are changed infrequently.
//

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

// Windows headers
#include <Windows.h>
#include <WindowsX.h>
#pragma warning(push)
#pragma warning(disable: 4458)
#include <GdiPlus.h>
#pragma warning(pop)
#include <ShlwApi.h>
#include <ShlObj.h>

// C++ STL headers
#include <string>
#include <memory>
#include <functional>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <mutex>
#include <thread>
//#include <deque>
//#include <list>
//#include <algorithm>
//#include <iterator>

// Visual C++ pragmas
#pragma warning(disable : 4100)
#pragma warning(disable : 4706)

// Application specific
#include "Resource.h"
#include "..\\PDFium\\fpdfview.h"
#include "..\\PDFium\\fpdf_doc.h"
#include "..\\PDFium\\fpdf_text.h"
#include "..\\PDFium\\fpdf_edit.h"
#include "..\\UXReader\\UXReaderLibrary.hpp"
