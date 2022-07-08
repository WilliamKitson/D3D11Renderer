#include "GeometryDefaultNormalsTest.h"

GeometryDefaultNormalsTest::GeometryDefaultNormalsTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

GeometryDefaultNormalsTest::~GeometryDefaultNormalsTest()
{
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryDefaultNormalsTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry default normals test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "geometry default normals test failed\n";
}

void GeometryDefaultNormalsTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryDefaultNormalsTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryDefaultNormalsTest::initialiseD3D11()
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

bool GeometryDefaultNormalsTest::success()
{
	context->IAGetVertexBuffers(
		0,
		3,
		vBuffer,
		nullptr,
		nullptr
	);

	if (!vBuffer[2])
	{
		return true;
	}

	return false;
}
