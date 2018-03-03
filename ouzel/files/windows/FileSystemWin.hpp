// Copyright (C) 2018 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <windows.h>
#include <Shlobj.h>
#include <Shlwapi.h>
#include "files/FileSystem.hpp"

namespace ouzel
{
    class Engine;

    class FileSystemWin: public FileSystem
    {
        friend Engine;
    public:
        virtual std::string getStorageDirectory(bool user = true) const override;

    protected:
        FileSystemWin();
    };
}
