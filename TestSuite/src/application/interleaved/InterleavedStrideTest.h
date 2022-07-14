#pragma once

#include <string>
#include <d3d11.h>

#include "Interleaved.h"

class InterleavedStrideTest
{
public:
	InterleavedStrideTest();
	~InterleavedStrideTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	bool success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
