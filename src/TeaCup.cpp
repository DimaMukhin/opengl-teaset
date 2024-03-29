#include "TeaCup.h"

int TeaCup::numOfPatches = 26;
int TeaCup::numOfVertices = 251;

// tea cup indices (values from provided file)
int* TeaCup::indices = new int[numOfPatches * 16]{
	1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
	4,17,18,19,8,20,21,22,12,23,24,25,16,26,27,28,
	19,29,30,31,22,32,33,34,25,35,36,37,28,38,39,40,
	31,41,42,1,34,43,44,5,37,45,46,9,40,47,48,13,
	13,14,15,16,49,50,51,52,53,54,55,56,57,58,59,60,
	16,26,27,28,52,61,62,63,56,64,65,66,60,67,68,69,
	28,38,39,40,63,70,71,72,66,73,74,75,69,76,77,78,
	40,47,48,13,72,79,80,49,75,81,82,53,78,83,84,57,
	193,194,195,196,197,198,199,200,201,202,203,204,1,2,3,4,
	196,205,206,207,200,208,209,210,204,211,212,213,4,17,18,19,
	207,214,215,216,210,217,218,219,213,220,221,222,19,29,30,31,
	216,223,224,193,219,225,226,197,222,227,228,201,31,41,42,1,
	229,230,231,28,232,233,234,235,236,237,238,239,240,241,242,243,
	28,244,245,229,235,246,247,232,239,248,249,236,243,250,251,240,
	57,58,59,60,85,86,87,88,89,90,91,92,93,94,95,96,
	60,67,68,69,88,97,98,99,92,100,101,102,96,103,104,105,
	69,76,77,78,99,106,107,108,102,109,110,111,105,112,113,114,
	78,83,84,57,108,115,116,85,111,117,118,89,114,119,120,93,
	93,94,95,96,121,122,123,124,125,126,127,128,129,130,131,132,
	96,103,104,105,124,133,134,135,128,136,137,138,132,139,140,141,
	105,112,113,114,135,142,143,144,138,145,146,147,141,148,149,150,
	114,119,120,93,144,151,152,121,147,153,154,125,150,155,156,129,
	129,130,131,132,157,158,159,160,161,162,163,164,165,166,167,168,
	132,139,140,141,160,169,170,171,164,172,173,174,168,175,176,177,
	141,148,149,150,171,178,179,180,174,181,182,183,177,184,185,186,
	150,155,156,129,180,187,188,157,183,189,190,161,186,191,192,165
};

