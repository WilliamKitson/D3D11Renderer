#include "InterleavedInvalidContextTest.h"

InterleavedInvalidContextTest::InterleavedInvalidContextTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

InterleavedInvalidContextTest::~InterleavedInvalidContextTest()
{
	cleanup(vBuffer);
	cleanup(context);
	cleanup(device);
}

std::string InterleavedInvalidContextTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved invalid context test failed to initialise D3D11\n";
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
	unit.render(nullptr);

	if (success())
	{
		return std::string();
	}

	return "interleaved invalid context test failed\n";
}

void InterleavedInvalidContextTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedInvalidContextTest::initialiseD3D11()
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

bool InterleavedInvalidContextTest::success()
{
	context->IAGetVertexBuffers(
		0,
		1,
		&vBuffer,
		nullptr,
		nullptr
	);

	if (!vBuffer)
	{
		return true;
	}

	return false;
}
