#include "PerSceneInvalidApplyTest.h"

PerSceneInvalidApplyTest::PerSceneInvalidApplyTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), ambience(), outputData()
{
	initialiseAmbience();
}

PerSceneInvalidApplyTest::~PerSceneInvalidApplyTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneInvalidApplyTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene invalid apply test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(context);

	unit.setAmbience(ambience);
	unit.apply(nullptr);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "per scene invalid apply test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "per scene invalid apply test failed to initialise read buffer\n";
	}

	initialiseOutput();

	if (successes() == 4)
	{
		return std::string();
	}

	return "per scene invalid apply ambience test failed\n";
}

void PerSceneInvalidApplyTest::initialiseAmbience()
{
	for (int i{ 0 }; i < 3; i++)
	{
		ambience[i] = (float)i;
	}
}

void PerSceneInvalidApplyTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneInvalidApplyTest::initialiseD3D11()
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

void PerSceneInvalidApplyTest::initialiseRead()
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

void PerSceneInvalidApplyTest::initialiseOutput()
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

int PerSceneInvalidApplyTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[16 + i] == 1.0f;
	}

	return output;
}
