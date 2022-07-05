#include "PerSceneDefaultAmbienceTest.h"

PerSceneDefaultAmbienceTest::PerSceneDefaultAmbienceTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

PerSceneDefaultAmbienceTest::~PerSceneDefaultAmbienceTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneDefaultAmbienceTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene default ambience test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(context);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "per scene default ambience test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "per scene default ambience test failed to initialise read buffer\n";
	}

	initialiseData();

	if (successes() == 4)
	{
		return std::string();
	}

	return "per scene default ambience test failed\n";
}

void PerSceneDefaultAmbienceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneDefaultAmbienceTest::initialiseD3D11()
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

void PerSceneDefaultAmbienceTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(data),
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

void PerSceneDefaultAmbienceTest::initialiseData()
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
		&data,
		subresource.pData,
		sizeof(data)
	);
}

int PerSceneDefaultAmbienceTest::successes()
{
	int output = 0;

	for (int i{ 16 }; i < 20; i++)
	{
		output += data[i] == 1.0f;
	}

	return output;
}
