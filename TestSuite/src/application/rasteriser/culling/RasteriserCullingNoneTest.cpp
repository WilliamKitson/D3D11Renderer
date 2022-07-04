#include "RasteriserCullingNoneTest.h"

RasteriserCullingNoneTest::RasteriserCullingNoneTest()
	: device{ nullptr }, context{ nullptr }, result()
{
	initialise();
}

RasteriserCullingNoneTest::~RasteriserCullingNoneTest()
{
	cleanup(context);
	cleanup(device);
}

std::string RasteriserCullingNoneTest::test()
{
	if (FAILED(result))
	{
		return "rasteriser culling none test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.setNone();
	unit.initialise(device);
	unit.bind(context);

	if (description().CullMode == D3D11_CULL_NONE)
	{
		return std::string();
	}

	return "rasteriser culling none test failed\n";
}

void RasteriserCullingNoneTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

void RasteriserCullingNoneTest::initialise()
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

CD3D11_RASTERIZER_DESC RasteriserCullingNoneTest::description()
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
