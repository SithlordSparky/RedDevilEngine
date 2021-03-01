///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///


#pragma once
#include <d3d11.h>

class SwapChain;

class DeviceContext
{

public:
	DeviceContext(ID3D11DeviceContext* device_context);
	
	bool Release();
	bool clearRenderTargetColor(SwapChain* swap_chain, float red, float green, float blue, float alpha);

	~DeviceContext();

private:
	ID3D11DeviceContext* m_device_context;
};

