#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserDefaultDepthTest
{
public:
	RasteriserDefaultDepthTest();
	~RasteriserDefaultDepthTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();
	CD3D11_RASTERIZER_DESC description();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
