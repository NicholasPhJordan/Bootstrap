#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Quad.h"
#include "Texture.h"
#include "EarthTexture.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light0 = nullptr;
	Light* m_light1 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Quad* m_quad = nullptr;
	EarthTexture* m_earthTexture = nullptr;
};

