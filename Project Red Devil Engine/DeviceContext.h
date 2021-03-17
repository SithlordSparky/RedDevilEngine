///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///


#pragma once
#include <d3d11.h>

class SwapChain;
class VertexBuffer;
class VertexShader;
class PixelShader;

class DeviceContext
{

public:
	DeviceContext(ID3D11DeviceContext* device_context);
	void setVertexBuffer(VertexBuffer* vertex_buffer);
	bool Release();
	void clearRenderTargetColor(SwapChain* swap_chain, float red, float green, float blue, float alpha);
	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);
	void setViewPortSize(UINT width, UINT height);
	void setVertexShader(VertexShader* vertex_shader);
	// Learn to spell Pixel properly
	void setPixelShader(PixelShader* pixel_shader);
	~DeviceContext();

private:
	ID3D11DeviceContext* m_device_context;
};

