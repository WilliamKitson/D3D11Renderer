#pragma once

#include <string>
#include <d3d11.h>

#include "Shaders.h"

class ShadersLoadInputTest
{
public:
	ShadersLoadInputTest();
	~ShadersLoadInputTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11InputLayout* input;
	HRESULT result;
};
