#include "App.h"
#include <fstream>
#include "Texture.h"
#include <vgl.h>

App::App() :iSkin(0), robot(nullptr){}

void App::init()
{
	Display::init();
	Input::init();
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

void App::start()
{
	glutMainLoop();
}

void App::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	robot->draw();
	glPopMatrix();
	glutSwapBuffers();
}

void App::timer()
{
	float moveX = 0, moveY = 0;
	//Coordinate system with respect to Craftian
	if (Input::isKeyPress('w')) moveY += 1;
	if (Input::isKeyPress('a')) moveX += 1;
	if (Input::isKeyPress('s')) moveY -= 1;
	if (Input::isKeyPress('d')) moveX -= 1;
	if(moveX != 0 || moveY != 0) robot->move(moveX, moveY);
	glutPostRedisplay();
}

bool yawLock = 1;
void App::keyDown(int key)
{
	switch (key)
	{
	case'x': robot->setSkin((++iSkin) >= dbTex.size() ? dbTex[iSkin = dbTex.size() - 1] : dbTex[iSkin], 64); break;
	case'z': robot->setSkin((--iSkin) < 0 ? dbTex[iSkin = 0] : dbTex[iSkin], 64); break;
	case 'c': 
		if (!mouseLock)
		{
			mouseLock = 1, glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(Display::windowWidth / 2, Display::windowHeight / 2);
			yawLock = 0;
		}
		else
		{mouseLock = 0, yawLock = 1, glutSetCursor(GLUT_CURSOR_LEFT_ARROW);}
	}
}
float lastX, lastY;
void App::moveMouse(int x, int y)
{
	if (mouseLock) {
		if (!yawLock)
		{
			if (x - 50 < 0 || y - 50 < 0 || x + 50 > windowWidth || y + 50 > windowHeight)
			{
				yawLock = 1;
				glutWarpPointer(Display::windowWidth / 2, Display::windowHeight / 2);
			}
			else robot->changeYaw(x - lastX);
		}
		else yawLock = 0;
		lastX = x;
		lastY = y;
	}
}