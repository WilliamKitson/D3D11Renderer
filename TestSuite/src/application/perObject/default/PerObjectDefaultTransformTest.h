#pragma once

#include <string>
#include <d3d11.h>

#include "PerObject.h"

class PerObjectDefaultTransformTest
{
public:
	PerObjectDefaultTransformTest();
	~PerObjectDefaultTransformTest();

	std::string test();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* perObject;
	HRESULT result;
};
