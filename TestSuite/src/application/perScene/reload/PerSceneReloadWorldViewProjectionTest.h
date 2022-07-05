#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "PerScene.h"

class PerSceneReloadWorldViewProjectionTest
{
public:
	PerSceneReloadWorldViewProjectionTest();
	~PerSceneReloadWorldViewProjectionTest();

	std::string test();

private:
	void initialiseCamera();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseRead();
	void initialiseOuput();
	DirectX::XMMATRIX WVPCamera();
	bool success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float camera[8];
	float outputData[20];
};
