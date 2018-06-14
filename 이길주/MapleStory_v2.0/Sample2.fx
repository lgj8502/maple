cbuffer ConstBuffer
{
	matrix	matWorld;
	matrix	matView;
	matrix	matProjection;

	//	���� ����� ����
	float4	LightDir;
	float4	LightColor;
};

struct VPC_INPUT
{
	float4	Pos		: POSITION;
	float4	Color	: COLOR;
};
struct VPC_OUTPUT
{
	float4	Pos		: SV_POSITION;
	float4	Color	: COLOR;
};

VPC_OUTPUT VS_Color(VPC_INPUT Input)
{
	VPC_OUTPUT Out = (VPC_OUTPUT)0;

	Out.Pos = mul(Input.Pos, matWorld);
	Out.Pos = mul(Out.Pos, matView);
	Out.Pos = mul(Out.Pos, matProjection);
	Out.Color = Input.Color;

	return Out;
}

float4 PS_Color(VPC_OUTPUT Input) : SV_Target
{
	return Input.Color;
}
/////////////////////////////////////////////////////////
struct VNT_INPUT
{
	float4	Pos		: POSITION;
	float3	Normal	: NORMAL;
	float4	Tex		: TEXCOORD;
};
struct VNT_OUTPUT
{
	float4	Pos		: SV_POSITION;
	float3	Normal	: NORMAL;
	float4	Tex		: TEXCOORD;
};

Texture2D		Texture;
SamplerState	Sampler;

VNT_OUTPUT VS_NormalTex(VNT_INPUT Input)
{
	VNT_OUTPUT Out = (VNT_OUTPUT)0;

	Out.Pos = mul(Input.Pos, matWorld);
	Out.Pos = mul(Out.Pos, matView);
	Out.Pos = mul(Out.Pos, matProjection);
	Out.Normal = mul(float4(Input.Normal, 0), matWorld).xyz;
	Out.Tex = Input.Tex;

	return Out;
}
float4 PS_Tex(VNT_OUTPUT Input) : SV_Target
{
	float4 FinalColor = 0;

	//	���� ���� ���� ���
	FinalColor = saturate(-dot((float3)LightDir, Input.Normal) * LightColor);
	//	ȯ�汤 �ϰ������� �����Ѵ�.
	FinalColor += saturate(float4(0.2f, 0.2f, 0.2f, 1));
	//	�⺻����(�ؽ�ó) * �����������
	return Texture.Sample(Sampler, Input.Tex) * FinalColor;
}