#pragma once

#include <string>
#include <d3d11.h>

#include "PerObject.h"

class PerObjectInvalidApplyTest
{
public:
	PerObjectInvalidApplyTest();
	~PerObjectInvalidApplyTest();

	std::string test();

private:
	void initialiseUpdate();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseData();
	void initialiseObject();
	void initialiseRead();
	bool success();
	int successes();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	D3D11Renderer::CBufferPerObject update;
	D3D11Renderer::CBufferPerObject data;
};
