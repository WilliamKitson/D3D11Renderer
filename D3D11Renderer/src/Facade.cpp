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

ID3D11DeviceContext* D3D11Renderer::Facade::getContext()
{
    return nullptr;
}

void D3D11Renderer::Facade::outputResolution(Output, HWND)
{
}
