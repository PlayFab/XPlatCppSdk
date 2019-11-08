// Copyright (C) Microsoft Corporation. All rights reserved.
//
// This header file is used to define PLAYFAB_PLATFORM macros.
// Any platform supported by the XPlatCppSdk must be added and redefined here.
//
// Format used : PLAYFAB_PLATFORM_<PlatformName>
//
// In the PlayFab codebase, this newly defined macro will be used.

#pragma once

#ifdef _DURANGO
#define PLAYFAB_PLATFORM_XBOX
#endif // _DURANGO

#if defined(__linux__) && !defined(__ANDROID__)
#define PLAYFAB_PLATFORM_LINUX
#endif // __linux__ && !__ANDROID__

#ifdef __APPLE__
#define PLAYFAB_PLATFORM_IOS
#endif // __APPLE__

#ifdef __ANDROID__
#define PLAYFAB_PLATFORM_ANDROID
#endif // __ANDROID__

// Durango is also defined as _WIN32.
// Hence to specify only Windows, we have check for ! _DURANGO.
#if defined(_WIN32) && !defined(_DURANGO)
#define PLAYFAB_PLATFORM_WINDOWS
#endif //_WIN32

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
typedef signed __int64 Int64;
typedef signed __int32 Int32;
typedef signed __int16 Int16;

typedef unsigned __int64 Uint64;
typedef unsigned __int32 Uint32;
typedef unsigned __int16 Uint16;
#elif defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_PLAYSTATION)
typedef int64_t Int64;
typedef int32_t Int32;
typedef int16_t Int16;

typedef uint64_t Uint64;
typedef uint32_t Uint32;
typedef uint16_t Uint16;
#endif
