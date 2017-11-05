#include "Display.h"
#include <fstream>

const string Display::windowName = "Project Miez";
Craftian *Display::robot = nullptr;
int Display::windowWidth = 800;
int Display::windowHeight = 600;
int Display::iSkin = 0;
std::vector<GLuint> Display::dbTex;

void Display::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	robot->draw();
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
	switch (key)
	{
	case'x': robot->setSkin((++iSkin) >= dbTex.size() ? dbTex[iSkin = dbTex.size()-1] : dbTex[iSkin], 64); break;
	case'z': robot->setSkin((--iSkin) < 0 ? dbTex[iSkin = 0] : dbTex[iSkin], 64); break;
	}
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
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //GLUT_MULTISAMPLE anti-aliasing
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(windowName.c_str());

	//enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//clear color and depth
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClearDepth(1.0f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND); //For Transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keydown);
	glutKeyboardUpFunc(keyup);
	glutTimerFunc(16, timer, 0);

	glewInit();
	for (int i = 0;; ++i)
	{
		std::string dir = "res\\skin\\";
		dir += to_string(i) + ".png";
		std::fstream fs(dir, std::fstream::in);
		if (!fs) {
			printf("%d\n", i); break;
		}
		char *buf = new char[dir.length() + 1];
		std::strcpy(buf, dir.c_str());
		dbTex.push_back(Texture::GenTexture(buf));
		delete buf;
	}
	if (dbTex.empty()) throw std::runtime_error("No texture file available");
	robot = new Craftian(dbTex[0], 64);
}


void Display::main_loop()
{
	glutMainLoop();
}