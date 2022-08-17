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

bool ImplimentationSceneDefaultTest::success()
{
	if (!position(WVPDefault()))
	{
		return false;
	}

	if (!rotation(WVPDefault()))
	{
		return false;
	}

	if (!scale(WVPDefault()))
	{
		return false;
	}

	if (!packing(WVPDefault()))
	{
		return false;
	}

	if (!ambience())
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneDefaultTest::position(DirectX::XMMATRIX input)
{
	if (data[0] != input._11)
	{
		return false;
	}

	if (data[1] != input._12)
	{
		return false;
	}

	if (data[2] != input._13)
	{
		return false;
	}

	if (data[3] != input._14)
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneDefaultTest::rotation(DirectX::XMMATRIX input)
{
	if (data[4] != input._21)
	{
		return false;
	}

	if (data[5] != input._22)
	{
		return false;
	}

	if (data[6] != input._23)
	{
		return false;
	}

	if (data[7] != input._24)
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneDefaultTest::scale(DirectX::XMMATRIX input)
{
	if (data[8] != input._31)
	{
		return false;
	}

	if (data[9] != input._32)
	{
		return false;
	}

	if (data[10] != input._33)
	{
		return false;
	}

	if (data[11] != input._34)
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneDefaultTest::packing(DirectX::XMMATRIX input)
{
	if (data[12] != input._41)
	{
		return false;
	}

	if (data[13] != input._42)
	{
		return false;
	}

	if (data[14] != input._43)
	{
		return false;
	}

	if (data[15] != input._44)
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneDefaultTest::ambience()
{
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
