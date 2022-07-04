#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserInvalidContextTest
{
public:
	RasteriserInvalidContextTest();
	~RasteriserInvalidContextTest();

	std::string test();

private:
	void cleanup(IUnknown*);

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11RasterizerState* state;
	HRESULT result;
};
