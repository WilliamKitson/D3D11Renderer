#include "ImplimentationObjectColourTest.h"

ImplimentationObjectColourTest::ImplimentationObjectColourTest()
	: unit{ new D3D11Renderer::Implimentation() }, colour(initialiseColour()), objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationObjectColourTest::~ImplimentationObjectColourTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	delete unit;
}

std::string ImplimentationObjectColourTest::test()
{
	unit->initialise(HWND(), "");
	unit->objectColour(colour);

	unit->getContext()->VSGetConstantBuffers(
		1,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return "implimentation object colour test failed to initialise object buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation object colour test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation object colour test failed\n";
}

D3D11Renderer::RGBA ImplimentationObjectColourTest::initialiseColour()
{
	return D3D11Renderer::RGBA{
		0.0f,
		1.0f,
		2.0f,
		3.0f
	};
}

void ImplimentationObjectColourTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationObjectColourTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(data),
		D3D11_USAGE_STAGING,
		0,
		D3D11_CPU_ACCESS_READ,
		0,
		0
	};

	result = unit->getDevice()->CreateBuffer(
		&readDescription,
		NULL,
		&readBuffer
	);
}

void ImplimentationObjectColourTest::initialiseData()
{
	unit->getContext()->CopyResource(
		readBuffer,
		objectBuffer
	);

	D3D11_MAPPED_SUBRESOURCE subresource;

	result = unit->getContext()->Map(
		readBuffer,
		NULL,
		D3D11_MAP_READ,
		NULL,
		&subresource
	);

	memcpy(
		&data,
		subresource.pData,
		sizeof(data)
	);
}

bool ImplimentationObjectColourTest::success()
{
	if (data[16] != colour.red)
	{
		return false;
	}

	if (data[17] != colour.green)
	{
		return false;
	}

	if (data[18] != colour.blue)
	{
		return false;
	}

	if (data[19] != colour.alpha)
	{
		return false;
	}

	return true;
}
