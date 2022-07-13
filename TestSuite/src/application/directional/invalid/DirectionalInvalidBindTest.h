#pragma once

#include <string>
#include <d3d11.h>

#include "Directional.h"

class DirectionalInvalidBindTest
{
public:
	DirectionalInvalidBindTest();
	~DirectionalInvalidBindTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	HRESULT result;
};
