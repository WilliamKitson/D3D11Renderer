#include "Coordinates3D.h"

D3D11Renderer::Coordinates3D::Coordinates3D()
	: count{ 0 }, index{ 0 }, coordinates{ nullptr }
{
}

D3D11Renderer::Coordinates3D::~Coordinates3D()
{
	cleanup();
}

void D3D11Renderer::Coordinates3D::push(float input[3])
{
	swap(pushed());
	incriment();
	xInitialise(input[0]);
	yInitialise(input[1]);
	zInitialise(input[2]);
}

void D3D11Renderer::Coordinates3D::clear()
{
	count = 0;
}

int D3D11Renderer::Coordinates3D::getCount()
{
	return count / 3;
}

float D3D11Renderer::Coordinates3D::getX()
{
	try
	{
		validate();
	}
	catch (int)
	{
		return 0.0f;
	}

	return coordinates[xIndex()];
}

float D3D11Renderer::Coordinates3D::getY()
{
	try
	{
		validate();
	}
	catch (int)
	{
		return 0.0f;
	}

	return coordinates[yIndex()];
}

float D3D11Renderer::Coordinates3D::getZ()
{
	try
	{
		validate();
	}
	catch (int)
	{
		return 0.0f;
	}

	return coordinates[zIndex()];
}

void D3D11Renderer::Coordinates3D::setIndex(int input)
{
	index = minimum(maximum(input));
}

void D3D11Renderer::Coordinates3D::cleanup()
{
	delete[] coordinates;
	coordinates = nullptr;
}

void D3D11Renderer::Coordinates3D::swap(float* input)
{
	cleanup();
	coordinates = input;
}

float* D3D11Renderer::Coordinates3D::pushed()
{
	float* output = new float[count + 3];

	for (int i{ 0 }; i < count; i++)
	{
		output[i] = coordinates[i];
	}

	return output;
}

void D3D11Renderer::Coordinates3D::incriment()
{
	count += 3;
}

void D3D11Renderer::Coordinates3D::xInitialise(float input)
{
	coordinates[count - 3] = input;
}

void D3D11Renderer::Coordinates3D::yInitialise(float input)
{
	coordinates[count - 2] = input;
}

void D3D11Renderer::Coordinates3D::zInitialise(float input)
{
	coordinates[count - 1] = input;
}

void D3D11Renderer::Coordinates3D::validate()
{
	if (count)
	{
		return;
	}

	throw int();
}

int D3D11Renderer::Coordinates3D::xIndex()
{
	return index * 3;
}

int D3D11Renderer::Coordinates3D::yIndex()
{
	return (index * 3) + 1;
}

int D3D11Renderer::Coordinates3D::zIndex()
{
	return (index * 3) + 2;
}

int D3D11Renderer::Coordinates3D::minimum(int input)
{
	int output = 0;

	if (input < output)
	{
		return output;
	}

	return input;
}

int D3D11Renderer::Coordinates3D::maximum(int input)
{
	if (input < getCount())
	{
		return input;
	}

	return 0;
}
