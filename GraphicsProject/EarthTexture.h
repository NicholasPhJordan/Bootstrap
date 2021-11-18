#pragma once
#include "Texture.h"
#include "Quad.h"

class EarthTexture : public Quad
{
public:
	EarthTexture(const char* texFile);

	void onDraw() override;

private:
	aie::Texture m_texture;
};

