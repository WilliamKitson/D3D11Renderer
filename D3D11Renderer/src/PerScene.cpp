#include "PerScene.h"

D3D11Renderer::PerScene::PerScene()
	: cBuffer{ nullptr }, data()
{
	float camera[8]{
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		90.0f,
		960.0f / 540.0f
	};

	setCamera(camera);

	for (int i{ 16 }; i < 20; i++)
	{
		data[i] = 1.0f;
	}
}

D3D11Renderer::PerScene::~PerScene()
{
	cleanup();
}

void D3D11Renderer::PerScene::initialise(ID3D11Device* input)
{
	cleanup();

	D3D11_BUFFER_DESC description{
		sizeof(data),
		D3D11_USAGE_DEFAULT,
		D3D11_BIND_CONSTANT_BUFFER,
		0,
		0,
		0
	};

	D3D11_SUBRESOURCE_DATA subresource{
		&data,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&cBuffer
	);
}

void D3D11Renderer::PerScene::bind(ID3D11DeviceContext* input)
{
	input->VSSetConstantBuffers(
		0,
		1,
		&cBuffer
	);
}

void D3D11Renderer::PerScene::setCamera(float input[8])
{
	DirectX::XMMATRIX world = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX viewPosition = DirectX::XMMatrixTranslation(
		input[0],
		input[1],
		input[2]
	);

	DirectX::XMMATRIX viewRotation = DirectX::XMMatrixRotationRollPitchYaw(
		input[3],
		input[4],
		input[5]
	);

	DirectX::XMMATRIX view = viewPosition * viewRotation;

	DirectX::XMMATRIX projection = DirectX::XMMatrixPerspectiveFovLH(
		DirectX::XMConvertToRadians(input[6]),
		input[7],
		1.0f,
		100.0f
	);

	DirectX::XMMATRIX worldViewProjection = world * view * projection;

	data[0] = worldViewProjection._11;
	data[1] = worldViewProjection._12;
	data[2] = worldViewProjection._13;
	data[3] = worldViewProjection._14;
	data[4] = worldViewProjection._21;
	data[5] = worldViewProjection._22;
	data[6] = worldViewProjection._23;
	data[7] = worldViewProjection._24;
	data[8] = worldViewProjection._31;
	data[9] = worldViewProjection._32;
	data[10] = worldViewProjection._33;
	data[11] = worldViewProjection._34;
	data[12] = worldViewProjection._41;
	data[13] = worldViewProjection._42;
	data[14] = worldViewProjection._43;
	data[15] = worldViewProjection._44;
}

void D3D11Renderer::PerScene::cleanup()
{
	if (cBuffer)
	{
		cBuffer->Release();
		cBuffer = nullptr;
	}
}
