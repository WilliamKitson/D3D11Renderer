#pragma once

#include <string>
#include <d3d11.h>

#include "PerObject.h"

class PerObjectReloadTransformTest
{
public:
	PerObjectReloadTransformTest();
	~PerObjectReloadTransformTest();

	std::string test();

private:
	void initialiseInput();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseOutput();
	void initialiseObject();
	void initialiseRead();
	bool success();
	DirectX::XMMATRIX convert(D3D11Renderer::CBufferPerObject);
	D3D11Renderer::CBufferPerObject convert(DirectX::XMMATRIX);

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	D3D11Renderer::CBufferPerObject inputData;
	D3D11Renderer::CBufferPerObject outputData;
};
