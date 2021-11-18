#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Quad.h"
#include "Texture.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onDraw() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light0 = nullptr;
	Light* m_light1 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Quad* m_quad = nullptr;

};

