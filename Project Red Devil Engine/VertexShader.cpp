///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///

#include "VertexShader.h"
#include "GraphicsEngine.h"


VertexShader::VertexShader()
{
	m_vs = 0;
}

void VertexShader::release()
{
	m_vs->Release();
	delete this;
}

bool VertexShader::init(const void* shader_byte_code, size_t byte_code_size)
{
	if (!SUCCEEDED(GraphicsEngine::get()->m_d3d_device->CreateVertexShader(shader_byte_code, byte_code_size, nullptr, &m_vs)))
		return false;

	return true;
}



VertexShader::~VertexShader()
{
}


