#include "GeometryReloadTexcoordsTest.h"

GeometryReloadTexcoordsTest::GeometryReloadTexcoordsTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), readBuffer{ nullptr }, result(), outputData()
{
}

GeometryReloadTexcoordsTest::~GeometryReloadTexcoordsTest()
{
	cleanup(readBuffer);
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryReloadTexcoordsTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry reload texcoords test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	unit.initialise(device);
	unit.bind(context);

	for (int i{ 0 }; i < 4; i++)
	{
		float texcoord[] = {
			 (float)i,
			 (float)i + 1
		};

		unit.pushTexcoord(texcoord);
	}

	unit.initialise(device);
	unit.bind(context);

	initialiseVBuffer();

	if (!vBuffer[1])
	{
		return "geometry reload texcoords test failed to initialise vBuffer 1\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "geometry reload texcoords test failed to initialise read buffer\n";
	}

	initialiseOutput();

	if (success())
	{
		return std::string();
	}

	return "geometry reload texcoords test failed\n";
}

void GeometryReloadTexcoordsTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryReloadTexcoordsTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryReloadTexcoordsTest::initialiseD3D11()
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

void GeometryReloadTexcoordsTest::initialiseVBuffer()
{
	context->IAGetVertexBuffers(
		0,
		3,
		vBuffer,
		nullptr,
		nullptr
	);
}

void GeometryReloadTexcoordsTest::initialiseRead()
{
	D3D11_BUFFER_DESC vBufferDesc;

	vBuffer[1]->GetDesc(&vBufferDesc);

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

void GeometryReloadTexcoordsTest::initialiseOutput()
{
	context->CopyResource(
		readBuffer,
		vBuffer[1]
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

bool GeometryReloadTexcoordsTest::success()
{
	if (successes() == 8)
	{
		return true;
	}

	return false;
}

int GeometryReloadTexcoordsTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[i * 2] == (float)i;
		output += outputData[(i * 2) + 1] == (float)i + 1;
	}

	return output;
}
