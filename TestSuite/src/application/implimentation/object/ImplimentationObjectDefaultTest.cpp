#include "ImplimentationObjectDefaultTest.h"

ImplimentationObjectDefaultTest::ImplimentationObjectDefaultTest()
	: unit{ new D3D11Renderer::Implimentation() }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationObjectDefaultTest::~ImplimentationObjectDefaultTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	delete unit;
}

std::string ImplimentationObjectDefaultTest::test()
{
	unit->initialise(HWND(), "");

	unit->getContext()->VSGetConstantBuffers(
		1,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return "implimentation object default test failed to initialise object buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation object default test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation object default test failed\n";
}

void ImplimentationObjectDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationObjectDefaultTest::initialiseRead()
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

void ImplimentationObjectDefaultTest::initialiseData()
{
	unit->getContext()->CopyResource(
		readBuffer,
		objectBuffer
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

bool ImplimentationObjectDefaultTest::success()
{
	DirectX::XMMATRIX location = DirectX::XMMatrixTranslation(
		0.0f,
		0.0f,
		0.0f
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		0.0f,
		0.0f,
		0.0f
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		1.0f,
		1.0f,
		1.0f
	);

	DirectX::XMMATRIX transform = location * rotation * scale;

	if (data[0] != transform._11)
	{
		return false;
	}

	if (data[1] != transform._12)
	{
		return false;
	}

	if (data[2] != transform._13)
	{
		return false;
	}

	if (data[3] != transform._14)
	{
		return false;
	}

	if (data[4] != transform._21)
	{
		return false;
	}

	if (data[5] != transform._22)
	{
		return false;
	}

	if (data[6] != transform._23)
	{
		return false;
	}

	if (data[7] != transform._24)
	{
		return false;
	}

	if (data[8] != transform._31)
	{
		return false;
	}

	if (data[9] != transform._32)
	{
		return false;
	}

	if (data[10] != transform._33)
	{
		return false;
	}

	if (data[11] != transform._34)
	{
		return false;
	}

	if (data[12] != transform._41)
	{
		return false;
	}

	if (data[13] != transform._42)
	{
		return false;
	}

	if (data[14] != transform._43)
	{
		return false;
	}

	if (data[15] != transform._44)
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
