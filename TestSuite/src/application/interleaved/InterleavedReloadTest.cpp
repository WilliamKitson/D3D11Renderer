#include "InterleavedReloadTest.h"

InterleavedReloadTest::InterleavedReloadTest()
	: device{ nullptr }, context{ nullptr }, vBuffer{ nullptr }, readBuffer{ nullptr }, result(), outputData()
{
}

InterleavedReloadTest::~InterleavedReloadTest()
{
	cleanup(readBuffer);
	cleanup(vBuffer);
	cleanup(context);
	cleanup(device);
}

std::string InterleavedReloadTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved reload test failed to initialise D3D11\n";
	}

	D3D11Renderer::Interleaved unit;

	unit.initialise(device);
	unit.render(context);

	for (int i{ 0 }; i < 4; i++)
	{
		float vertex[] = {
			(float)i + 0,
			(float)i + 1,
			(float)i + 2,
			(float)i + 3,
			(float)i + 4,
			(float)i + 5,
			(float)i + 6,
			(float)i + 7
		};

		unit.push(vertex);
	}

	unit.initialise(device);
	unit.render(context);

	initialiseVBuffer();

	if (!vBuffer)
	{
		return "interleaved reload test failed to initialise vBuffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "interleaved reload test failed to initialise read buffer\n";
	}

	initialiseOutput();

	if (success())
	{
		return std::string();
	}

	return "interleaved reload test failed\n";
}

void InterleavedReloadTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedReloadTest::initialiseD3D11()
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

void InterleavedReloadTest::initialiseVBuffer()
{
	context->IAGetVertexBuffers(
		0,
		1,
		&vBuffer,
		nullptr,
		nullptr
	);
}

void InterleavedReloadTest::initialiseRead()
{
	D3D11_BUFFER_DESC vBufferDesc;

	vBuffer->GetDesc(&vBufferDesc);

	D3D11_BUFFER_DESC readDescription{
		vBufferDesc.ByteWidth,
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

void InterleavedReloadTest::initialiseOutput()
{
	context->CopyResource(
		readBuffer,
		vBuffer
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

bool InterleavedReloadTest::success()
{
	if (successes() == 32)
	{
		return true;
	}

	return false;
}

int InterleavedReloadTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[(i * 8) + 0] == (float)i + 0;
		output += outputData[(i * 8) + 1] == (float)i + 1;
		output += outputData[(i * 8) + 2] == (float)i + 2;
		output += outputData[(i * 8) + 3] == (float)i + 3;
		output += outputData[(i * 8) + 4] == (float)i + 4;
		output += outputData[(i * 8) + 5] == (float)i + 5;
		output += outputData[(i * 8) + 6] == (float)i + 6;
		output += outputData[(i * 8) + 7] == (float)i + 7;
	}

	return output;
}
