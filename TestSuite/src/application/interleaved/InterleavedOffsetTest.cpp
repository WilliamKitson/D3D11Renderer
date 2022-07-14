#include "InterleavedOffsetTest.h"

InterleavedOffsetTest::InterleavedOffsetTest()
	: device{ nullptr }, context{ nullptr }, result()
{
}

InterleavedOffsetTest::~InterleavedOffsetTest()
{
	cleanup(context);
	cleanup(device);
}

std::string InterleavedOffsetTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved offset test failed to initialise D3D11\n";
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

	unit.pushVertex(vertex);
	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "interleaved offset test failed\n";
}

void InterleavedOffsetTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void InterleavedOffsetTest::initialiseD3D11()
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

bool InterleavedOffsetTest::success()
{
	UINT offset;

	context->IAGetVertexBuffers(
		0,
		1,
		nullptr,
		nullptr,
		&offset
	);

	if (offset == 0)
	{
		return true;
	}

	return false;
}
