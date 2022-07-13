#include "DirectionalDefaultDirectionTest.h"

DirectionalDefaultDirectionTest::DirectionalDefaultDirectionTest()
	: device{ nullptr }, context{ nullptr }, cBuffer{ nullptr }, readBuffer{ nullptr }, result(), outputData()
{
}

DirectionalDefaultDirectionTest::~DirectionalDefaultDirectionTest()
{
	cleanup(readBuffer);
	cleanup(cBuffer);
	cleanup(context);
	cleanup(device);
}

std::string DirectionalDefaultDirectionTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "directional default direction test failed to initialise D3D11\n";
	}

	D3D11Renderer::Directional unit;

	unit.initialise(device);
	unit.bind(context);

	initialiseOutput();

	if (FAILED(result))
	{
		return "directional default direction test failed to initialise data\n";
	}

	if (success() == 4)
	{
		return std::string();
	}

	return "directional default direction test failed\n";
}

void DirectionalDefaultDirectionTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void DirectionalDefaultDirectionTest::initialiseD3D11()
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

void DirectionalDefaultDirectionTest::initialiseOutput()
{
	initialiseCBuffer();

	if (FAILED(result))
	{
		return;
	}

	initialiseRead();

	if (FAILED(result))
	{
		return;
	}

	context->CopyResource(
		readBuffer,
		cBuffer
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

void DirectionalDefaultDirectionTest::initialiseCBuffer()
{
	context->VSGetConstantBuffers(
		2,
		1,
		&cBuffer
	);

	if (!cBuffer)
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void DirectionalDefaultDirectionTest::initialiseRead()
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

int DirectionalDefaultDirectionTest::success()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[i] == 0.0f;
	}

	return output;
}
