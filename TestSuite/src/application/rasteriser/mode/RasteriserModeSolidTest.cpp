#include "RasteriserModeSolidTest.h"

RasteriserModeSolidTest::RasteriserModeSolidTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserModeSolidTest::~RasteriserModeSolidTest()
{
	cleanup(context);
	cleanup(device);
}

std::string RasteriserModeSolidTest::test()
{
	if (FAILED(initialise()))
	{
		return "rasteriser mode solid test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.setWireframe();
	unit.apply(device);

	unit.setSolid();
	unit.apply(device);
	unit.bind(context);

	if (FAILED(getDescription()))
	{
		return "rasteriser mode solid test description failed to initialise\n";
	}

	if (description.FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "rasteriser mode solid test failed\n";
}

void RasteriserModeSolidTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

HRESULT RasteriserModeSolidTest::initialise()
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

HRESULT RasteriserModeSolidTest::getDescription()
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
