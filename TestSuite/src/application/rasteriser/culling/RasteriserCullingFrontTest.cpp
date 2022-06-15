#include "RasteriserCullingFrontTest.h"

RasteriserCullingFrontTest::RasteriserCullingFrontTest()
	: device{ nullptr }, context{ nullptr }, result()
{
	initialise();
}

RasteriserCullingFrontTest::~RasteriserCullingFrontTest()
{
	cleanup(context);
	cleanup(device);
}

std::string RasteriserCullingFrontTest::test()
{
	if (FAILED(result))
	{
		return "rasteriser culling front test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.setFront();
	unit.apply(device);
	unit.bind(context);

	if (description().CullMode == D3D11_CULL_FRONT)
	{
		return std::string();
	}

	return "rasteriser culling front test failed\n";
}

void RasteriserCullingFrontTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

void RasteriserCullingFrontTest::initialise()
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

CD3D11_RASTERIZER_DESC RasteriserCullingFrontTest::description()
{
	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return CD3D11_RASTERIZER_DESC();
	}

	CD3D11_RASTERIZER_DESC output;
	state->GetDesc(&output);
	cleanup(state);

	return output;
}
