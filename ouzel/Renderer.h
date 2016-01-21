// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include "Types.h"
#include "Noncopyable.h"
#include "Rectangle.h"
#include "Matrix4.h"
#include "Size2.h"
#include "Color.h"
#include "Vertex.h"
#include "Shader.h"

namespace ouzel
{
    const std::string SHADER_TEXTURE = "shaderTexture";
    const std::string SHADER_COLOR = "shaderColor";
    
    class Engine;
    class Node;
    class Sprite;
    class MeshBuffer;

    class Renderer: public Noncopyable
    {
        friend Engine;
    public:
        static const uint32_t TEXTURE_LAYERS = 2;
    
        enum class Driver
        {
            NONE = 0,
            OPENGL,
            DIRECT3D11
        };

        virtual ~Renderer();
        
        Driver getDriver() const { return _driver; }
        
        virtual void setClearColor(Color color) { _clearColor = color; }
        virtual Color getClearColor() const { return _clearColor; }
        
        virtual void begin();
        virtual void clear();
        virtual void flush();
        
        virtual const Size2& getSize() const { return _size; }
        virtual void resize(const Size2& size);
        
        virtual bool getResizable() const { return _resizable; }
        
        virtual const std::string& getTitle() const { return _title; }
        virtual void setTitle(const std::string& title);
        
        virtual TexturePtr createTexture(Size2 const& size, bool dynamic);
        virtual TexturePtr loadTextureFromFile(const std::string& filename, bool dynamic = false);
        virtual TexturePtr loadTextureFromData(const void* data, const Size2& size, bool dynamic = false);
        virtual bool activateTexture(TexturePtr const& texture, uint32_t layer);
        virtual TexturePtr getActiveTexture(uint32_t layer) const { return _activeTextures[layer]; }
        virtual RenderTargetPtr createRenderTarget(Size2 const& size, bool depthBuffer);
        virtual void activateRenderTarget(RenderTargetPtr renderTarget);
        
        virtual ShaderPtr loadShaderFromFiles(const std::string& fragmentShader, const std::string& vertexShader, uint32_t vertexAttributes);
        virtual ShaderPtr loadShaderFromBuffers(const uint8_t* fragmentShader, uint32_t fragmentShaderSize, const uint8_t* vertexShader, uint32_t vertexShaderSize, uint32_t vertexAttributes);
        virtual bool activateShader(ShaderPtr const& shader);
        virtual ShaderPtr getActiveShader() const { return _activeShader; }
        
        virtual MeshBufferPtr createMeshBuffer(const void* indices, uint32_t indexSize, uint32_t indexCount, bool dynamicIndexBuffer, const void* vertices, uint32_t vertexSize, uint32_t vertexCount, bool dynamicVertexBuffer, uint32_t vertexAttributes);
        virtual bool drawMeshBuffer(MeshBufferPtr const& meshBuffer);
        
        virtual bool drawLine(const Vector2& start, const Vector2& finish, const Color& color, const Matrix4& transform = Matrix4());
        virtual bool drawRectangle(const Rectangle& rectangle, const Color& color, const Matrix4& transform = Matrix4());
        virtual bool drawQuad(const Rectangle& rectangle, const Color& color, const Matrix4& transform = Matrix4());
        
        Vector2 viewToScreenLocation(const Vector2& position);
        Vector2 screenToViewLocation(const Vector2& position);
        
        virtual bool saveScreenshot(std::string const& filename);
        
    protected:
        Renderer();
        virtual bool init(const Size2& size, bool resizable, bool fullscreen, Driver driver = Driver::NONE);
        
        Driver _driver;
        
        Color _clearColor;
        
        TexturePtr _activeTextures[TEXTURE_LAYERS];
        ShaderPtr _activeShader;
        RenderTargetPtr _activeRenderTarget;
        
        Size2 _size;
        bool _resizable = false;
        bool _fullscreen = false;
        
        std::string _title = "";
    };
}
