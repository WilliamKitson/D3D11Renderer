#include "Resolution.h"

D3D11Renderer::Resolution::Resolution()
	: resolution()
{
	setResolution(0, 0);
}

D3D11Renderer::Resolution::~Resolution()
{
}

int D3D11Renderer::Resolution::getWidth()
{
	return resolution[0];
}

int D3D11Renderer::Resolution::getHeight()
{
	return resolution[1];
}

void D3D11Renderer::Resolution::setResolution(int width, int height)
{
	resolution[0] = validateMinimum(960, width);
	resolution[1] = validateMinimum(540, height);
}

int D3D11Renderer::Resolution::validateMinimum(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
