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
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseOutput();
	void initialiseObject();
	void initialiseRead();
	bool success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float outputData[20];
};
