///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///

#include "AppWindow.h"

struct vec3
{
	float x, y, z;
};

struct vertex
{
	vec3 position;
	vec3 color;
};

AppWindow::AppWindow()
{
}
AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swap_chain=GraphicsEngine::get()->createSwapChain();
	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top);

	vertex list[] =
	{
		//x Y Z
		{-0.5f,-0.5f,0.0f, 1,0,0 }, // POS 1
		{-0.5f,0.5f,0.0f,  0,1,0 }, // POS 2
		{ 0.5f,-0.5f,0.0f, 0,0,1 }, // POS 3
		{ 0.5f,0.5f,0.0f,  1,1,0 }
	};

	m_vb=GraphicsEngine::get()->createVertexBuffer();
	UINT size_list = ARRAYSIZE(list);
	void* shader_byte_code = nullptr;
	size_t size_shader = 0;

	/// <summary>
	/// Vertex Shader
	/// </summary>
	GraphicsEngine::get()->compileVertexShader(L"VertexShader.hlsl","vsmain", &shader_byte_code, &size_shader);
	m_vs=GraphicsEngine::get()->createVertexShader(shader_byte_code, size_shader);
	m_vb->load(list, sizeof(vertex), size_list, shader_byte_code, size_shader);
	GraphicsEngine::get()->releaseCompiledShader();

	/// <summary>
	/// Pixel Shader
	/// </summary>
	GraphicsEngine::get()->compilePixelShader(L"PixelShader.hlsl", "psmain", &shader_byte_code, &size_shader);
	m_ps = GraphicsEngine::get()->createPixelShader(shader_byte_code, size_shader);
	GraphicsEngine::get()->releaseCompiledShader();
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	// Clear the Render Target
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swap_chain,1, 0, 0, 1);
	// Set Viewport of render target in which we have to draw
	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewPortSize(rc.right - rc.left, rc.bottom - rc.top);
	// Set default shader in the graphics pipeline to be able to draw
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexShader(m_vs);
	GraphicsEngine::get()->getImmediateDeviceContext()->setPixelShader(m_ps);
	// Set the vertices of the triangle to draw
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(m_vb);
	// draw the triangle
	GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleList(m_vb->getSizeVertexList(), 0);
	m_swap_chain->present(false);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_vb->release();
	m_vs->release();
	m_ps->release();
	m_swap_chain->release();
	GraphicsEngine::get()->release();
}