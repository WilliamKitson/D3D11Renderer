#include "ImplimentationSceneAmbienceTest.h"

ImplimentationSceneAmbienceTest::ImplimentationSceneAmbienceTest()
	: unit{ new D3D11Renderer::Implimentation() }, ambience(initialiseAmbience()), sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationSceneAmbienceTest::~ImplimentationSceneAmbienceTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	delete unit;
}

std::string ImplimentationSceneAmbienceTest::test()
{
	unit->initialise(HWND(), "");
	unit->sceneAmbience(ambience);

	unit->getContext()->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "implimentation scene ambience test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation scene ambience test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation scene ambience test failed\n";
}

D3D11Renderer::RGBA ImplimentationSceneAmbienceTest::initialiseAmbience()
{
	return D3D11Renderer::RGBA{
		0.0f,
		1.0f,
		2.0f,
		3.0f
	};
}

void ImplimentationSceneAmbienceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationSceneAmbienceTest::initialiseRead()
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

void ImplimentationSceneAmbienceTest::initialiseData()
{
	unit->getContext()->CopyResource(
		readBuffer,
		sceneBuffer
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

bool ImplimentationSceneAmbienceTest::success()
{
	if (data[16] != ambience.red)
	{
		return false;
	}

	if (data[17] != ambience.green)
	{
		return false;
	}

	if (data[18] != ambience.blue)
	{
		return false;
	}

	if (data[19] != ambience.alpha)
	{
		return false;
	}

	return true;
}
