//
//	targetver.h
//	UXReader v0.1
//
//	Copyright © 2017-2019 Julius Oklamcak. All rights reserved.
//
//	Including SDKDDKVer.h defines the highest available Windows platform.
//	If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
//	then set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h
//

#pragma once

#include <WinSDKVer.h>

// Windows 7 and up
#define WINVER 0x0601
#define _WIN32_WINNT 0x0601

#include <SDKDDKVer.h>
