#pragma once

#include "common.h"
#include "Patch.h"

#include <vector>

class TeaCup
{
public:
	static int numOfPatches;
	static int numOfVertices;
	static int *indices;
	static glm::vec3 *vertices;

	TeaCup(GLuint vertexPositionAttribLocation);

	void display();

	~TeaCup();

private:
	std::vector<Patch*> *patches;
};