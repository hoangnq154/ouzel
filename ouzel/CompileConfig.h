// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
    #define OUZEL_PLATFORM_WINDOWS 1
    #define SUPPORTS_DIRECT3D11 1
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_IOS
        #define OUZEL_PLATFORM_IOS 1
        #define OUZEL_SUPPORTS_OPENGLES 1
    #elif TARGET_OS_TV
        #define OUZEL_PLATFORM_TVOS 1
        #define OUZEL_SUPPORTS_OPENGLES 1
    #else
        #define OUZEL_PLATFORM_OSX 1
        #define OUZEL_SUPPORTS_OPENGL 1
    #endif
#elif defined(__ANDROID__)
    #define OUZEL_PLATFORM_ANDROID 1
    #define OUZEL_SUPPORTS_OPENGLES 1
#endif