// tea cup vertices (values from provided file)
glm::vec4* TeaCup::vertices = new glm::vec4[numOfVertices]{
	glm::vec4(0.409091,0.772727,0.0, 1.0),
	glm::vec4(0.409091,0.772727,-0.229091, 1.0),
	glm::vec4(0.229091,0.772727,-0.409091, 1.0),
	glm::vec4(0.0,0.772727,-0.409091, 1.0),
	glm::vec4(0.409091,0.886364,0.0, 1.0),
	glm::vec4(0.409091,0.886364,-0.229091, 1),
	glm::vec4(0.229091,0.886364,-0.409091, 1),
	glm::vec4(0.0,0.886364,-0.409091, 1),
	glm::vec4(0.454545,0.886364,0.0, 1),
	glm::vec4(0.454545,0.886364,-0.254545, 1),
	glm::vec4(0.254545,0.886364,-0.454545, 1),
	glm::vec4(0.0,0.886364,-0.454545, 1),
	glm::vec4(0.454545,0.772727,0.0, 1),
	glm::vec4(0.454545,0.772727,-0.254545, 1),
	glm::vec4(0.254545,0.772727,-0.454545, 1),
	glm::vec4(0.0,0.772727,-0.454545, 1),
	glm::vec4(-0.229091,0.772727,-0.409091, 1),
	glm::vec4(-0.409091,0.772727,-0.229091, 1),
	glm::vec4(-0.409091,0.772727,0.0, 1),
	glm::vec4(-0.229091,0.886364,-0.409091, 1),
	glm::vec4(-0.409091,0.886364,-0.229091, 1),
	glm::vec4(-0.409091,0.886364,0.0, 1),
	glm::vec4(-0.254545,0.886364,-0.454545, 1),
	glm::vec4(-0.454545,0.886364,-0.254545, 1),
	glm::vec4(-0.454545,0.886364,0.0, 1),
	glm::vec4(-0.254545,0.772727,-0.454545, 1),
	glm::vec4(-0.454545,0.772727,-0.254545, 1),
	glm::vec4(-0.454545,0.772727,0.0, 1),
	glm::vec4(-0.409091,0.772727,0.229091, 1),
	glm::vec4(-0.229091,0.772727,0.409091, 1),
	glm::vec4(0.0,0.772727,0.409091, 1),
	glm::vec4(-0.409091,0.886364,0.229091, 1),
	glm::vec4(-0.229091,0.886364,0.409091, 1),
	glm::vec4(0.0,0.886364,0.409091, 1),
	glm::vec4(-0.454545,0.886364,0.254545, 1),
	glm::vec4(-0.254545,0.886364,0.454545, 1),
	glm::vec4(0.0,0.886364,0.454545, 1),
	glm::vec4(-0.454545,0.772727,0.254545, 1),
	glm::vec4(-0.254545,0.772727,0.454545, 1),
	glm::vec4(0.0,0.772727,0.454545, 1),
	glm::vec4(0.229091,0.772727,0.409091, 1),
	glm::vec4(0.409091,0.772727,0.229091, 1),
	glm::vec4(0.229091,0.886364,0.409091, 1),
	glm::vec4(0.409091,0.886364,0.229091, 1),
	glm::vec4(0.254545,0.886364,0.454545, 1),
	glm::vec4(0.454545,0.886364,0.254545, 1),
	glm::vec4(0.254545,0.772727,0.454545, 1),
	glm::vec4(0.454545,0.772727,0.254545, 1),
	glm::vec4(0.454545,0.545455,0.0, 1),
	glm::vec4(0.454545,0.545455,-0.254545, 1),
	glm::vec4(0.254545,0.545455,-0.454545, 1),
	glm::vec4(0.0,0.545455,-0.454545, 1),
	glm::vec4(0.454545,0.272727,0.0, 1),
	glm::vec4(0.454545,0.272727,-0.254545, 1),
	glm::vec4(0.254545,0.272727,-0.454545, 1),
	glm::vec4(0.0,0.272727,-0.454545, 1),
	glm::vec4(0.318182,0.0454545,0.0, 1),
	glm::vec4(0.318182,0.0454545,-0.178182, 1),
	glm::vec4(0.178182,0.0454545,-0.318182, 1),
	glm::vec4(0.0,0.0454545,-0.318182, 1),
	glm::vec4(-0.254545,0.545455,-0.454545, 1),
	glm::vec4(-0.454545,0.545455,-0.254545, 1),
	glm::vec4(-0.454545,0.545455,0.0, 1),
	glm::vec4(-0.254545,0.272727,-0.454545, 1),
	glm::vec4(-0.454545,0.272727,-0.254545, 1),
	glm::vec4(-0.454545,0.272727,0.0, 1),
	glm::vec4(-0.178182,0.0454545,-0.318182, 1),
	glm::vec4(-0.318182,0.0454545,-0.178182, 1),
	glm::vec4(-0.318182,0.0454545,0.0, 1),
	glm::vec4(-0.454545,0.545455,0.254545, 1),
	glm::vec4(-0.254545,0.545455,0.454545, 1),
	glm::vec4(0.0,0.545455,0.454545, 1),
	glm::vec4(-0.454545,0.272727,0.254545, 1),
	glm::vec4(-0.254545,0.272727,0.454545, 1),
	glm::vec4(0.0,0.272727,0.454545, 1),
	glm::vec4(-0.318182,0.0454545,0.178182, 1),
	glm::vec4(-0.178182,0.0454545,0.318182, 1),
	glm::vec4(0.0,0.0454545,0.318182, 1),
	glm::vec4(0.254545,0.545455,0.454545, 1),
	glm::vec4(0.454545,0.545455,0.254545, 1),
	glm::vec4(0.254545,0.272727,0.454545, 1),
	glm::vec4(0.454545,0.272727,0.254545, 1),
	glm::vec4(0.178182,0.0454545,0.318182, 1),
	glm::vec4(0.318182,0.0454545,0.178182, 1),
	glm::vec4(0.545455,0.0454545,0.0, 1),
	glm::vec4(0.545455,0.0454545,-0.305455, 1),
	glm::vec4(0.305455,0.0454545,-0.545455, 1),
	glm::vec4(0.0,0.0454545,-0.545455, 1),
	glm::vec4(0.727273,0.136364,0.0, 1),
	glm::vec4(0.727273,0.136364,-0.407273, 1),
	glm::vec4(0.407273,0.136364,-0.727273, 1),
	glm::vec4(0.0,0.136364,-0.727273, 1),
	glm::vec4(0.909091,0.136364,0.0, 1),
	glm::vec4(0.909091,0.136364,-0.509091, 1),
	glm::vec4(0.509091,0.136364,-0.909091, 1),
	glm::vec4(0.0,0.136364,-0.909091, 1),
	glm::vec4(-0.305455,0.0454545,-0.545455, 1),
	glm::vec4(-0.545455,0.0454545,-0.305455, 1),
	glm::vec4(-0.545455,0.0454545,0.0, 1),
	glm::vec4(-0.407273,0.136364,-0.727273, 1),
	glm::vec4(-0.727273,0.136364,-0.407273, 1),
	glm::vec4(-0.727273,0.136364,0.0, 1),
	glm::vec4(-0.509091,0.136364,-0.909091, 1),
	glm::vec4(-0.909091,0.136364,-0.509091, 1),
	glm::vec4(-0.909091,0.136364,0.0, 1),
	glm::vec4(-0.545455,0.0454545,0.305455, 1),
	glm::vec4(-0.305455,0.0454545,0.545455, 1),
	glm::vec4(0.0,0.0454545,0.545455, 1),
	glm::vec4(-0.727273,0.136364,0.407273, 1),
	glm::vec4(-0.407273,0.136364,0.727273, 1),
	glm::vec4(0.0,0.136364,0.727273, 1),
	glm::vec4(-0.909091,0.136364,0.509091, 1),
	glm::vec4(-0.509091,0.136364,0.909091, 1),
	glm::vec4(0.0,0.136364,0.909091, 1),
	glm::vec4(0.305455,0.0454545,0.545455, 1),
	glm::vec4(0.545455,0.0454545,0.305455, 1),
	glm::vec4(0.407273,0.136364,0.727273, 1),
	glm::vec4(0.727273,0.136364,0.407273, 1),
	glm::vec4(0.509091,0.136364,0.909091, 1),
	glm::vec4(0.909091,0.136364,0.509091, 1),
	glm::vec4(1.0,0.136364,0.0, 1),
	glm::vec4(1.0,0.136364,-0.56, 1),
	glm::vec4(0.56,0.136364,-1.0, 1),
	glm::vec4(0.0,0.136364,-1.0, 1),
	glm::vec4(1.0,0.0909091,0.0, 1),
	glm::vec4(1.0,0.0909091,-0.56, 1),
	glm::vec4(0.56,0.0909091,-1.0, 1),
	glm::vec4(0.0,0.0909091,-1.0, 1),
	glm::vec4(0.909091,0.0909091,0.0, 1),
	glm::vec4(0.909091,0.0909091,-0.509091, 1),
	glm::vec4(0.509091,0.0909091,-0.909091, 1),
	glm::vec4(0.0,0.0909091,-0.909091, 1),
	glm::vec4(-0.56,0.136364,-1.0, 1),
	glm::vec4(-1.0,0.136364,-0.56, 1),
	glm::vec4(-1.0,0.136364,0.0, 1),
	glm::vec4(-0.56,0.0909091,-1.0, 1),
	glm::vec4(-1.0,0.0909091,-0.56, 1),
	glm::vec4(-1.0,0.0909091,0.0, 1),
	glm::vec4(-0.509091,0.0909091,-0.909091, 1),
	glm::vec4(-0.909091,0.0909091,-0.509091, 1),
	glm::vec4(-0.909091,0.0909091,0.0, 1),
	glm::vec4(-1.0,0.136364,0.56, 1),
	glm::vec4(-0.56,0.136364,1.0, 1),
	glm::vec4(0.0,0.136364,1.0, 1),
	glm::vec4(-1.0,0.0909091,0.56, 1),
	glm::vec4(-0.56,0.0909091,1.0, 1),
	glm::vec4(0.0,0.0909091,1.0, 1),
	glm::vec4(-0.909091,0.0909091,0.509091, 1),
	glm::vec4(-0.509091,0.0909091,0.909091, 1),
	glm::vec4(0.0,0.0909091,0.909091, 1),
	glm::vec4(0.56,0.136364,1.0, 1),
	glm::vec4(1.0,0.136364,0.56, 1),
	glm::vec4(0.56,0.0909091,1.0, 1),
	glm::vec4(1.0,0.0909091,0.56, 1),
	glm::vec4(0.509091,0.0909091,0.909091, 1),
	glm::vec4(0.909091,0.0909091,0.509091, 1),
	glm::vec4(0.727273,0.0909091,0.0, 1),
	glm::vec4(0.727273,0.0909091,-0.407273, 1),
	glm::vec4(0.407273,0.0909091,-0.727273, 1),
	glm::vec4(0.0,0.0909091,-0.727273, 1),
	glm::vec4(0.545455,0.0,0.0, 1),
	glm::vec4(0.545455,0.0,-0.305455, 1),
	glm::vec4(0.305455,0.0,-0.545455, 1),
	glm::vec4(0.0,0.0,-0.545455, 1),
	glm::vec4(0.318182,0.0,0.0, 1),
	glm::vec4(0.318182,0.0,-0.178182, 1),
	glm::vec4(0.178182,0.0,-0.318182, 1),
	glm::vec4(0.0,0.0,-0.318182, 1),
	glm::vec4(-0.407273,0.0909091,-0.727273, 1),
	glm::vec4(-0.727273,0.0909091,-0.407273, 1),
	glm::vec4(-0.727273,0.0909091,0.0, 1),
	glm::vec4(-0.305455,0.0,-0.545455, 1),
	glm::vec4(-0.545455,0.0,-0.305455, 1),
	glm::vec4(-0.545455,0.0,0.0, 1),
	glm::vec4(-0.178182,0.0,-0.318182, 1),
	glm::vec4(-0.318182,0.0,-0.178182, 1),
	glm::vec4(-0.318182,0.0,0.0, 1),
	glm::vec4(-0.727273,0.0909091,0.407273, 1),
	glm::vec4(-0.407273,0.0909091,0.727273, 1),
	glm::vec4(0.0,0.0909091,0.727273, 1),
	glm::vec4(-0.545455,0.0,0.305455, 1),
	glm::vec4(-0.305455,0.0,0.545455, 1),
	glm::vec4(0.0,0.0,0.545455, 1),
	glm::vec4(-0.318182,0.0,0.178182, 1),
	glm::vec4(-0.178182,0.0,0.318182, 1),
	glm::vec4(0.0,0.0,0.318182, 1),
	glm::vec4(0.407273,0.0909091,0.727273, 1),
	glm::vec4(0.727273,0.0909091,0.407273, 1),
	glm::vec4(0.305455,0.0,0.545455, 1),
	glm::vec4(0.545455,0.0,0.305455, 1),
	glm::vec4(0.178182,0.0,0.318182, 1),
	glm::vec4(0.318182,0.0,0.178182, 1),
	glm::vec4(0.272727,0.0454545,0.0, 1),
	glm::vec4(0.272727,0.0454545,-0.152727, 1),
	glm::vec4(0.152727,0.0454545,-0.272727, 1),
	glm::vec4(0.0,0.0454545,-0.272727, 1),
	glm::vec4(0.409091,0.272727,0.0, 1),
	glm::vec4(0.409091,0.272727,-0.229091, 1),
	glm::vec4(0.229091,0.272727,-0.409091, 1),
	glm::vec4(0.0,0.272727,-0.409091, 1),
	glm::vec4(0.409091,0.545455,0.0, 1),
	glm::vec4(0.409091,0.545455,-0.229091, 1),
	glm::vec4(0.229091,0.545455,-0.409091, 1),
	glm::vec4(0.0,0.545455,-0.409091, 1),
	glm::vec4(-0.152727,0.0454545,-0.272727, 1),
	glm::vec4(-0.272727,0.0454545,-0.152727, 1),
	glm::vec4(-0.272727,0.0454545,0.0, 1),
	glm::vec4(-0.229091,0.272727,-0.409091, 1),
	glm::vec4(-0.409091,0.272727,-0.229091, 1),
	glm::vec4(-0.409091,0.272727,0.0, 1),
	glm::vec4(-0.229091,0.545455,-0.409091, 1),
	glm::vec4(-0.409091,0.545455,-0.229091, 1),
	glm::vec4(-0.409091,0.545455,0.0, 1),
	glm::vec4(-0.272727,0.0454545,0.152727, 1),
	glm::vec4(-0.152727,0.0454545,0.272727, 1),
	glm::vec4(0.0,0.0454545,0.272727, 1),
	glm::vec4(-0.409091,0.272727,0.229091, 1),
	glm::vec4(-0.229091,0.272727,0.409091, 1),
	glm::vec4(0.0,0.272727,0.409091, 1),
	glm::vec4(-0.409091,0.545455,0.229091, 1),
	glm::vec4(-0.229091,0.545455,0.409091, 1),
	glm::vec4(0.0,0.545455,0.409091, 1),
	glm::vec4(0.152727,0.0454545,0.272727, 1),
	glm::vec4(0.272727,0.0454545,0.152727, 1),
	glm::vec4(0.229091,0.272727,0.409091, 1),
	glm::vec4(0.409091,0.272727,0.229091, 1),
	glm::vec4(0.229091,0.545455,0.409091, 1),
	glm::vec4(0.409091,0.545455,0.229091, 1),
	glm::vec4(-0.454545,0.704545,0.0, 1),
	glm::vec4(-0.454545,0.704545,-0.0454545, 1),
	glm::vec4(-0.454545,0.772727,-0.0454545, 1),
	glm::vec4(-0.772727,0.863636,0.0, 1),
	glm::vec4(-0.772727,0.863636,-0.0454545, 1),
	glm::vec4(-0.818182,0.954545,-0.0454545, 1),
	glm::vec4(-0.818182,0.954545,0.0, 1),
	glm::vec4(-0.772727,0.522727,0.0, 1),
	glm::vec4(-0.772727,0.522727,-0.0454545, 1),
	glm::vec4(-0.909091,0.477273,-0.0454545, 1),
	glm::vec4(-0.909091,0.477273,0.0, 1),
	glm::vec4(-0.409091,0.363636,0.0, 1),
	glm::vec4(-0.409091,0.363636,-0.0454545, 1),
	glm::vec4(-0.409091,0.295455,-0.0454545, 1),
	glm::vec4(-0.409091,0.295455,0.0, 1),
	glm::vec4(-0.454545,0.772727,0.0454545, 1),
	glm::vec4(-0.454545,0.704545,0.0454545, 1),
	glm::vec4(-0.818182,0.954545,0.0454545, 1),
	glm::vec4(-0.772727,0.863636,0.0454545, 1),
	glm::vec4(-0.909091,0.477273,0.0454545, 1),
	glm::vec4(-0.772727,0.522727,0.0454545, 1),
	glm::vec4(-0.409091,0.295455,0.0454545, 1),
	glm::vec4(-0.409091,0.363636,0.0454545, 1)
};

