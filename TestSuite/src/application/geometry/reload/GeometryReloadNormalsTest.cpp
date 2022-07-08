#include "GeometryReloadNormalsTest.h"

GeometryReloadNormalsTest::GeometryReloadNormalsTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), readBuffer{ nullptr }, result(), outputData()
{
}

GeometryReloadNormalsTest::~GeometryReloadNormalsTest()
{
	cleanup(readBuffer);
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryReloadNormalsTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry reload positions test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	unit.initialise(device);
	unit.bind(context);

	for (int i{ 0 }; i < 4; i++)
	{
		float normal[] = {
			 (float)i,
			 (float)i + 1,
			 (float)i + 2
		};

		unit.pushNormal(normal);
	}

	unit.initialise(device);
	unit.bind(context);

	initialiseVBuffer();

	if (!vBuffer[2])
	{
		return "geometry reload normals test failed to initialise vBuffer 2\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "geometry reload normals test failed to initialise read buffer\n";
	}

	initialiseOutput();

	if (success())
	{
		return std::string();
	}

	return "geometry reload normals test failed\n";
}

void GeometryReloadNormalsTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryReloadNormalsTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryReloadNormalsTest::initialiseD3D11()
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

void GeometryReloadNormalsTest::initialiseVBuffer()
{
	context->IAGetVertexBuffers(
		0,
		3,
		vBuffer,
		nullptr,
		nullptr
	);
}

void GeometryReloadNormalsTest::initialiseRead()
{
	D3D11_BUFFER_DESC vBufferDesc;

	vBuffer[2]->GetDesc(&vBufferDesc);

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

void GeometryReloadNormalsTest::initialiseOutput()
{
	context->CopyResource(
		readBuffer,
		vBuffer[2]
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

bool GeometryReloadNormalsTest::success()
{
	if (successes() == 12)
	{
		return true;
	}

	return false;
}

int GeometryReloadNormalsTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < 4; i++)
	{
		output += outputData[i * 3] == (float)i;
		output += outputData[(i * 3) + 1] == (float)i + 1;
		output += outputData[(i * 3) + 2] == (float)i + 2;
	}

	return output;
}
