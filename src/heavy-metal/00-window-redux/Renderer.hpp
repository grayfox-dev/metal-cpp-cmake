#ifndef RENDERER
#define RENDERER
#include "common.hpp"

class Renderer
{
    public:
        Renderer( MTL::Device* pDevice );
        ~Renderer();

        void draw( MTK::View* pView );

    private:
        MTL::Device*       _pDevice;
        MTL::CommandQueue* _pCommandQueue;
};


Renderer::Renderer( MTL::Device* pDevice )
: _pDevice( pDevice->retain() )
{
    _pCommandQueue = _pDevice->newCommandQueue();
}

Renderer::~Renderer()
{
    _pCommandQueue->release();
    _pDevice->release();
}

void Renderer::draw( MTK::View* pView )
{
    NS::AutoreleasePool* pPool      = NS::AutoreleasePool::alloc()->init();
    MTL::CommandBuffer* pCmd        = _pCommandQueue->commandBuffer();
    MTL::RenderPassDescriptor* pRpd = pView->currentRenderPassDescriptor();
    MTL::RenderCommandEncoder* pEnc = pCmd->renderCommandEncoder( pRpd );

    pEnc->endEncoding();
    pCmd->presentDrawable( pView->currentDrawable() );
    pCmd->commit();

    pPool->release();
}

#endif
