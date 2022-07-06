#pragma once

#include <string>
#include <d3d11.h>

#include "PerObject.h"

class PerObjectApplyColourTest
{
public:
	PerObjectApplyColourTest();
	~PerObjectApplyColourTest();

	std::string test();

private:
	void initialiseInput();
	void cleanup(IUnknown*);
	void initialiseD3D11();
	void initialiseOutput();
	void initialiseObject();
	void initialiseRead();
	int successes();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	ID3D11Buffer* objectBuffer;
	ID3D11Buffer* readBuffer;
	HRESULT result;
	float inputData[3];
	float outputData[20];
};
