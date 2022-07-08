#pragma once

#include <string>
#include <d3d11.h>

#include "Geometry.h"

class GeometryReloadPositionsTest
{
public:
	GeometryReloadPositionsTest();
	~GeometryReloadPositionsTest();

	std::string test();

private:
	void cleanup();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseVBuffer();
	void initialiseRead();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* vBuffer[3];
	ID3D11Buffer* readBuffer;
	HRESULT result;
};
