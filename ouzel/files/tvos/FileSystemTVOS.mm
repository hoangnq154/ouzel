// Copyright (C) 2018 Elviss Strazdins
// This file is part of the Ouzel engine.

#include <Foundation/Foundation.h>
#include "FileSystemTVOS.hpp"
#include "utils/Log.hpp"

namespace ouzel
{
    FileSystemTVOS::FileSystemTVOS()
    {
    }

    std::string FileSystemTVOS::getStorageDirectory(bool user) const
    {
        NSFileManager* fileManager = [NSFileManager defaultManager];

        NSError* error;
        NSURL* documentDirectory = [fileManager URLForDirectory:NSDocumentDirectory inDomain:user ? NSUserDomainMask : NSLocalDomainMask appropriateForURL:nil create:YES error:&error];

        if (!documentDirectory)
        {
            Log(Log::Level::ERR) << "Failed to get document directory";
            return "";
        }

        return [[documentDirectory path] UTF8String];
    }
}
