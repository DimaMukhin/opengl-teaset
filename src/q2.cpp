// Display a cube, using glDrawElements

#include "common.h"
#include "TeaCup.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

const char *WINDOW_TITLE = "A2Q2";
const double FRAME_RATE_MS = 1000.0 / 60.0;

// uniform variable locations
GLuint  modelUniformLocation, viewUniformLocation, projectionUniformLocation, colorUniformLocation;

// tea cup
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
	colorUniformLocation = glGetUniformLocation(program, "color");

	// setting default values for uniform variables
	glUniformMatrix4fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
	glUniformMatrix4fv(viewUniformLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
	glUniform4fv(colorUniformLocation, 1, glm::value_ptr(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)));

	tc = new TeaCup(vPosition, modelUniformLocation, colorUniformLocation);

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

//----------------------------------------------------------------------------

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	tc->display(); // display the tea cup

	glutSwapBuffers();
	glFinish();
}

//----------------------------------------------------------------------------

bool showControlPoints = false;
void keyboard(unsigned char key, int x, int y)
{
	// bind show control points on space bar press
	switch (key) {
	case 033: // Escape Key
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;
	case ' ':
		showControlPoints = !showControlPoints;
		tc->setShowControlPoints(showControlPoints);
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

// rotate camera around the world
GLfloat cameraAngle = 0.0f;
void update(void)
{
	glm::mat4 view;
	view = glm::rotate(view, glm::radians(cameraAngle), glm::vec3(0.0f, 1.0f, 0.0f));

	glUniformMatrix4fv(viewUniformLocation, 1, GL_FALSE, glm::value_ptr(view));

	cameraAngle += 0.1f;
	if (cameraAngle >= 360.0f) {
		cameraAngle = 0.0f;
	}
}

//----------------------------------------------------------------------------

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	/*GLfloat aspect = GLfloat(width) / height;
	glm::mat4  projection = glm::perspective(glm::radians(45.0f), aspect, 0.5f, 3.0f);*/
	glm::mat4  projection = glm::ortho(-1.0f, 1.0f, 1.0f, -1.0f, -3.0f, 3.0f);

	glUniformMatrix4fv(projectionUniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
}
