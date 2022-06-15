#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserCullingBackTest
{
public:
	RasteriserCullingBackTest();
	~RasteriserCullingBackTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	HRESULT initialise();
	HRESULT getDescription();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	CD3D11_RASTERIZER_DESC description;
};
