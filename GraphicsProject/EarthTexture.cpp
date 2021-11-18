#include "EarthTexture.h"
#include "gl_core_4_4.h"

EarthTexture::EarthTexture(const char* texFile)
{
	if (!m_texture.load(texFile))
	{
		printf("Texture not found!\n");
	}
}

void EarthTexture::onDraw()
{
	// Gets the shader
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
	{
		printf("no shader bound.\n");
	}

	// Gets the texture uniform
	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");

	// Binds the texture
	if (diffuseTextureUniform >= 0)
	{
		glUniform1i(diffuseTextureUniform, 0);
	}

	// Sets the texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());

	
	Quad::onDraw();
}
