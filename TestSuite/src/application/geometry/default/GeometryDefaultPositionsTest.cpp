#include "GeometryDefaultPositionsTest.h"

GeometryDefaultPositionsTest::GeometryDefaultPositionsTest()
	: device{ nullptr }, context{ nullptr }, positionsBuffer{ nullptr }, result()
{
}

GeometryDefaultPositionsTest::~GeometryDefaultPositionsTest()
{
	cleanup(positionsBuffer);
	cleanup(context);
	cleanup(device);
}

std::string GeometryDefaultPositionsTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry default positions test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	unit.initialise(device);
	unit.bind(context);

	UINT stride = 0;
	UINT offset = 0;

	context->IAGetVertexBuffers(
		0,
		1,
		&positionsBuffer,
		&stride,
		&offset
	);

	if (!positionsBuffer)
	{
		return std::string();
	}

	return "geometry default positions test failed\n";
}

void GeometryDefaultPositionsTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryDefaultPositionsTest::initialiseD3D11()
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
