#include "DragonWorld.h"

void DragonWorld::onStart()
{
	// Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-35.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light0
	m_light0 = new Light(
		{ 0.0f, 0.0f, 5.0f },
		{ 0.8f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	add(m_light0);
	m_light0->setIndex(0);

	//Light1
	m_light1 = new Light(
		{ 0.0f, 0.0f, -5.0f },
		{ 0.0f, 0.0f, 0.8f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	add(m_light1);
	m_light1->setIndex(1);

	// Quad
	m_quad = new Quad();
	m_quad->setColor(glm::vec4(0.6f, 0.0f, 0.2f, 1.0f));
	m_quad->getTransform()->scale(glm::vec3(10.0f));
	add(m_quad);

	// Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({ 0.0f, 0.0f, 0.0f });
	m_dragon->getTransform()->setScale(glm::vec3(0.25f));
	add(m_dragon);
}

void DragonWorld::onUpdate(float deltaTime)
{
}

void DragonWorld::onDraw()
{
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light0);
	destroy(m_light1);
	destroy(m_dragon);
}
