#include "PerObjectUpdateColourTest.h"

PerObjectUpdateColourTest::PerObjectUpdateColourTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), update(), data()
{
	initialiseUpdate();
}

PerObjectUpdateColourTest::~PerObjectUpdateColourTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectUpdateColourTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per object update colour test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	unit.setColour(update.colour);
	unit.initialise(device);
	unit.bind(context);

	initialiseData();

	if (FAILED(result))
	{
		return "per object update colour test failed to initialise data\n";
	}

	if (success())
	{
		return std::string();
	}

	return "per object update colour test failed\n";
}

void PerObjectUpdateColourTest::initialiseUpdate()
{
	for (int i{ 0 }; i < 4; i++)
	{
		update.colour[i] = (float)i;
	}
}

void PerObjectUpdateColourTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectUpdateColourTest::initialiseD3D11()
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

void PerObjectUpdateColourTest::initialiseData()
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
		&data,
		subresource.pData,
		sizeof(data)
	);
}

void PerObjectUpdateColourTest::initialiseObject()
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

void PerObjectUpdateColourTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(D3D11Renderer::CBufferPerObject),
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

bool PerObjectUpdateColourTest::success()
{
	if (successes() == 4)
	{
		return true;
	}

	return false;
}

int PerObjectUpdateColourTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += data.colour[i] == update.colour[i];
	}

	return output;
}
