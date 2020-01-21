// Copyright (C) Microsoft Corporation. All rights reserved.
// stdafx.h : The file for declaring precompiled headers.

#ifndef STDAFX_H
#define STDAFX_H

#pragma once

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <functional>
#include <fstream>
#include <future>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>

#include <playfab/PlayFabJsonHeaders.h>
#include <playfab/PlayFabPlatformMacros.h>
#include <playfab/PlayFabPlatformTypes.h>
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>

#define UNREFERENCED_PARAMETER(P) (P)

#ifdef PLAYFAB_PLATFORM_LINUX
#include <stdio.h>
#endif // PLAYFAB_PLATFORM_LINUX

#ifdef PLAYFAB_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#endif // PLAYFAB_PLATFORM_WINDOWS

#endif // STDAFX_H
