#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationSceneDefaultTest
{
public:
	ImplimentationSceneDefaultTest();
	~ImplimentationSceneDefaultTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseRead();
	void initialiseData();
	DirectX::XMMATRIX WVPDefault();
	bool success();

private:
	D3D11Renderer::Facade* unit;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
