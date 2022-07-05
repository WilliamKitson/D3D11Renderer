#include "PerObjectReloadColourTest.h"

PerObjectReloadColourTest::PerObjectReloadColourTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), inputData(), outputData()
{
	initialiseInput();
}

PerObjectReloadColourTest::~PerObjectReloadColourTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectReloadColourTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per object reload colour test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	float colour[4];

	for (int i{ 0 }; i < 4; i++)
	{
		colour[i] = inputData[16 + i];
	}

	unit.setColour(colour);
	unit.initialise(device);
	unit.bind(context);

	initialiseOutput();

	if (FAILED(result))
	{
		return "per object reload colour test failed to initialise data\n";
	}

	if (success())
	{
		return std::string();
	}

	return "per object reload colour test failed\n";
}

void PerObjectReloadColourTest::initialiseInput()
{
	for (int i{ 16 }; i < 20; i++)
	{
		inputData[i] = (float)i;
	}
}

void PerObjectReloadColourTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectReloadColourTest::initialiseD3D11()
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

void PerObjectReloadColourTest::initialiseOutput()
{
	initialiseObject();
	initialiseRead();

	if (FAILED(result))
	{
		return;
	}

	context->CopyResource(
		readBuffer,
		objectBuffer
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

void PerObjectReloadColourTest::initialiseObject()
{
	context->VSGetConstantBuffers(
		0,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void PerObjectReloadColourTest::initialiseRead()
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

bool PerObjectReloadColourTest::success()
{
	if (successes() == 4)
	{
		return true;
	}

	return false;
}

int PerObjectReloadColourTest::successes()
{
	int output = 0;

	for (int i{ 16 }; i < 20; i++)
	{
		output += outputData[i] == inputData[i];
	}

	return output;
}
