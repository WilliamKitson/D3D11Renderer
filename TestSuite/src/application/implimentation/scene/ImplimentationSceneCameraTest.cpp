#include "ImplimentationSceneCameraTest.h"

ImplimentationSceneCameraTest::ImplimentationSceneCameraTest()
	: unit{ new D3D11Renderer::Implimentation() }, camera(initialiseCamera()), sceneBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationSceneCameraTest::~ImplimentationSceneCameraTest()
{
	cleanup(readBuffer);
	cleanup(sceneBuffer);
	delete unit;
}

std::string ImplimentationSceneCameraTest::test()
{
	unit->initialise(HWND(), "");
	unit->sceneCamera(camera);

	unit->getContext()->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return "implimentation scene camera test failed to initialise scene buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation scene camera test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation scene camera test failed\n";
}

D3D11Renderer::Camera ImplimentationSceneCameraTest::initialiseCamera()
{
	return D3D11Renderer::Camera{
		0.0f,
		1.0f,
		2.0f,
		3.0f,
		4.0f,
		5.0f,
		6.0f,
		7.0f
	};
}

void ImplimentationSceneCameraTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationSceneCameraTest::initialiseRead()
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

void ImplimentationSceneCameraTest::initialiseData()
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

bool ImplimentationSceneCameraTest::success()
{
	if (!position(WVPCamera()))
	{
		return false;
	}

	if (!rotation(WVPCamera()))
	{
		return false;
	}

	if (!scale(WVPCamera()))
	{
		return false;
	}

	if (!packing(WVPCamera()))
	{
		return false;
	}

	return true;
}

bool ImplimentationSceneCameraTest::position(DirectX::XMMATRIX input)
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

bool ImplimentationSceneCameraTest::rotation(DirectX::XMMATRIX input)
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

bool ImplimentationSceneCameraTest::scale(DirectX::XMMATRIX input)
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

bool ImplimentationSceneCameraTest::packing(DirectX::XMMATRIX input)
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

DirectX::XMMATRIX ImplimentationSceneCameraTest::WVPCamera()
{
	DirectX::XMMATRIX world = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX position = DirectX::XMMatrixTranslation(
		camera.xpos,
		camera.ypos,
		camera.zpos
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		camera.xrot,
		camera.yrot,
		camera.zrot
	);

	DirectX::XMMATRIX projection = DirectX::XMMatrixPerspectiveFovLH(
		DirectX::XMConvertToRadians(camera.frustum),
		camera.aspectRatio,
		1.0f,
		100.0f
	);

	return world * position * rotation * projection;
}
