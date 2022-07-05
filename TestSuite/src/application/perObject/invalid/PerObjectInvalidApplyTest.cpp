#include "PerObjectInvalidApplyTest.h"

PerObjectInvalidApplyTest::PerObjectInvalidApplyTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), inputData(), outputData()
{
	initialiseInput();
}

PerObjectInvalidApplyTest::~PerObjectInvalidApplyTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectInvalidApplyTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per object invalid apply test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	float transform[16];

	for (int i{ 0 }; i < 16; i++)
	{
		transform[i] = inputData[i];
	}

	unit.setTransform(transform);
	unit.apply(nullptr);

	initialiseOutput();

	if (FAILED(result))
	{
		return "per object invalid apply test failed to initialise data\n";
	}

	if (success())
	{
		return std::string();
	}

	return "per object update transform test failed\n";
}

void PerObjectInvalidApplyTest::initialiseInput()
{
	for (int i{ 0 }; i < 16; i++)
	{
		inputData[i] = (float)i;
	}
}

void PerObjectInvalidApplyTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectInvalidApplyTest::initialiseD3D11()
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

void PerObjectInvalidApplyTest::initialiseOutput()
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

void PerObjectInvalidApplyTest::initialiseObject()
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

void PerObjectInvalidApplyTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(inputData),
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

bool PerObjectInvalidApplyTest::success()
{
	if (successes() == 16)
	{
		return true;
	}

	return false;
}

int PerObjectInvalidApplyTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 16; i++)
	{
		output += outputData[i] == 1.0f;
	}

	return output;
}
