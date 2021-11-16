#include "Light.h"
#include "gl_core_4_4.h"

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
}

void Light::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	// Light0
	int lightDirection = glGetUniformLocation(program, "iDirection0");
	int lightAmbient = glGetUniformLocation(program, "iAmbient0");
	int lightDiffuse = glGetUniformLocation(program, "iDiffuse0");
	int lightSpecular = glGetUniformLocation(program, "iSpecular0");

	if (lightDirection >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) {
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) {
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) {
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}

	// Light1
	int lightDirection1 = glGetUniformLocation(program, "iDirection1");
	int lightAmbient1 = glGetUniformLocation(program, "iAmbient1");
	int lightDiffuse1 = glGetUniformLocation(program, "iDiffuse1");
	int lightSpecular1 = glGetUniformLocation(program, "iSpecular1");

	if (lightDirection1 >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection1, direction.x, direction.y, direction.z);
	}
	if (lightAmbient1 >= 0) {
		glUniform3f(lightAmbient1, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse1 >= 0) {
		glUniform3f(lightDiffuse1, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular1 >= 0) {
		glUniform3f(lightSpecular1, m_specular.x, m_specular.y, m_specular.z);
	}
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}
