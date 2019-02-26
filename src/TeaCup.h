#pragma once

#include "common.h"
#include "Patch.h"

#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TeaCup
{
public:
	static int numOfPatches;
	static int numOfVertices;
	static int *indices;
	static int *cpIndices;
	static glm::vec4 *vertices;

	TeaCup(GLuint vertexPositionAttribLocation, GLuint modelUniformLocation, GLuint colorUniformLocation);

	void display();

	void setShowControlPoints(bool show);

	~TeaCup();

private:
	std::vector<Patch*> *patches;
	GLuint modelUniformLocation;
	GLuint vertexPositionAttribLocation;
	GLuint colorUniformLocation;
	GLuint pointsVAO, pointsVBO, pointsIBO;
	bool showControlPoints;

	void initPatches();

	void initPoints();
};