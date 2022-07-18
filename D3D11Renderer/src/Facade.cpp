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

ID3D11DeviceContext* D3D11Renderer::Facade::getContext()
{
    return nullptr;
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
