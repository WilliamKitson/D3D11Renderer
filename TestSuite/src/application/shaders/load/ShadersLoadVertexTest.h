#pragma once

#include <string>
#include <d3d11.h>

#include "Shaders.h"

class ShadersLoadVertexTest
{
public:
	ShadersLoadVertexTest();
	~ShadersLoadVertexTest();

	std::string test();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11VertexShader* shader;
	HRESULT result;
};
