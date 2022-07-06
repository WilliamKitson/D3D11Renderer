#include "PerScene.h"

D3D11Renderer::PerScene::PerScene()
	: cBuffer{ nullptr }, data()
{
	camera();
	ambience();
}

D3D11Renderer::PerScene::~PerScene()
{
	cleanup();
}

void D3D11Renderer::PerScene::initialise(ID3D11Device* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	cleanup();
	create(input);
}

void D3D11Renderer::PerScene::apply(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	input->UpdateSubresource(
		cBuffer,
		0,
		0,
		&data,
		0,
		0
	);
}

void D3D11Renderer::PerScene::bind(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	input->VSSetConstantBuffers(
		0,
		1,
		&cBuffer
	);
}

void D3D11Renderer::PerScene::setCamera(float input[8])
{
	DirectX::XMMATRIX transform = worldViewProjection(input);

	data[0] = transform._11;
	data[1] = transform._12;
	data[2] = transform._13;
	data[3] = transform._14;
	data[4] = transform._21;
	data[5] = transform._22;
	data[6] = transform._23;
	data[7] = transform._24;
	data[8] = transform._31;
	data[9] = transform._32;
	data[10] = transform._33;
	data[11] = transform._34;
	data[12] = transform._41;
	data[13] = transform._42;
	data[14] = transform._43;
	data[15] = transform._44;
}

void D3D11Renderer::PerScene::setAmbience(float input[3])
{
	for (int i{ 0 }; i < 3; i++)
	{
		data[16 + i] = input[i];
	}
}

void D3D11Renderer::PerScene::camera()
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
}

void D3D11Renderer::PerScene::ambience()
{
	for (int i{ 0 }; i < 4; i++)
	{
		data[16 + i] = 1.0f;
	}
}

void D3D11Renderer::PerScene::cleanup()
{
	if (cBuffer)
	{
		cBuffer->Release();
		cBuffer = nullptr;
	}
}

void D3D11Renderer::PerScene::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::PerScene::create(ID3D11Device* input)
{
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

DirectX::XMMATRIX D3D11Renderer::PerScene::worldViewProjection(float input[8])
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

	return world * view * projection;
}
