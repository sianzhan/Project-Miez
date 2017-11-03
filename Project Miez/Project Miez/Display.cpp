#include "Display.h"
#include "Craftian/Craftian.h"
#include <GLUT/glut.h>

const string Display::windowName = "Project Miez";
int Display::windowWidth = 800;
int Display::windowHeight = 600;

void Display::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	Craftian robot;
	robot.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void Display::reshape(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	if (windowHeight <= 0)
	{
		windowHeight = 1;
	}

	//calculate aspect ratio for perspective projection
	float aspect = (float)windowWidth / (float)windowHeight;

	//set projection matrix to perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.3f, 1000.0f);

	//set view matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 1.0f, //eye(camera) position
		0.0f, 0.0f, 0.0f, //look direction
		0.0f, 1.0f, 0.0f);//up direction
}

void Display::keydown(unsigned char key, int, int)
{

}

void Display::keyup(unsigned char key, int, int)
{

}

void Display::timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void Display::init(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_MULTISAMPLE); //GLUT_MULTISAMPLE anti-aliasing
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(windowName.c_str());
	glShadeModel(GL_SMOOTH);

	//enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//clear color and depth
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClearDepth(1.0f);

	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keydown);
	glutKeyboardUpFunc(keyup);
	glutTimerFunc(16, timer, 0);
}


void Display::main_loop()
{
	glutMainLoop();
}