TeaCup::TeaCup(GLuint vertexPositionAttribLocation, GLuint modelUniformLocation, GLuint colorUniformLocation)
{
	this->modelUniformLocation = modelUniformLocation;
	this->vertexPositionAttribLocation = vertexPositionAttribLocation;
	this->colorUniformLocation = colorUniformLocation;

	showControlPoints = false;

	initPatches();

	initPoints();
}

void TeaCup::display()
{
	// displaying the patches
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	glUniform4fv(colorUniformLocation, 1, glm::value_ptr(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)));
	glUniformMatrix4fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(model));

	for (int i = 0; i < patches->size(); i++) {
		(*patches)[i]->display();
	}

	// displaying the control points

	if (showControlPoints) {
		glUniform4fv(colorUniformLocation, 1, glm::value_ptr(glm::vec4(0.0f, 0.5f, 0.0f, 1.0f)));

		glBindVertexArray(pointsVAO);

		glPointSize(3.0f);
		glDrawArrays(GL_POINTS, 0, numOfVertices);

		glBindVertexArray(0);

		glUniform4fv(colorUniformLocation, 1, glm::value_ptr(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)));
	}

	glUniformMatrix4fv(modelUniformLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
}

// set to true to show control points
void TeaCup::setShowControlPoints(bool show)
{
	showControlPoints = show;
}

