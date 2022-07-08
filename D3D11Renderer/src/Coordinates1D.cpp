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

	float* pushed = new float[count];

	for (int i{ 0 }; i < count - 1; i++)
	{
		pushed[i] = coordinates[i];
	}

	pushed[count - 1] = input;

	cleanup();
	coordinates = pushed;
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
	if (input < 0)
	{
		input = 0;
	}

	if (input >= count)
	{
		input = 0;
	}

	index = input;
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
