// Copyright 2015-2020 Elviss Strazdins. All rights reserved.

#ifndef OUZEL_GRAPHICS_RENDERER_CAMERA_HPP
#define OUZEL_GRAPHICS_RENDERER_CAMERA_HPP

#include "Renderer.hpp"

namespace ouzel::graphics::renderer
{
    class Camera final
    {
    public:
        enum class ProjectionMode
        {
            custom,
            orthographic,
            perspective
        };

        enum class ScaleMode
        {
            noScale,
            exactFit,
            noBorder,
            showAll
        };

        Camera(Renderer& initRenderer):
            renderer{initRenderer},
            resource{initRenderer}
        {
        }

    private:
        Renderer& renderer;
        Renderer::Resource resource;
    };
}

#endif // OUZEL_GRAPHICS_RENDERER_CAMERA_HPP
