#pragma once

#include <string>
#include <d3d11.h>

#include "Geometry.h"

class GeometryDefaultPositionsTest
{
public:
	GeometryDefaultPositionsTest();
	~GeometryDefaultPositionsTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* positionsBuffer;
	HRESULT result;
};
