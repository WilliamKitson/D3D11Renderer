#include "PerObjectReloadTransformTest.h"

PerObjectReloadTransformTest::PerObjectReloadTransformTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), inputData(), outputData()
{
	initialiseInput();
}

PerObjectReloadTransformTest::~PerObjectReloadTransformTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectReloadTransformTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per object reload transform test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	float transform[16];

	for (int i{ 0 }; i < 16; i++)
	{
		transform[i] = inputData[i];
	}

	unit.setTransform(transform);
	unit.initialise(device);
	unit.bind(context);

	initialiseOutput();

	if (FAILED(result))
	{
		return "per object reload transform test failed to initialise data\n";
	}

	if (success())
	{
		return std::string();
	}

	return "per object reload transform test failed\n";
}

void PerObjectReloadTransformTest::initialiseInput()
{
	for (int i{ 0 }; i < 16; i++)
	{
		inputData[i] = (float)i;
	}
}

void PerObjectReloadTransformTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectReloadTransformTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	result = D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		levels,
		1,
		D3D11_SDK_VERSION,
		&device,
		&supported,
		&context
	);
}

void PerObjectReloadTransformTest::initialiseOutput()
{
	initialiseObject();
	initialiseRead();

	if (FAILED(result))
	{
		return;
	}

	context->CopyResource(
		readBuffer,
		objectBuffer
	);

	D3D11_MAPPED_SUBRESOURCE subresource;

	result = context->Map(
		readBuffer,
		NULL,
		D3D11_MAP_READ,
		NULL,
		&subresource
	);

	memcpy(
		&outputData,
		subresource.pData,
		sizeof(outputData)
	);
}

void PerObjectReloadTransformTest::initialiseObject()
{
	context->VSGetConstantBuffers(
		0,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void PerObjectReloadTransformTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(D3D11Renderer::CBufferPerObject),
		D3D11_USAGE_STAGING,
		0,
		D3D11_CPU_ACCESS_READ,
		0,
		0
	};

	result = device->CreateBuffer(
		&readDescription,
		NULL,
		&readBuffer
	);
}

bool PerObjectReloadTransformTest::success()
{
	DirectX::XMMATRIX transform = convert(inputData);

	if (outputData[0] != transform._11)
	{
		return false;
	}

	if(outputData[1] != transform._12)
	{
		return false;
	}

	if(outputData[2] != transform._13)
	{
		return false;
	}

	if(outputData[3] != transform._14)
	{
		return false;
	}

	if(outputData[4] != transform._21)
	{
		return false;
	}

	if(outputData[5] != transform._22)
	{
		return false;
	}

	if(outputData[6] != transform._23)
	{
		return false;
	}

	if(outputData[7] != transform._24)
	{
		return false;
	}

	if(outputData[8] != transform._31)
	{
		return false;
	}

	if(outputData[9] != transform._32)
	{
		return false;
	}

	if(outputData[10] != transform._33)
	{
		return false;
	}

	if(outputData[11] != transform._34)
	{
		return false;
	}

	if(outputData[12] != transform._41)
	{
		return false;
	}

	if(outputData[13] != transform._42)
	{
		return false;
	}

	if(outputData[14] != transform._43)
	{
		return false;
	}

	if(outputData[15] != transform._44)
	{
		return false;
	}

	return true;
}

DirectX::XMMATRIX PerObjectReloadTransformTest::convert(float input[20])
{
	DirectX::XMMATRIX position = DirectX::XMMatrixTranslation(
		input[0],
		input[1],
		input[2]
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		input[4],
		input[5],
		input[6]
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		input[8],
		input[9],
		input[10]
	);

	return position * rotation * scale;
}
