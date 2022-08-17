#include "ImplimentationObjectTransformTest.h"

ImplimentationObjectTransformTest::ImplimentationObjectTransformTest()
	: unit{ new D3D11Renderer::Implimentation() }, inputData(initialiseTransform()), objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), outputData()
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
	unit->objectTransform(inputData);

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
		sizeof(outputData),
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
		&outputData,
		subresource.pData,
		sizeof(outputData)
	);
}

bool ImplimentationObjectTransformTest::success()
{
	if (!position(transform()))
	{
		return false;
	}

	if (!rotation(transform()))
	{
		return false;
	}

	if (!scale(transform()))
	{
		return false;
	}

	if (!packing(transform()))
	{
		return false;
	}

	return true;
}

bool ImplimentationObjectTransformTest::position(DirectX::XMMATRIX input)
{
	if (outputData[0] != input._11)
	{
		return false;
	}

	if (outputData[1] != input._12)
	{
		return false;
	}

	if (outputData[2] != input._13)
	{
		return false;
	}

	if (outputData[3] != input._14)
	{
		return false;
	}

	return true;
}

bool ImplimentationObjectTransformTest::rotation(DirectX::XMMATRIX input)
{
	if (outputData[4] != input._21)
	{
		return false;
	}

	if (outputData[5] != input._22)
	{
		return false;
	}

	if (outputData[6] != input._23)
	{
		return false;
	}

	if (outputData[7] != input._24)
	{
		return false;
	}

	return true;
}

bool ImplimentationObjectTransformTest::scale(DirectX::XMMATRIX input)
{
	if (outputData[8] != input._31)
	{
		return false;
	}

	if (outputData[9] != input._32)
	{
		return false;
	}

	if (outputData[10] != input._33)
	{
		return false;
	}

	if (outputData[11] != input._34)
	{
		return false;
	}

	return true;
}

bool ImplimentationObjectTransformTest::packing(DirectX::XMMATRIX input)
{
	if (outputData[12] != input._41)
	{
		return false;
	}

	if (outputData[13] != input._42)
	{
		return false;
	}

	if (outputData[14] != input._43)
	{
		return false;
	}

	if (outputData[15] != input._44)
	{
		return false;
	}

	return true;
}

DirectX::XMMATRIX ImplimentationObjectTransformTest::transform()
{
	DirectX::XMMATRIX location = DirectX::XMMatrixTranslation(
		inputData.xpos,
		inputData.ypos,
		inputData.zpos
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		inputData.xrot,
		inputData.yrot,
		inputData.zrot
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		inputData.xscale,
		inputData.yscale,
		inputData.zscale
	);

	return location * rotation * scale;
}
