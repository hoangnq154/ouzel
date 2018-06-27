// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#include "graphics/RenderResource.hpp"

namespace ouzel
{
    namespace graphics
    {
        class TextureResource;

        class RenderTargetResource: public RenderResource
        {
        public:
            TextureResource* getColorTexture() const { return colorTexture; }
            TextureResource* getDepthTexture() const { return depthTexture; }

        private:
            TextureResource* colorTexture = nullptr;
            TextureResource* depthTexture = nullptr;
        };
    } // namespace graphics
} // namespace ouzel
