///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///

#pragma once
#include <d3d11.h>



class SwapChain
{
public:
	SwapChain();


	bool init(HWND hwnd, UINT width, UINT height);
	bool release();


	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
};

