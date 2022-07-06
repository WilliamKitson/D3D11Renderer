#pragma once

#include <string>
#include <d3d11.h>

#include "PerScene.h"

class PerSceneInvalidApplyTest
{
public:
	PerSceneInvalidApplyTest();
	~PerSceneInvalidApplyTest();

	std::string test();

private:
	void initialiseAmbience();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseRead();
	void initialiseOutput();
	int successes();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float ambience[4];
	float outputData[20];
};
