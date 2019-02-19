// Display a cube, using glDrawElements

#include "common.h"
#include "TeaCup.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

const char *WINDOW_TITLE = "A2Q2";
const double FRAME_RATE_MS = 1000.0 / 60.0;

GLuint  modelUniformLocation, viewUniformLocation, projectionUniformLocation;

std::vector<glm::vec4> *surfaceVertices;
std::vector<GLuint> *surfaceIndices;

TeaCup *tc;

//----------------------------------------------------------------------------

// OpenGL initialization
void init()
{
	// Load shaders and use the resulting shader program
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(program, "vPosition");

	// getting uniform locations
	modelUniformLocation = glGetUniformLocation(program, "model");
	viewUniformLocation = glGetUniformLocation(program, "view");
	projectionUniformLocation = glGetUniformLocation(program, "projection");

	// setting default values for uniform variables
	glUniformMatrix4fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
	glUniformMatrix4fv(viewUniformLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4()));

	tc = new TeaCup(vPosition);

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

//----------------------------------------------------------------------------

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	tc->display();

	glutSwapBuffers();
	glFinish();
}

//----------------------------------------------------------------------------

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 033: // Escape Key
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;
	}
}

//----------------------------------------------------------------------------

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {

	}
}

//----------------------------------------------------------------------------

void update(void)
{
}

//----------------------------------------------------------------------------

// TODO: change back to perspective if required or if want to
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	/*GLfloat aspect = GLfloat(width) / height;
	glm::mat4  projection = glm::perspective(glm::radians(45.0f), aspect, 0.5f, 3.0f);*/
	glm::mat4  projection = glm::ortho(-1.0f, 1.0f, 1.0f, -1.0f);

	glUniformMatrix4fv(projectionUniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
}
