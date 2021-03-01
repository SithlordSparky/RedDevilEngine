///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///



#include "AppWindow.h"



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
}

void AppWindow::onUpdate()
{
	Window::onUpdate();

}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_swap_chain->release();
	GraphicsEngine::get()->release();
}
