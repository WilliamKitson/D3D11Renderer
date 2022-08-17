#pragma once

#include <string>
#include <d3d11.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationShadersTest
{
public:
	ImplimentationShadersTest();
	~ImplimentationShadersTest();

	std::string test();

private:
	void cleanup();
	void cleanup(IUnknown*);

private:
	D3D11Renderer::Facade* unit;
	ID3D11VertexShader* shader;
	HRESULT result;
};
