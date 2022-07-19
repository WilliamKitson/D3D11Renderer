#include "ImplimentationObjectTransformTest.h"

ImplimentationObjectTransformTest::ImplimentationObjectTransformTest()
	: unit{ new D3D11Renderer::Implimentation() }, transform(initialiseTransform()), objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), data()
{
}

ImplimentationObjectTransformTest::~ImplimentationObjectTransformTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	delete unit;
}

std::string ImplimentationObjectTransformTest::test()
{
	unit->initialise(HWND(), "");
	unit->objectTransform(transform);

	unit->getContext()->VSGetConstantBuffers(
		1,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return "implimentation object transform test failed to initialise object buffer\n";
	}

	initialiseRead();

	if (FAILED(result))
	{
		return "implimentation object transform test failed to initialise read buffer\n";
	}

	initialiseData();

	if (success())
	{
		return std::string();
	}

	return "implimentation object transform test failed\n";
}

D3D11Renderer::Transform ImplimentationObjectTransformTest::initialiseTransform()
{
	return D3D11Renderer::Transform{
		0.0f,
		1.0f,
		2.0f,
		3.0f,
		4.0f,
		5.0f,
		6.0f,
		7.0f,
		8.0f
	};
}

void ImplimentationObjectTransformTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationObjectTransformTest::initialiseRead()
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

void ImplimentationObjectTransformTest::initialiseData()
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

bool ImplimentationObjectTransformTest::success()
{
	DirectX::XMMATRIX location = DirectX::XMMatrixTranslation(
		transform.xpos,
		transform.ypos,
		transform.zpos
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		transform.xrot,
		transform.yrot,
		transform.zrot
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		transform.xscale,
		transform.yscale,
		transform.zscale
	);

	DirectX::XMMATRIX temp = location * rotation * scale;

	if (data[0] != temp._11)
	{
		return false;
	}

	if (data[1] != temp._12)
	{
		return false;
	}

	if (data[2] != temp._13)
	{
		return false;
	}

	if (data[3] != temp._14)
	{
		return false;
	}

	if (data[4] != temp._21)
	{
		return false;
	}

	if (data[5] != temp._22)
	{
		return false;
	}

	if (data[6] != temp._23)
	{
		return false;
	}

	if (data[7] != temp._24)
	{
		return false;
	}

	if (data[8] != temp._31)
	{
		return false;
	}

	if (data[9] != temp._32)
	{
		return false;
	}

	if (data[10] != temp._33)
	{
		return false;
	}

	if (data[11] != temp._34)
	{
		return false;
	}

	if (data[12] != temp._41)
	{
		return false;
	}

	if (data[13] != temp._42)
	{
		return false;
	}

	if (data[14] != temp._43)
	{
		return false;
	}

	if (data[15] != temp._44)
	{
		return false;
	}

	return true;
}
