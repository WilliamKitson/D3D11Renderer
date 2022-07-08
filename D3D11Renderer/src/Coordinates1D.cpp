#include "Coordinates1D.h"

D3D11Renderer::Coordinates1D::Coordinates1D()
	: count{ 0 }, index{ 0 }, coordinates{ nullptr }
{
}

D3D11Renderer::Coordinates1D::~Coordinates1D()
{
	cleanup();
}

void D3D11Renderer::Coordinates1D::push(float input)
{
	increment();
	swap(pushed());
	initialise(input);
}

int D3D11Renderer::Coordinates1D::getCount()
{
	return count;
}

float D3D11Renderer::Coordinates1D::getCoordinate()
{
	return coordinates[index];
}

void D3D11Renderer::Coordinates1D::setIndex(int input)
{
	if (input >= count)
	{
		input = 0;
	}

	index = minimum(input);
}

void D3D11Renderer::Coordinates1D::cleanup()
{
	if (coordinates)
	{
		delete[] coordinates;
		coordinates = nullptr;
	}
}

void D3D11Renderer::Coordinates1D::increment()
{
	count++;
}

void D3D11Renderer::Coordinates1D::swap(float* input)
{
	cleanup();
	coordinates = input;
}

float* D3D11Renderer::Coordinates1D::pushed()
{
	float* output = new float[count];

	for (int i{ 0 }; i < count - 1; i++)
	{
		output[i] = coordinates[i];
	}

	return output;
}

void D3D11Renderer::Coordinates1D::initialise(float input)
{
	coordinates[count - 1] = input;
}

int D3D11Renderer::Coordinates1D::minimum(int input)
{
	int output = 0;

	if (input < output)
	{
		return output;
	}

	return input;
}
