#pragma once

#include <string>
#include <d3d11.h>

#include "Shaders.h"

class ShadersInvalidDeviceTest
{
public:
	ShadersInvalidDeviceTest();
	~ShadersInvalidDeviceTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11VertexShader* shader;
	HRESULT result;
};
