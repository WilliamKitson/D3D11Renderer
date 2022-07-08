#include "GeometryStridesNormalTest.h"

GeometryStridesNormalTest::GeometryStridesNormalTest()
	: device{ nullptr }, context{ nullptr }, result()
{
}

GeometryStridesNormalTest::~GeometryStridesNormalTest()
{
	cleanup(context);
	cleanup(device);
}

std::string GeometryStridesNormalTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry strides normal test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	float normal[] = {
		0.0f,
		0.0f,
		0.0f
	};

	unit.pushNormal(normal);
	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "geometry strides normal test failed\n";
}

void GeometryStridesNormalTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryStridesNormalTest::initialiseD3D11()
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

bool GeometryStridesNormalTest::success()
{
	UINT strides[3];

	context->IAGetVertexBuffers(
		0,
		3,
		nullptr,
		strides,
		nullptr
	);

	if (strides[2] == sizeof(float) * 3)
	{
		return true;
	}

	return false;
}
