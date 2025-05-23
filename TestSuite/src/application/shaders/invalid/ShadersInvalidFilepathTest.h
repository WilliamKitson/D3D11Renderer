#pragma once

#include <string>
#include <d3d11.h>

#include "Shaders.h"

class ShadersInvalidFilepathTest
{
public:
	ShadersInvalidFilepathTest();
	~ShadersInvalidFilepathTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();
	bool success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11VertexShader* vShader;
	ID3D11InputLayout* layout;
	ID3D11PixelShader* pShader;
	HRESULT result;
};
