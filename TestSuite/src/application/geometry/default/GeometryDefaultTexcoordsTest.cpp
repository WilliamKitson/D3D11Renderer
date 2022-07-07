#include "GeometryDefaultTexcoordsTest.h"

GeometryDefaultTexcoordsTest::GeometryDefaultTexcoordsTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

GeometryDefaultTexcoordsTest::~GeometryDefaultTexcoordsTest()
{
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryDefaultTexcoordsTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry default positions test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "geometry default positions test failed\n";
}

void GeometryDefaultTexcoordsTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryDefaultTexcoordsTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryDefaultTexcoordsTest::initialiseD3D11()
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

bool GeometryDefaultTexcoordsTest::success()
{
	UINT stride[] = {
		0,
		0,
		0
	};

	UINT offset[] = {
		0,
		0,
		0
	};

	context->IAGetVertexBuffers(
		0,
		3,
		vBuffer,
		stride,
		offset
	);

	if (!vBuffer[1])
	{
		return true;
	}

	return false;
}
