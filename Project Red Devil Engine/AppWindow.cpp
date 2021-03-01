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
}

void AppWindow::onUpdate()
{
	Window::onUpdate();

}

void AppWindow::onDestroy()
{
	Window::onDestroy();

	GraphicsEngine::get()->release();
}
