#include "Patch.h"

Patch::Patch(glm::mat4 px, glm::mat4 py, glm::mat4 pz, GLuint vertexPositionAttribLocation)
{
	this->px = px;
	this->py = py;
	this->pz = pz;
	this->vertexPositionAttribLocation = vertexPositionAttribLocation;

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

void Patch::generateSurface(std::vector<glm::vec4>* vertices, std::vector<GLuint>* indices)
{
	int N = 10;
	for (GLfloat u = 0.0f; u <= 1.0f; u += 1.0f / N) {
		for (GLfloat v = 0.0f; v <= 1.0f; v += 1.0f / N) {
			GLfloat v2 = v * v;
			GLfloat v3 = v2 * v;
			GLfloat u2 = u * u;
			GLfloat u3 = u2 * u;

			GLfloat Q = 1 - 3 * v + 3 * v2 - v3;
			GLfloat W = 3 * v - 6 * v2 + 3 * v3;
			GLfloat E = 3 * v2 - 3 * v3;
			GLfloat R = v3;

			GLfloat Ax = px[0][0] * Q + px[0][1] * W + px[0][2] * E + px[0][3] * R;
			GLfloat Ay = py[0][0] * Q + py[0][1] * W + py[0][2] * E + py[0][3] * R;
			GLfloat Az = pz[0][0] * Q + pz[0][1] * W + pz[0][2] * E + pz[0][3] * R;
			GLfloat Sx = px[1][0] * Q + px[1][1] * W + px[1][2] * E + px[1][3] * R;
			GLfloat Sy = py[1][0] * Q + py[1][1] * W + py[1][2] * E + py[1][3] * R;
			GLfloat Sz = pz[1][0] * Q + pz[1][1] * W + pz[1][2] * E + pz[1][3] * R;
			GLfloat Dx = px[2][0] * Q + px[2][1] * W + px[2][2] * E + px[2][3] * R;
			GLfloat Dy = py[2][0] * Q + py[2][1] * W + py[2][2] * E + py[2][3] * R;
			GLfloat Dz = pz[2][0] * Q + pz[2][1] * W + pz[2][2] * E + pz[2][3] * R;
			GLfloat Fx = px[3][0] * Q + px[3][1] * W + px[3][2] * E + px[3][3] * R;
			GLfloat Fy = py[3][0] * Q + py[3][1] * W + py[3][2] * E + py[3][3] * R;
			GLfloat Fz = pz[3][0] * Q + pz[3][1] * W + pz[3][2] * E + pz[3][3] * R;

			GLfloat Gx = Ax;
			GLfloat Gy = Ay;
			GLfloat Gz = Az;
			GLfloat Hx = -3 * Ax + 3 * Sx;
			GLfloat Hy = -3 * Ay + 3 * Sy;
			GLfloat Hz = -3 * Az + 3 * Sz;
			GLfloat Jx = 3 * Ax - 6 * Sx + 3 * Dx;
			GLfloat Jy = 3 * Ay - 6 * Sy + 3 * Dy;
			GLfloat Jz = 3 * Az - 6 * Sz + 3 * Dz;
			GLfloat Kx = -1 * Ax + 3 * Sx - 3 * Dx + Fx;
			GLfloat Ky = -1 * Ay + 3 * Sy - 3 * Dy + Fy;
			GLfloat Kz = -1 * Az + 3 * Sz - 3 * Dz + Fz;

			GLfloat finalX = Gx + u * Hx + u2 * Jx + u3 * Kx;
			GLfloat finalY = Gy + u * Hy + u2 * Jy + u3 * Ky;
			GLfloat finalZ = Gz + u * Hz + u2 * Jz + u3 * Kz;

			glm::vec4 finalPoint(finalX, finalY, finalZ, 1.0f);
			vertices->push_back(finalPoint);
		}
	}

	GLuint count = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			indices->push_back(count);
			indices->push_back(count + 1);
			indices->push_back(count + N + 1);

			indices->push_back(count + N + 1);
			indices->push_back(count + N);
			indices->push_back(count);

			count++;
		}
		count++;
	}
}
