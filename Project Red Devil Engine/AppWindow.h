///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///


#pragma once
#include "Window.h"
#include "SwapChain.h"
#include "GraphicsEngine.h"

class AppWindow: public Window
{
public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;

private:
	SwapChain* m_swap_chain;
};

