/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net

#pragma once
#include <d3d11.h>
#include "SwapChain.h"

class SwapChain;
class DeviceContext;
class VertexBuffer;
class VertexShader;
class PixelShader;

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
	VertexBuffer* createVertexBuffer();
	VertexShader* createVertexShader(const void* shader_byte_code, size_t byte_code_size);
	PixelShader* createPixelShader(const void* shader_byte_code, size_t byte_code_size);
public:
	bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	bool compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	void releaseCompiledShader();

public:
	static GraphicsEngine* get();

private:
	DeviceContext* m_imm_device_context;

private:
	ID3D11Device * m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

private:
	ID3DBlob* m_blob = nullptr;
	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;
	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;
	
private:
	IDXGIDevice * m_dxdgi_device;
	IDXGIAdapter * m_dxdgi_adapter;
	IDXGIFactory * m_dxdgi_factory;
	ID3D11DeviceContext* m_imm_context;
	
private:
	friend class SwapChain;
	friend class VertexBuffer;
	friend class VertexShader;
	friend class PixelShader;
};

