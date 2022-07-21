#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <string>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationSceneAmbienceTest
{
public:
	ImplimentationSceneAmbienceTest();
	~ImplimentationSceneAmbienceTest();

	std::string test();

private:
	D3D11Renderer::RGBA initialiseAmbience();
	void cleanup(IUnknown*);
	void initialiseRead();
	void initialiseData();
	bool success();

private:
	D3D11Renderer::Facade* unit;
	D3D11Renderer::RGBA ambience;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
