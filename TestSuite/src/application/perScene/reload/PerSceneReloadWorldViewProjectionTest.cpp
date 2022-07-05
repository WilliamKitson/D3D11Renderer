#include "PerSceneReloadWorldViewProjectionTest.h"

PerSceneReloadWorldViewProjectionTest::PerSceneReloadWorldViewProjectionTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), camera(), outputData()
{
	for (int i{ 0 }; i < 8; i++)
	{
		camera[i] = (float)i;
	}
}

PerSceneReloadWorldViewProjectionTest::~PerSceneReloadWorldViewProjectionTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneReloadWorldViewProjectionTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene reload world view projection test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(context);

	unit.setCamera(camera);
	unit.initialise(device);
	unit.bind(context);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "per scene reload world view projection test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "per scene reload world view projection test failed to initialise read buffer\n";
	}

	initialiseOuput();

	if (success())
	{
		return std::string();
	}

	return "per scene reload world view projection test failed\n";
}

void PerSceneReloadWorldViewProjectionTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneReloadWorldViewProjectionTest::initialiseD3D11()
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

void PerSceneReloadWorldViewProjectionTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(outputData),
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

void PerSceneReloadWorldViewProjectionTest::initialiseOuput()
{
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
		&outputData,
		subresource.pData,
		sizeof(outputData)
	);
}

DirectX::XMMATRIX PerSceneReloadWorldViewProjectionTest::WVPCamera()
{
	DirectX::XMMATRIX world = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX viewPosition = DirectX::XMMatrixTranslation(
		camera[0],
		camera[1],
		camera[2]
	);

	DirectX::XMMATRIX viewRotation = DirectX::XMMatrixRotationRollPitchYaw(
		camera[3],
		camera[4],
		camera[5]
	);

	DirectX::XMMATRIX view = viewPosition * viewRotation;

	DirectX::XMMATRIX projection = DirectX::XMMatrixPerspectiveFovLH(
		DirectX::XMConvertToRadians(camera[6]),
		camera[7],
		1.0f,
		100.0f
	);

	return world * view * projection;
}

bool PerSceneReloadWorldViewProjectionTest::success()
{
	DirectX::XMMATRIX worldViewProjection = WVPCamera();

	if (outputData[0] != worldViewProjection._11)
	{
		return false;
	}

	if (outputData[1] != worldViewProjection._12)
	{
		return false;
	}

	if (outputData[2] != worldViewProjection._13)
	{
		return false;
	}

	if (outputData[3] != worldViewProjection._14)
	{
		return false;
	}

	if (outputData[4] != worldViewProjection._21)
	{
		return false;
	}

	if (outputData[5] != worldViewProjection._22)
	{
		return false;
	}

	if (outputData[6] != worldViewProjection._23)
	{
		return false;
	}

	if (outputData[7] != worldViewProjection._24)
	{
		return false;
	}

	if (outputData[8] != worldViewProjection._31)
	{
		return false;
	}

	if (outputData[9] != worldViewProjection._32)
	{
		return false;
	}

	if (outputData[10] != worldViewProjection._33)
	{
		return false;
	}

	if (outputData[11] != worldViewProjection._34)
	{
		return false;
	}

	if (outputData[12] != worldViewProjection._41)
	{
		return false;
	}

	if (outputData[13] != worldViewProjection._42)
	{
		return false;
	}

	if (outputData[14] != worldViewProjection._43)
	{
		return false;
	}

	if (outputData[15] != worldViewProjection._44)
	{
		return false;
	}

	return true;
}
