#include "Shaders.h"

D3D11Renderer::Shaders::Shaders()
	: vShader{ nullptr }, layout{ nullptr }, pShader{ nullptr }, filepath{ L"" }
{
}

D3D11Renderer::Shaders::~Shaders()
{
	cleanup(pShader);
	cleanup(layout);
	cleanup(vShader);
}

void D3D11Renderer::Shaders::initialise(ID3D11Device* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	cleanup(pShader);
	cleanup(layout);
	cleanup(vShader);

	vLoad(input);
	pLoad(input);
}

void D3D11Renderer::Shaders::bind(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	input->VSSetShader(
		vShader,
		0,
		0
	);

	input->PSSetShader(
		pShader,
		0,
		0
	);

	input->IASetInputLayout(layout);
}

void D3D11Renderer::Shaders::setFilepath(std::string input)
{
	filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(input);
}

void D3D11Renderer::Shaders::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void D3D11Renderer::Shaders::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Shaders::vLoad(ID3D11Device* input)
{
	ID3DBlob* blob = nullptr;

	D3DCompileFromFile(
		filepath.c_str(),
		0,
		0,
		"VShader",
		"vs_4_0",
		0,
		0,
		&blob,
		nullptr
	);

	try
	{
		validate(blob);
	}
	catch (int)
	{
		return;
	}

	input->CreateVertexShader(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		NULL,
		&vShader
	);

	iLoad(input, blob);
}

void D3D11Renderer::Shaders::iLoad(ID3D11Device* device, ID3DBlob* blob)
{
	D3D11_INPUT_ELEMENT_DESC position{
		"POSITION",
		0,
		DXGI_FORMAT_R32G32B32_FLOAT,
		0,
		0,
		D3D11_INPUT_PER_VERTEX_DATA,
		0
	};

	D3D11_INPUT_ELEMENT_DESC texture{
		"TEXCOORD",
		0,
		DXGI_FORMAT_R32G32_FLOAT,
		1,
		D3D11_APPEND_ALIGNED_ELEMENT,
		D3D11_INPUT_PER_VERTEX_DATA,
		0
	};

	D3D11_INPUT_ELEMENT_DESC normal{
		"NORMAL",
		0,
		DXGI_FORMAT_R32G32B32_FLOAT,
		2,
		D3D11_APPEND_ALIGNED_ELEMENT,
		D3D11_INPUT_PER_VERTEX_DATA,
		0
	};

	D3D11_INPUT_ELEMENT_DESC description[] = {
		position,
		texture,
		normal
	};

	device->CreateInputLayout(
		description,
		3,
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		&layout
	);
}

void D3D11Renderer::Shaders::pLoad(ID3D11Device* input)
{
	ID3DBlob* blob = nullptr;

	D3DCompileFromFile(
		filepath.c_str(),
		0,
		0,
		"PShader",
		"ps_4_0",
		0,
		0,
		&blob,
		nullptr
	);

	try
	{
		validate(blob);
	}
	catch (int)
	{
		return;
	}

	input->CreatePixelShader(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		NULL,
		&pShader
	);
}
