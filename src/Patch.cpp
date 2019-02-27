#include "Patch.h"

glm::mat4 Patch::MB = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f, -3.0f, 3.0f, 0.0f, 0.0f, 3.0f, -6.0f, 3.0f, 0.0f, -1.0f, 3.0f, -3.0f, 1.0f);
glm::mat4 Patch::MBT = glm::mat4(1.0f, -3.0f, 3.0f, -1.0f, 0.0f, 3.0f, -6.0f, 3.0f, 0.0f, 0.0f, 3.0f, -3.0f, 0.0f, 0.0f, 0.0f, 1.0f);

Patch::Patch(glm::mat4 px, glm::mat4 py, glm::mat4 pz, GLuint vertexPositionAttribLocation)
{
	this->px = px;
	this->py = py;
	this->pz = pz;
	this->vertexPositionAttribLocation = vertexPositionAttribLocation;

	middleX = MBT * px * MB;
	middleY = MBT * py * MB;
	middleZ = MBT * pz * MB;

	init();
}

void Patch::display()
{
	glBindVertexArray(VAO);

	for (int i = 0; i < indices->size(); i += 3) {
		glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(i * sizeof(GLuint)));
	}

	glBindVertexArray(0);
}

Patch::~Patch()
{
}

// initialize the patch
void Patch::init()
{
	vertices = new std::vector<glm::vec4>();
	indices = new std::vector<GLuint>();
	generateSurface(vertices, indices);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof((*vertices)[0]) * vertices->size(), &vertices->front(), GL_STATIC_DRAW);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof((*indices)[0]) * indices->size(), &indices->front(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(vertexPositionAttribLocation);
	glVertexAttribPointer(vertexPositionAttribLocation, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	// unbinding
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// calculate the vertices of the patch based on its control points
void Patch::generateSurface(std::vector<glm::vec4>* vertices, std::vector<GLuint>* indices)
{
	int N = 10;
	for (GLfloat u = 0.0f; u <= 1.01f; u += 1.0f / N) {
		for (GLfloat v = 0.0f; v <= 1.01f; v += 1.0f / N) {
			glm::vec4 mvx = glm::vec4(1, v, v*v, v*v*v) * middleX;
			glm::vec4 mvy = glm::vec4(1, v, v*v, v*v*v) * middleY;
			glm::vec4 mvz = glm::vec4(1, v, v*v, v*v*v) * middleZ;

			GLfloat finalX = glm::dot(mvx, glm::vec4(1, u, u*u, u*u*u));
			GLfloat finalY = glm::dot(mvy, glm::vec4(1, u, u*u, u*u*u));
			GLfloat finalZ = glm::dot(mvz, glm::vec4(1, u, u*u, u*u*u));

			glm::vec4 finalPoint(finalX, finalY, finalZ, 1.0f);
			vertices->push_back(finalPoint);
		}
	}

	GLuint count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			indices->push_back(count);
			indices->push_back(count + 1);
			indices->push_back(count + N + 2);

			indices->push_back(count + N + 2);
			indices->push_back(count + N + 1);
			indices->push_back(count);

			count++;
		}
		count++;
	}
}
