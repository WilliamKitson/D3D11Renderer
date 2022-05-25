#include "Resolution.h"

D3D11Renderer::Resolution::Resolution()
	: resolution()
{
	int initial[2]{
		0,
		0
	};

	setResolution(initial);
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

void D3D11Renderer::Resolution::setResolution(int input[2])
{
	resolution[0] = validate(960, input[0]);
	resolution[1] = validate(540, input[1]);
}

int D3D11Renderer::Resolution::validate(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
