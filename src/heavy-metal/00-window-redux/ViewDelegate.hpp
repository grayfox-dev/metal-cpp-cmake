#ifndef VIEWDELEGATE
#define VIEWDELEGATE
#include "Renderer.hpp"

class MTKViewDelegate : public MTK::ViewDelegate
{
    public:
        MTKViewDelegate( MTL::Device* pDevice );
        virtual ~MTKViewDelegate() override;
        virtual void drawInMTKView( MTK::View* pView ) override;

    private:
        Renderer* _pRenderer;
};

MTKViewDelegate::MTKViewDelegate( MTL::Device* pDevice )
: MTK::ViewDelegate()
, _pRenderer( new Renderer( pDevice ) )
{
}

MTKViewDelegate::~MTKViewDelegate()
{
    delete _pRenderer;
}

void MTKViewDelegate::drawInMTKView( MTK::View* pView )
{
    _pRenderer->draw( pView );
}

#endif
