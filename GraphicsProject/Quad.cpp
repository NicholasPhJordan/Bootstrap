#include "Quad.h"

Quad::Quad(glm::vec4 color) : Quad::Quad()
{
	m_color = color;
	m_texture.load("earth_diffuse.jpg");
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount)
{
	//Set the number of vertices
	vertexCount = 6;

	//Define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];

	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1.0f };

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].normal = { 0.0f, 0.0f, 0.0f, 0.0f };
		vertices[i].color = m_color;
	}


	vertices[0].texCoord = { 0.0f, 1.0f };
	vertices[1].texCoord = { 1.0f, 1.0f };
	vertices[2].texCoord = { 0.0f, 0.0f };
	vertices[3].texCoord = { 1.0f, 0.0f };

	return vertices;
}

unsigned int* Quad::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 6;

	unsigned int* indices = new unsigned int[indexCount]{
		0, 1, 2,
		2, 1, 3
	};

	return indices;
}
