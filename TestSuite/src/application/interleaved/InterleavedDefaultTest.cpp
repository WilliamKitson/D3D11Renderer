#include "InterleavedDefaultTest.h"

InterleavedDefaultTest::InterleavedDefaultTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

InterleavedDefaultTest::~InterleavedDefaultTest()
{
	cleanup(vBuffer);
	cleanup(context);
	cleanup(device);
}

std::string InterleavedDefaultTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved default test failed to initialise D3D11\n";
	}

	D3D11Renderer::Interleaved unit;

	unit.initialise(device);
	unit.render(context);

	if (success())
	{
		return std::string();
	}

	return "interleaved default test failed\n";
}

void InterleavedDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedDefaultTest::initialiseD3D11()
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

bool InterleavedDefaultTest::success()
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
