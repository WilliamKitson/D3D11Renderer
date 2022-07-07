#include "Coordinates1D.h"

D3D11Renderer::Coordinates1D::Coordinates1D()
	: count{ 0 }
{
}

D3D11Renderer::Coordinates1D::~Coordinates1D()
{
}

void D3D11Renderer::Coordinates1D::push(float)
{
	count++;
}

int D3D11Renderer::Coordinates1D::getCount()
{
	return count;
}

float D3D11Renderer::Coordinates1D::getCoordinate()
{
	return 1.0f;
}
