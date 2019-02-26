#pragma once

#include "common.h"

#include <glm/glm.hpp>
#include <vector>

class Patch
{
public:
	static glm::mat4 MB;
	static glm::mat4 MBT;

	Patch(glm::mat4 px, glm::mat4 py, glm::mat4 pz, GLuint vertexPositionAttribLocation);

	void display();

	~Patch();

private:
	GLuint VAO, VBO, IBO;
	GLuint vertexPositionAttribLocation;
	glm::mat4 px, py, pz;
	glm::mat4 middleX, middleY, middleZ;
	std::vector<glm::vec4> *vertices;
	std::vector<GLuint> *indices;

	void init();

	void generateSurface(std::vector<glm::vec4> *vertices, std::vector<GLuint> *indices);
};