#include "InterleavedDefaultVertexTest.h"

InterleavedDefaultVertexTest::InterleavedDefaultVertexTest()
	: device{ nullptr }, context{ nullptr }, vBuffer(), result()
{
}

InterleavedDefaultVertexTest::~InterleavedDefaultVertexTest()
{
	cleanup(vBuffer);
	cleanup(context);
	cleanup(device);
}

std::string InterleavedDefaultVertexTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved default vertex test failed to initialise D3D11\n";
	}

	D3D11Renderer::Interleaved unit;

	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "interleaved default vertex test failed\n";
}

void InterleavedDefaultVertexTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedDefaultVertexTest::initialiseD3D11()
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

bool InterleavedDefaultVertexTest::success()
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
