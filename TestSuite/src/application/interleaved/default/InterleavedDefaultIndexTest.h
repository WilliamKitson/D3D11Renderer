#pragma once

#include <string>
#include <d3d11.h>

#include "Interleaved.h"

class InterleavedDefaultIndexTest
{
public:
	InterleavedDefaultIndexTest();
	~InterleavedDefaultIndexTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	bool success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* iBuffer;
	HRESULT result;
};
