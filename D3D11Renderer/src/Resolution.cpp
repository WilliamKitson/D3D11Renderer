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
	resolution[0] = width(input[0]);
	resolution[1] = height(input[1]);
}

int D3D11Renderer::Resolution::width(int input)
{
	int output = 960;

	if (input < output)
	{
		return output;
	}

	return input;
}

int D3D11Renderer::Resolution::height(int input)
{
	int output = 540;

	if (input < output)
	{
		return output;
	}

	return input;
}

int D3D11Renderer::Resolution::validate(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
