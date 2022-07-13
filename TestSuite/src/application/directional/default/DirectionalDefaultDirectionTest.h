#pragma once

#include <string>
#include <d3d11.h>

#include "Directional.h"

class DirectionalDefaultDirectionTest
{
public:
	DirectionalDefaultDirectionTest();
	~DirectionalDefaultDirectionTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseOutput();
	void initialiseCBuffer();
	void initialiseRead();
	int success();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* cBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float outputData[8];
};
