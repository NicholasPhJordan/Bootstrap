#pragma once
#include "Entity.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class Light : public Entity
{
public:
	Light() {}
	Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, int count);
	~Light() {}

	void onDraw() override;

	// Light Direction
	glm::vec3 getDirection();
	void setDirection(glm::vec3 direction);

	// Ambient Color
	glm::vec4 getAmbient(int count);
	void setAmbient(glm::vec4 ambient, int count);
	// Diffuse Color
	glm::vec4 getDiffuse(int count);
	void setDiffuse(glm::vec4 diffuse, int count);
	// Specular Color
	glm::vec4 getSpecular(int count);
	void setSpecular(glm::vec4 specular, int count);

	// Count
	int getCount() { return m_count; }

private:
	// Light0
	glm::vec4 m_ambient = glm::vec4(0.0f);
	glm::vec4 m_diffuse = glm::vec4(0.0f);
	glm::vec4 m_specular = glm::vec4(0.0f);
	// Light1
	glm::vec4 m_ambient1 = glm::vec4(0.0f);
	glm::vec4 m_diffuse1 = glm::vec4(0.0f);
	glm::vec4 m_specular1 = glm::vec4(0.0f);
	int m_count = 0;
};

