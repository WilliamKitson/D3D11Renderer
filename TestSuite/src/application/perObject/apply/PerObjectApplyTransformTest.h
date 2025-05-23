#pragma once

#include <string>
#include <d3d11.h>

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT
#include <DirectXMath.h>

#include "PerObject.h"

class PerObjectApplyTransformTest
{
public:
	PerObjectApplyTransformTest();
	~PerObjectApplyTransformTest();

	std::string test();

private:
	void initialiseInput();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseOutput();
	void initialiseObject();
	void initialiseRead();
	bool success();
	DirectX::XMMATRIX convert(float[9]);

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float inputData[9];
	float outputData[20];
};
