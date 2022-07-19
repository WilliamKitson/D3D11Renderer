#include "ImplimentationSceneDefaultTest.h"

ImplimentationSceneDefaultTest::ImplimentationSceneDefaultTest()
	: unit{ new D3D11Renderer::Implimentation() }, sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationSceneDefaultTest::~ImplimentationSceneDefaultTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	delete unit;
}

std::string ImplimentationSceneDefaultTest::test()
{
	unit->initialise(HWND(), "");

	unit->getContext()->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "implimentation scene default test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation scene default test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation scene default test failed\n";
}

void ImplimentationSceneDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationSceneDefaultTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(data),
		D3D11_USAGE_STAGING,
		0,
		D3D11_CPU_ACCESS_READ,
		0,
		0
	};

	result = unit->getDevice()->CreateBuffer(
		&readDescription,
		NULL,
		&readBuffer
	);
}

void ImplimentationSceneDefaultTest::initialiseData()
{
	unit->getContext()->CopyResource(
		readBuffer,
		sceneBuffer
	);

	D3D11_MAPPED_SUBRESOURCE subresource;

	result = unit->getContext()->Map(
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
}

DirectX::XMMATRIX ImplimentationSceneDefaultTest::WVPDefault()
{
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
		960.0f / 540.0f,
		1.0f,
		100.0f
	);

	return world * view * projection;
}

bool ImplimentationSceneDefaultTest::success()
{
	DirectX::XMMATRIX worldViewProjection = WVPDefault();

	if (data[0] != worldViewProjection._11)
	{
		return false;
	}

	if (data[1] != worldViewProjection._12)
	{
		return false;
	}

	if (data[2] != worldViewProjection._13)
	{
		return false;
	}

	if (data[3] != worldViewProjection._14)
	{
		return false;
	}

	if (data[4] != worldViewProjection._21)
	{
		return false;
	}

	if (data[5] != worldViewProjection._22)
	{
		return false;
	}

	if (data[6] != worldViewProjection._23)
	{
		return false;
	}

	if (data[7] != worldViewProjection._24)
	{
		return false;
	}

	if (data[8] != worldViewProjection._31)
	{
		return false;
	}

	if (data[9] != worldViewProjection._32)
	{
		return false;
	}

	if (data[10] != worldViewProjection._33)
	{
		return false;
	}

	if (data[11] != worldViewProjection._34)
	{
		return false;
	}

	if (data[12] != worldViewProjection._41)
	{
		return false;
	}

	if (data[13] != worldViewProjection._42)
	{
		return false;
	}

	if (data[14] != worldViewProjection._43)
	{
		return false;
	}

	if (data[15] != worldViewProjection._44)
	{
		return false;
	}

	if (data[16] != 1.0f)
	{
		return false;
	}

	if (data[17] != 1.0f)
	{
		return false;
	}

	if (data[18] != 1.0f)
	{
		return false;
	}

	if (data[19] != 1.0f)
	{
		return false;
	}

	return true;
}
