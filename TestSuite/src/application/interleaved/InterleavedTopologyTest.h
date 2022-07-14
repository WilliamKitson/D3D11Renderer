#pragma once

#include <string>
#include <d3d11.h>

#include "Interleaved.h"

class InterleavedTopologyTest
{
public:
	InterleavedTopologyTest();
	~InterleavedTopologyTest();

	std::string test();

private:
	void initialiseD3D11();
	void cleanup(IUnknown*);

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
