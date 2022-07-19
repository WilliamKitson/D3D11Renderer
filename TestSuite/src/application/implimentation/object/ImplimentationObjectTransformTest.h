#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationObjectTransformTest
{
public:
	ImplimentationObjectTransformTest();
	~ImplimentationObjectTransformTest();

	std::string test();

private:
	D3D11Renderer::Transform initialiseTransform();
	void cleanup(IUnknown*);
	void initialiseRead();
	void initialiseData();
	bool success();

private:
	D3D11Renderer::Facade* unit;
	D3D11Renderer::Transform transform;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
