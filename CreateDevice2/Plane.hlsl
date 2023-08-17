struct VS_IN
{
    float3 p : POSITION;
    float2 t : TEXTURE;
};

struct VS_OUT
{
    float4 p : SV_POSITION;
    float2 t : TEXTURE;
};
VS_OUT VS(VS_IN vIn)
{
    VS_OUT vOut = (VS_OUT)0;
    vOut.p = float4(vIn.p.x, vIn.p.y, vIn.p.z, 1);
    vOut.t = vIn.t;
    return vOut;
}


Texture2D g_txDiffuse1 : register(t0);
SamplerState sample0 : register(s0);
struct PS_IN
{
    float4 p : SV_POSITION;
    float2 t : TEXTURE;
};
float4 PS(PS_IN vIn) : SV_Target
{
    return g_txDiffuse1.Sample(sample0, vIn.t);
}