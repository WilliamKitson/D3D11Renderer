#include "GeometryInvalidContextTest.h"

GeometryInvalidContextTest::GeometryInvalidContextTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

GeometryInvalidContextTest::~GeometryInvalidContextTest()
{
	cleanup();
	cleanup(context);
	cleanup(device);
}

std::string GeometryInvalidContextTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "geometry invalid context test failed to initialise D3D11\n";
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
	unit.initialise(device);
	unit.bind(nullptr);

	if (success())
	{
		return std::string();
	}

	return "geometry invalid context test failed\n";
}

void GeometryInvalidContextTest::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffer[i]);
	}
}

void GeometryInvalidContextTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void GeometryInvalidContextTest::initialiseD3D11()
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

bool GeometryInvalidContextTest::success()
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
