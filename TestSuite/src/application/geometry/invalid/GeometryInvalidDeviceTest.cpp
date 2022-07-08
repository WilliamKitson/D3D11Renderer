#include "GeometryInvalidDeviceTest.h"

GeometryInvalidDeviceTest::GeometryInvalidDeviceTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

GeometryInvalidDeviceTest::~GeometryInvalidDeviceTest()
{
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryInvalidDeviceTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry invalid device test failed to initialise D3D11\n";
	}

	D3D11Renderer::Geometry unit;

	float position[] = {
		0.0f,
		0.0f,
		0.0f
	};

	float texcoord[] = {
		0.0f,
		0.0f
	};

	float normal[] = {
		0.0f,
		0.0f,
		0.0f
	};

	unit.pushPosition(position);
	unit.pushTexcoord(texcoord);
	unit.pushNormal(normal);
	unit.initialise(nullptr);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "geometry invalid device test failed\n";
}

void GeometryInvalidDeviceTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryInvalidDeviceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryInvalidDeviceTest::initialiseD3D11()
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

bool GeometryInvalidDeviceTest::success()
{
	context->IAGetVertexBuffers(
		0,
		3,
		vBuffer,
		nullptr,
		nullptr
	);

	int successes = 0;

	for (int i{ 0 }; i < 3; i++)
	{
		successes += !vBuffer[i];
	}

	if (successes == 3)
	{
		return true;
	}

	return false;
}
