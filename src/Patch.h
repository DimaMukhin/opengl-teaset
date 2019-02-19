#pragma once

#include "common.h"

#include <glm/glm.hpp>
#include <vector>

class Patch
{
public:
	Patch(glm::mat4 px, glm::mat4 py, glm::mat4 pz, GLuint vertexPositionAttribLocation);

	void display();

	~Patch();

private:
	GLuint VAO, VBO, IBO;
	GLuint vertexPositionAttribLocation;
	glm::mat4 px, py, pz;
	std::vector<glm::vec4> *vertices;
	std::vector<GLuint> *indices;

	void init();

	void generateSurface(std::vector<glm::vec4> *vertices, std::vector<GLuint> *indices);
};