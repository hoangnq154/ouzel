// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "AudioDS.h"
#include "SoundDS.h"
#include "core/Engine.h"
#include "core/windows/WindowWin.h"
#include "utils/Log.h"

namespace ouzel
{
    namespace audio
    {
        AudioDS::AudioDS():
            Audio(Driver::DIRECTSOUND)
        {
        }

        AudioDS::~AudioDS()
        {
            resourceDeleteSet.clear();
            resources.clear();

            if (listener3D) listener3D->Release();
            if (buffer) buffer->Release();
            if (directSound) directSound->Release();
        }

        bool AudioDS::init()
        {
            if (FAILED(DirectSoundCreate8(nullptr, &directSound, nullptr)))
            {
                Log(Log::Level::ERR) << "Failed to create DirectSound 8 instance";
                return false;
            }

            WindowWin* windowWin = static_cast<WindowWin*>(sharedEngine->getWindow());

            if (FAILED(directSound->SetCooperativeLevel(windowWin->getNativeWindow(), DSSCL_PRIORITY)))
            {
                Log(Log::Level::ERR) << "Failed to set cooperative level for DirectSound 8";
                return false;
            }

            return Audio::init();
        }

        void AudioDS::setListenerPosition(const Vector3& newPosition)
        {
            Audio::setListenerPosition(newPosition);
        }

        void AudioDS::setListenerRotation(const Quaternion& newRotation)
        {
            Audio::setListenerRotation(newRotation);
        }

        SoundResource* AudioDS::createSound()
        {
            SoundResource* sound = new SoundDS();
            resources.push_back(std::unique_ptr<SoundResource>(sound));
            return sound;
        }
    } // namespace audio
} // namespace ouzel
