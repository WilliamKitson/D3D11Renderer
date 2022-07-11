cbuffer CBufferPerScene : register(b0)
{
	matrix worldViewProjection;
	float4 ambience;
};

cbuffer CBufferPerObject : register(b1)
{
	matrix transform;
	float4 colour;
};

struct VInput
{
	float4 position : POSITION;
	float2 texcoord : TEXCOORD;
	float3 normal : NORMAL;
};

struct VOutput
{
	float4 position : SV_POSITION;
	float4 colour : COLOUR;
};

VOutput VShader(VInput input)
{
	VOutput output;

	output.position = mul(mul(worldViewProjection, transform), input.position);
	output.colour = colour * ambience;

	return output;
}

float4 PShader(VOutput output) : SV_TARGET
{
	return output.colour;
}
