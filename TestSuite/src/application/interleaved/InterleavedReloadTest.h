#pragma once

#include <string>
#include <d3d11.h>

#include "Interleaved.h"

class InterleavedReloadTest
{
public:
	InterleavedReloadTest();
	~InterleavedReloadTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseVBuffer();
	void initialiseRead();
	void initialiseOutput();
	bool success();
	int successes();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* vBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float outputData[32];
};
