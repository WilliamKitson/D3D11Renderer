#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationObjectDefaultTest
{
public:
	ImplimentationObjectDefaultTest();
	~ImplimentationObjectDefaultTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseRead();
	void initialiseData();
	bool success();
	bool position(DirectX::XMMATRIX);
	bool rotation(DirectX::XMMATRIX);
	bool scale(DirectX::XMMATRIX);
	DirectX::XMMATRIX transform();

private:
	D3D11Renderer::Facade* unit;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
