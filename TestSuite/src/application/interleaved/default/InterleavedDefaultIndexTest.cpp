#include "InterleavedDefaultIndexTest.h"

InterleavedDefaultIndexTest::InterleavedDefaultIndexTest()
	: device{ nullptr }, context{ nullptr }, iBuffer(), result()
{
}

InterleavedDefaultIndexTest::~InterleavedDefaultIndexTest()
{
	cleanup(iBuffer);
	cleanup(context);
	cleanup(device);
}

std::string InterleavedDefaultIndexTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved default index test failed to initialise D3D11\n";
	}

	D3D11Renderer::Interleaved unit;

	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "interleaved default index test failed\n";
}

void InterleavedDefaultIndexTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedDefaultIndexTest::initialiseD3D11()
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

bool InterleavedDefaultIndexTest::success()
{
	context->IAGetIndexBuffer(
		&iBuffer,
		nullptr,
		nullptr
	);

	if (!iBuffer)
	{
		return true;
	}

	return false;
}
