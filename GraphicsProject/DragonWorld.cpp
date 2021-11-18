#include "DragonWorld.h"

void DragonWorld::onStart()
{
	// Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-35.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	// Light0
	m_light0 = new Light(
		{ 0.0f, 0.0f, 5.0f },
		{ 0.8f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light0->setIndex(0);
	add(m_light0);

	// Light1
	m_light1 = new Light(
		{ 0.0f, 0.0f, -5.0f },
		{ 0.0f, 0.0f, 0.8f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light1->setIndex(1);
	add(m_light1);

	// Quad
	m_earthTexture = new EarthTexture("earth_diffuse.jpg");
	m_earthTexture->getTransform()->setScale(5.0f, 5.0f, 5.0f);
	add(m_earthTexture);

	// Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({ 0.0f, 0.0f, 0.0f });
	m_dragon->getTransform()->setScale(glm::vec3(0.25f));
	add(m_dragon);
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light0);
	destroy(m_light1);
	destroy(m_dragon);
	destroy(m_earthTexture);
}
