#include "PerObjectApplyTransformTest.h"

PerObjectApplyTransformTest::PerObjectApplyTransformTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, readBuffer{ nullptr }, result(), inputData(), outputData()
{
	initialiseInput();
}

PerObjectApplyTransformTest::~PerObjectApplyTransformTest()
{
	cleanup(readBuffer);
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectApplyTransformTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per object apply transform test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(context);

	unit.setTransform(inputData.transform);
	unit.apply(context);

	initialiseOutput();

	if (FAILED(result))
	{
		return "per object apply transform test failed to initialise data\n";
	}

	if (success())
	{
		return std::string();
	}

	return "per object apply transform test failed\n";
}

void PerObjectApplyTransformTest::initialiseInput()
{
	for (int i{ 0 }; i < 16; i++)
	{
		inputData.transform[i] = (float)i;
	}
}

void PerObjectApplyTransformTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectApplyTransformTest::initialiseD3D11()
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

void PerObjectApplyTransformTest::initialiseOutput()
{
	initialiseObject();
	initialiseRead();

	if (FAILED(result))
	{
		return;
	}

	context->CopyResource(
		readBuffer,
		objectBuffer
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

void PerObjectApplyTransformTest::initialiseObject()
{
	context->VSGetConstantBuffers(
		0,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void PerObjectApplyTransformTest::initialiseRead()
{
	D3D11_BUFFER_DESC readDescription{
		sizeof(D3D11Renderer::CBufferPerObject),
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

bool PerObjectApplyTransformTest::success()
{
	D3D11Renderer::CBufferPerObject inputConverted = convert(convert(inputData));

	for (int i{ 0 }; i < 16; i++)
	{
		if (inputConverted.transform[i] != outputData.transform[i])
		{
			return false;
		}
	}

	return true;
}

DirectX::XMMATRIX PerObjectApplyTransformTest::convert(D3D11Renderer::CBufferPerObject input)
{
	DirectX::XMMATRIX position = DirectX::XMMatrixTranslation(
		input.transform[0],
		input.transform[1],
		input.transform[2]
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		input.transform[4],
		input.transform[5],
		input.transform[6]
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		input.transform[8],
		input.transform[9],
		input.transform[10]
	);

	return position * rotation * scale;
}

D3D11Renderer::CBufferPerObject PerObjectApplyTransformTest::convert(DirectX::XMMATRIX input)
{
	D3D11Renderer::CBufferPerObject output;

	output.transform[0] = input._11;
	output.transform[1] = input._12;
	output.transform[2] = input._13;
	output.transform[3] = input._14;
	output.transform[4] = input._21;
	output.transform[5] = input._22;
	output.transform[6] = input._23;
	output.transform[7] = input._24;
	output.transform[8] = input._31;
	output.transform[9] = input._32;
	output.transform[10] = input._33;
	output.transform[11] = input._34;
	output.transform[12] = input._41;
	output.transform[13] = input._42;
	output.transform[14] = input._43;
	output.transform[15] = input._44;

	return output;
}
