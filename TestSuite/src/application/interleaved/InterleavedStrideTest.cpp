#include "InterleavedStrideTest.h"

InterleavedStrideTest::InterleavedStrideTest()
	: device{ nullptr }, context{ nullptr }, result()
{
}

InterleavedStrideTest::~InterleavedStrideTest()
{
	cleanup(context);
	cleanup(device);
}

std::string InterleavedStrideTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved stride test failed to initialise D3D11\n";
	}

	D3D11Renderer::Interleaved unit;

	float vertex[] = {
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f
	};

	unit.push(vertex);
	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "interleaved stride test failed\n";
}

void InterleavedStrideTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedStrideTest::initialiseD3D11()
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

bool InterleavedStrideTest::success()
{
	UINT strides;

	context->IAGetVertexBuffers(
		0,
		1,
		nullptr,
		&strides,
		nullptr
	);

	if (strides == sizeof(float) * 8)
	{
		return true;
	}

	return false;
}
