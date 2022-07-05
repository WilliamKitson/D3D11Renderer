#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "PerScene.h"

class PerSceneDefaultWorldViewProjectionTest
{
public:
	PerSceneDefaultWorldViewProjectionTest();
	~PerSceneDefaultWorldViewProjectionTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseRead();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
