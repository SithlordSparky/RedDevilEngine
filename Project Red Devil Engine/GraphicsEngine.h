/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net

#pragma once
#include <d3d11.h>
#include "SwapChain.h"

class SwapChain;
class DeviceContext;

class GraphicsEngine
{
public:
	GraphicsEngine();
	// Initialize the graphics engine and directx 11 device
	bool init();
	// Release the resources loaded
	bool release();
	~GraphicsEngine();

public:
	SwapChain* createSwapChain();
	DeviceContext* getImmediateDeviceContext();
public:
	static GraphicsEngine* get();

private:
	DeviceContext* m_imm_device_context;

private:
	ID3D11Device * m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	
private:
	IDXGIDevice * m_dxdgi_device;
	IDXGIAdapter * m_dxdgi_adapter;
	IDXGIFactory * m_dxdgi_factory;
private:
	friend class SwapChain;
};

