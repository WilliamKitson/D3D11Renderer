struct VInput
{
	float4 position : POSITION;
	float4 colour : COLOUR;
};

struct VOutput
{
	float4 position : SV_POSITION;
	float4 colour : COLOUR;
};

VOutput VShader(VInput input)
{
	VOutput output;

	output.position = input.position;
	output.colour = input.colour;

	return output;
}

float4 PShader(VOutput output) : SV_TARGET
{
	return output.colour;
}
