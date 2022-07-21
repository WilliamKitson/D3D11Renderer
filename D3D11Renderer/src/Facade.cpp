#include "Facade.h"

D3D11Renderer::Facade::Facade()
{
}

D3D11Renderer::Facade::~Facade()
{
}

void D3D11Renderer::Facade::initialise(HWND, std::string)
{
}

void D3D11Renderer::Facade::update()
{
}

void D3D11Renderer::Facade::overlap()
{
}

void D3D11Renderer::Facade::outputResolution(Output, HWND)
{
}

void D3D11Renderer::Facade::syncFull()
{
}

void D3D11Renderer::Facade::syncHalf()
{
}

void D3D11Renderer::Facade::syncQuater()
{
}

void D3D11Renderer::Facade::syncNone()
{
}

void D3D11Renderer::Facade::drawWireframe()
{
}

void D3D11Renderer::Facade::drawSolid()
{
}

void D3D11Renderer::Facade::cullNone()
{
}

void D3D11Renderer::Facade::cullFront()
{
}

void D3D11Renderer::Facade::cullBack()
{
}

void D3D11Renderer::Facade::sceneCamera(Camera)
{
}

void D3D11Renderer::Facade::sceneAmbience(RGBA)
{
}

void D3D11Renderer::Facade::objectTransform(Transform)
{
}

void D3D11Renderer::Facade::objectColour(RGBA)
{
}

ID3D11Device* D3D11Renderer::Facade::getDevice()
{
    return nullptr;
}

ID3D11DeviceContext* D3D11Renderer::Facade::getContext()
{
    return nullptr;
}
