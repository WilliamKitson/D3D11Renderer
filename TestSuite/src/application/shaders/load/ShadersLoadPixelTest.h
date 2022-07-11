#pragma once

#include <string>
#include <d3d11.h>

#include "Shaders.h"

class ShadersLoadPixelTest
{
public:
	ShadersLoadPixelTest();
	~ShadersLoadPixelTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11PixelShader* shader;
	HRESULT result;
};
