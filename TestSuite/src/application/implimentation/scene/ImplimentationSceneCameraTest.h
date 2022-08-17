#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationSceneCameraTest
{
public:
	ImplimentationSceneCameraTest();
	~ImplimentationSceneCameraTest();

	std::string test();

private:
	D3D11Renderer::Camera initialiseCamera();
	void cleanup(IUnknown*);
	void initialiseRead();
	void initialiseData();
	bool success();
	bool position(DirectX::XMMATRIX);
	bool rotation(DirectX::XMMATRIX);
	bool scale(DirectX::XMMATRIX);
	DirectX::XMMATRIX WVPCamera();

private:
	D3D11Renderer::Facade* unit;
	D3D11Renderer::Camera camera;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
