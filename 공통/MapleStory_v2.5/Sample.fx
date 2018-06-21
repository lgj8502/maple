cbuffer ConstBuffer
{
	matrix matWorld;
	matrix matView;
	matrix matProjection;

	float4 LightDir;
	float4 LightColor;

	float4 OutputColor;
}

struct VS_INPUT
{
	float4 Pos		: POSITION;
	float3 Normal	: NORMAL;
};

struct VS_OUTPUT
{
	float4 Pos		: SV_POSITION;
	float3 Normal	: TEXCOORD0;
};

VS_OUTPUT	VS( VS_INPUT _Input )
{
	VS_OUTPUT Out = (VS_OUTPUT)0;

	Out.Pos = mul(_Input.Pos, matWorld);
	Out.Pos = mul(Out.Pos, matView);
	Out.Pos = mul(Out.Pos, matProjection);

	Out.Normal = mul(float4(_Input.Normal, 0), matWorld).xyz;

	return Out;
}

float4	PS( VS_OUTPUT Input) : SV_Target
{
	float4 finalColor = 0;


	finalColor += saturate(-dot((float3)LightDir, Input.Normal) * LightColor);


	return finalColor;
}

float4 PS_Solid(VS_OUTPUT Input) : SV_Target
{
	return OutputColor;
}