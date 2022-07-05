#pragma once

#include <string>
#include <d3d11.h>

#include "PerScene.h"

class PerSceneDefaultAmbienceTest
{
public:
	PerSceneDefaultAmbienceTest();
	~PerSceneDefaultAmbienceTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseRead();
	void initialiseData();
	int successes();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* sceneBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float data[20];
};
