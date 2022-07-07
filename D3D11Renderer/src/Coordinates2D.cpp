#include "Coordinates2D.h"

D3D11Renderer::Coordinates2D::Coordinates2D()
	: count{ 0 }, index{ 0 }, coordinates{ nullptr }
{
}

D3D11Renderer::Coordinates2D::~Coordinates2D()
{
	cleanup();
}

void D3D11Renderer::Coordinates2D::push(float input[2])
{
	swap(pushed());
	incriment();
	xInitialise(input[0]);
	yInitialise(input[1]);
}

void D3D11Renderer::Coordinates2D::clear()
{
	count = 0;
}

int D3D11Renderer::Coordinates2D::getCount()
{
	return count / 2;
}

float D3D11Renderer::Coordinates2D::getX()
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

float D3D11Renderer::Coordinates2D::getY()
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

void D3D11Renderer::Coordinates2D::setIndex(int input)
{
	index = minimum(maximum(input));
}

void D3D11Renderer::Coordinates2D::cleanup()
{
	delete[] coordinates;
	coordinates = nullptr;
}

void D3D11Renderer::Coordinates2D::swap(float* input)
{
	cleanup();
	coordinates = input;
}

float* D3D11Renderer::Coordinates2D::pushed()
{
	float* output = new float[count + 2];

	for (int i{ 0 }; i < count; i++)
	{
		output[i] = coordinates[i];
	}

	return output;
}

void D3D11Renderer::Coordinates2D::incriment()
{
	count += 2;
}

void D3D11Renderer::Coordinates2D::xInitialise(float input)
{
	coordinates[count - 2] = input;
}

void D3D11Renderer::Coordinates2D::yInitialise(float input)
{
	coordinates[count - 1] = input;
}

void D3D11Renderer::Coordinates2D::validate()
{
	if (count)
	{
		return;
	}

	throw int();
}

int D3D11Renderer::Coordinates2D::xIndex()
{
	return index * 2;
}

int D3D11Renderer::Coordinates2D::yIndex()
{
	return (index * 2) + 1;
}

int D3D11Renderer::Coordinates2D::minimum(int input)
{
	int output = 0;

	if (input < output)
	{
		return output;
	}

	return input;
}

int D3D11Renderer::Coordinates2D::maximum(int input)
{
	if (input < getCount())
	{
		return input;
	}

	return 0;
}
