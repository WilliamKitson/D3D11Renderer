#include "PerSceneReloadAmbienceTest.h"

PerSceneReloadAmbienceTest::PerSceneReloadAmbienceTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), ambience(), outputData()
{
	initialiseAmbience();
}

PerSceneReloadAmbienceTest::~PerSceneReloadAmbienceTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneReloadAmbienceTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene reload ambience test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(context);

	unit.setAmbience(ambience);
	unit.initialise(device);
	unit.bind(context);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "per scene reload ambience test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "per scene reload ambience test failed to initialise read buffer\n";
	}

	initialiseOutput();

	if (successes() == 4)
	{
		return std::string();
	}

	return "per scene reload ambience test failed\n";
}

void PerSceneReloadAmbienceTest::initialiseAmbience()
{
	for (int i{ 0 }; i < 4; i++)
	{
		ambience[i] = (float)i;
	}
}

void PerSceneReloadAmbienceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneReloadAmbienceTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	result = D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		levels,
		1,
		D3D11_SDK_VERSION,
		&device,
		&supported,
		&context
	);
}

void PerSceneReloadAmbienceTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(outputData),
		D3D11_USAGE_STAGING,
		0,
		D3D11_CPU_ACCESS_READ,
		0,
		0
	};

	result = device->CreateBuffer(
		&readDescription,
		NULL,
		&readBuffer
	);
}

void PerSceneReloadAmbienceTest::initialiseOutput()
{
	context->CopyResource(
		readBuffer,
		sceneBuffer
	);

	D3D11_MAPPED_SUBRESOURCE subresource;

	result = context->Map(
		readBuffer,
		NULL,
		D3D11_MAP_READ,
		NULL,
		&subresource
	);

	memcpy(
		&outputData,
		subresource.pData,
		sizeof(outputData)
	);
}

int PerSceneReloadAmbienceTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[16 + i] == ambience[i];
	}

	return output;
}
