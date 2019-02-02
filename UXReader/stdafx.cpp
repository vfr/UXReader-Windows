//
//	stdafx.cpp
//	UXReader v0.1
//
//	Copyright � 2017-2019 Julius Oklamcak. All rights reserved.
//
//	Source file that includes just the standard includes. UXReader.pch will be the
//	pre-compiled header and stdafx.obj will contain the pre-compiled type information.
//

#include "stdafx.hpp"

#if _M_X64
	#if _DEBUG
		#pragma comment(lib, "..\\PDFium\\x64d\\bigint.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fdrm.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\formfiller.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fpdfapi.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fpdfdoc.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fpdftext.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fxcodec.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fxcrt.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fxedit.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fxge.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fx_agg.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fx_freetype.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fx_lcms2.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fx_libopenjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\fx_lpng.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\javascript.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\libjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\minizip.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\pdfium.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\pdfium_base.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\pdfwindow.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\simd.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\simd_asm.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\yasm_utils.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\zlib.lib")
		#pragma comment(lib, "..\\PDFium\\x64d\\zlib_x86_simd.lib")
	#else
		#pragma comment(lib, "..\\PDFium\\x64r\\bigint.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fdrm.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\formfiller.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fpdfapi.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fpdfdoc.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fpdftext.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fxcodec.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fxcrt.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fxedit.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fxge.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fx_agg.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fx_freetype.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fx_lcms2.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fx_libopenjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\fx_lpng.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\javascript.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\libjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\minizip.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\pdfium.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\pdfium_base.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\pdfwindow.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\simd.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\simd_asm.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\yasm_utils.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\zlib.lib")
		#pragma comment(lib, "..\\PDFium\\x64r\\zlib_x86_simd.lib")
	#endif
#else
	#if _DEBUG
		#pragma comment(lib, "..\\PDFium\\x86d\\bigint.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fdrm.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\formfiller.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fpdfapi.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fpdfdoc.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fpdftext.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fxcodec.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fxcrt.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fxedit.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fxge.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fx_agg.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fx_freetype.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fx_lcms2.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fx_libopenjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\fx_lpng.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\javascript.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\libjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\minizip.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\pdfium.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\pdfium_base.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\pdfwindow.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\simd.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\simd_asm.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\yasm_utils.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\zlib.lib")
		#pragma comment(lib, "..\\PDFium\\x86d\\zlib_x86_simd.lib")
	#else
		#pragma comment(lib, "..\\PDFium\\x86r\\bigint.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fdrm.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\formfiller.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fpdfapi.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fpdfdoc.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fpdftext.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fxcodec.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fxcrt.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fxedit.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fxge.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fx_agg.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fx_freetype.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fx_lcms2.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fx_libopenjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\fx_lpng.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\javascript.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\libjpeg.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\minizip.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\pdfium.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\pdfium_base.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\pdfwindow.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\simd.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\simd_asm.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\yasm_utils.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\zlib.lib")
		#pragma comment(lib, "..\\PDFium\\x86r\\zlib_x86_simd.lib")
	#endif
#endif
