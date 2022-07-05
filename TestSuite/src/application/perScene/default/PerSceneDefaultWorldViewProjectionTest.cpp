#include "PerSceneDefaultWorldViewProjectionTest.h"

PerSceneDefaultWorldViewProjectionTest::PerSceneDefaultWorldViewProjectionTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

PerSceneDefaultWorldViewProjectionTest::~PerSceneDefaultWorldViewProjectionTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneDefaultWorldViewProjectionTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene default world view projection test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(context);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "per scene default world view projection test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "per scene default world view projection test failed to initialise read buffer\n";
	}

	context->CopyResource(
		readBuffer,
		sceneBuffer
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
		&data,
		subresource.pData,
		sizeof(data)
	);

	DirectX::XMMATRIX world = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX viewPosition = DirectX::XMMatrixTranslation(
		0.0f,
		0.0f,
		0.0f
	);

	DirectX::XMMATRIX viewRotation = DirectX::XMMatrixRotationRollPitchYaw(
		0.0f,
		0.0f,
		0.0f
	);

	DirectX::XMMATRIX view = viewPosition * viewRotation;

	DirectX::XMMATRIX projection = DirectX::XMMatrixPerspectiveFovLH(
		DirectX::XMConvertToRadians(90.0f),
		960.0f/540.0f,
		1.0f,
		100.0f
	);

	DirectX::XMMATRIX worldViewProjection = world * view * projection;

	bool success = true;

	if (data[0] != worldViewProjection._11)
	{
		success = false;
	}

	if (data[1] != worldViewProjection._12)
	{
		success = false;
	}

	if (data[2] != worldViewProjection._13)
	{
		success = false;
	}

	if (data[3] != worldViewProjection._14)
	{
		success = false;
	}

	if (data[4] != worldViewProjection._21)
	{
		success = false;
	}

	if (data[5] != worldViewProjection._22)
	{
		success = false;
	}

	if (data[6] != worldViewProjection._23)
	{
		success = false;
	}

	if (data[7] != worldViewProjection._24)
	{
		success = false;
	}

	if (data[8] != worldViewProjection._31)
	{
		success = false;
	}

	if (data[9] != worldViewProjection._32)
	{
		success = false;
	}

	if (data[10] != worldViewProjection._33)
	{
		success = false;
	}

	if (data[11] != worldViewProjection._34)
	{
		success = false;
	}

	if (data[12] != worldViewProjection._41)
	{
		success = false;
	}

	if (data[13] != worldViewProjection._42)
	{
		success = false;
	}

	if (data[14] != worldViewProjection._43)
	{
		success = false;
	}

	if (data[15] != worldViewProjection._44)
	{
		success = false;
	}

	if (success)
	{
		return std::string();
	}

	return "per scene default world view projection test failed\n";
}

void PerSceneDefaultWorldViewProjectionTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneDefaultWorldViewProjectionTest::initialiseD3D11()
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

void PerSceneDefaultWorldViewProjectionTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(data),
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
