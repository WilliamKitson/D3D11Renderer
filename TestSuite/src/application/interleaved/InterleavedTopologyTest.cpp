#include "InterleavedTopologyTest.h"

InterleavedTopologyTest::InterleavedTopologyTest()
	: device{ nullptr }, context{ nullptr }, result()
{
}

InterleavedTopologyTest::~InterleavedTopologyTest()
{
	cleanup(context);
	cleanup(device);
}

std::string InterleavedTopologyTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "interleaved default test failed to initialise D3D11\n";
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
	unit.render(context);

	D3D11_PRIMITIVE_TOPOLOGY topology;
	context->IAGetPrimitiveTopology(&topology);

	if (topology == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
	{
		return std::string();
	}

	return "interleaved topology test failed\n";
}

void InterleavedTopologyTest::initialiseD3D11()
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

void InterleavedTopologyTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}