TeaCup::~TeaCup()
{
}

// initialize all patches
void TeaCup::initPatches()
{
	patches = new std::vector<Patch*>();

	int count = 0;
	for (int i = 0; i < numOfPatches; i++) {
		glm::vec3 cps[16];
		for (int j = 0; j < 16; j++) {
			int currIndex = indices[count];

			cps[j] = vertices[currIndex - 1];

			count++;
		}

		glm::mat4 px(
			cps[0].x, cps[1].x, cps[2].x, cps[3].x,
			cps[4].x, cps[5].x, cps[6].x, cps[7].x,
			cps[8].x, cps[9].x, cps[10].x, cps[11].x,
			cps[12].x, cps[13].x, cps[14].x, cps[15].x
		);

		glm::mat4 py(
			cps[0].y, cps[1].y, cps[2].y, cps[3].y,
			cps[4].y, cps[5].y, cps[6].y, cps[7].y,
			cps[8].y, cps[9].y, cps[10].y, cps[11].y,
			cps[12].y, cps[13].y, cps[14].y, cps[15].y
		);

		glm::mat4 pz(
			cps[0].z, cps[1].z, cps[2].z, cps[3].z,
			cps[4].z, cps[5].z, cps[6].z, cps[7].z,
			cps[8].z, cps[9].z, cps[10].z, cps[11].z,
			cps[12].z, cps[13].z, cps[14].z, cps[15].z
		);

		patches->push_back(new Patch(px, py, pz, vertexPositionAttribLocation));
	}
}

// initialize all control points
void TeaCup::initPoints()
{
	glGenVertexArrays(1, &pointsVAO);
	glBindVertexArray(pointsVAO);

	glGenBuffers(1, &pointsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, pointsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vertexPositionAttribLocation);
	glVertexAttribPointer(vertexPositionAttribLocation, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	// unbinding
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
