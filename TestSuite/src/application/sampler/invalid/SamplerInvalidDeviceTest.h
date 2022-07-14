#pragma once

#include <string>
#include <d3d11.h>

#include "Sampler.h"

class SamplerInvalidDeviceTest
{
public:
	SamplerInvalidDeviceTest();
	~SamplerInvalidDeviceTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11SamplerState* state;
	HRESULT result;
};
