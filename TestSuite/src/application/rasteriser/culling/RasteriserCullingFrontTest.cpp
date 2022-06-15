#include "RasteriserCullingFrontTest.h"

RasteriserCullingFrontTest::RasteriserCullingFrontTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserCullingFrontTest::~RasteriserCullingFrontTest()
{
	cleanup(context);
	cleanup(device);
}

std::string RasteriserCullingFrontTest::test()
{
	if (FAILED(initialise()))
	{
		return "rasteriser culling front test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.setFront();
	unit.apply(device);
	unit.bind(context);

	if (FAILED(getDescription()))
	{
		return "rasteriser culling front test description failed to initialise\n";
	}

	if (description.CullMode == D3D11_CULL_FRONT)
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

HRESULT RasteriserCullingFrontTest::initialise()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT output = D3D11CreateDevice(
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

	return output;
}

HRESULT RasteriserCullingFrontTest::getDescription()
{
	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return E_FAIL;
	}

	state->GetDesc(&description);
	cleanup(state);

	return S_OK;
}
