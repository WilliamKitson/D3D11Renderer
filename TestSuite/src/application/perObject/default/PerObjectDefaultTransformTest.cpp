#include "PerObjectDefaultTransformTest.h"

PerObjectDefaultTransformTest::PerObjectDefaultTransformTest()
	: device{ nullptr }, context{ nullptr }, perObject{ nullptr }, result()
{
}

PerObjectDefaultTransformTest::~PerObjectDefaultTransformTest()
{
	if (perObject)
	{
		perObject->Release();
		perObject = nullptr;
	}

	if (context)
	{
		context->Release();
		context = nullptr;
	}

	if (device)
	{
		device->Release();
		device = nullptr;
	}
}

std::string PerObjectDefaultTransformTest::test()
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

	if (FAILED(result))
	{
		return "per object default transform test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	context->VSGetConstantBuffers(
		0,
		1,
		&perObject
	);

	if (!perObject)
	{
		return "per object default transform test failed to initialise per object\n";
	}

	D3D11_BUFFER_DESC readDescription{
		sizeof(D3D11Renderer::CBufferPerObject),
		D3D11_USAGE_STAGING,
		0,
		D3D11_CPU_ACCESS_READ,
		0,
		0
	};

	/// STAGING BUFFER TO ACCESS CONSTANT BUFFER DATA

	ID3D11Buffer* readBuffer;

	result = device->CreateBuffer(
		&readDescription,
		NULL,
		&readBuffer
	);

	if (!readBuffer)
	{
		return "per object default transform test failed to initialise read buffer\n";
	}

	context->CopyResource(
		readBuffer,
		perObject
	);

	D3D11_MAPPED_SUBRESOURCE subresource;

	result = context->Map(
		readBuffer,
		NULL,
		D3D11_MAP_READ,
		NULL,
		&subresource
	);

	D3D11Renderer::CBufferPerObject data;

	memcpy(
		&data,
		subresource.pData,
		sizeof(data)
	);

	if (readBuffer)
	{
		readBuffer->Release();
		readBuffer = nullptr;
	}

	int successes = 0;

	for (int i{ 0 }; i < 16; i++)
	{
		successes += data.transform[i] == D3D11Renderer::CBufferPerObject().transform[i];
	}

	if (successes == 16)
	{
		return std::string();
	}

	return "per object default transform test failed\n";
}
