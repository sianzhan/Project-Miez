#include "App.h"
#include <fstream>
#include "Texture.h"
#include <vgl.h>

App::App() :iSkin(0), robot(nullptr){}

void App::init()
{
	srand(time(nullptr));
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
#define FLOOR_SIZE 500
#define WIDTH_RATIO 1

void drawFloor() {
	glBegin(GL_QUADS);

	glColor4f(1, 1, 1, 0.7f);
	//Floor
	glNormal3f(0, 1, 0);
	glVertex3f(-FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2); //Top Left
	glVertex3f(-FLOOR_SIZE / WIDTH_RATIO, 0, FLOOR_SIZE / WIDTH_RATIO); //Btm Left
	glVertex3f(FLOOR_SIZE / WIDTH_RATIO, 0, FLOOR_SIZE / WIDTH_RATIO); //Btm Right
	glVertex3f(FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2); //Top Right

	glEnd();
}

void App::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	GLfloat bAmb = 1.0;
	GLfloat bDiff = 1.0;
	GLfloat bSpec = 1.0;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (!day)
	{
		bAmb = bDiff = bSpec = 0;
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		if (sai) glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	}else glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	GLfloat lightPosition[] = { robot->getPos().x, 1.0f, robot->getPos().y, 1.0f };
	GLfloat lightAmbient[] = { bAmb, bAmb, bAmb, 1.0f };
	GLfloat lightDiffuse[] = { bDiff, bDiff, bDiff, 1.0f };
	GLfloat lightSpecular[] = { bSpec, bSpec, bSpec, 1.0f };

	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);

	glPushMatrix();
		glTranslatef(0, -0.4, 0);
		glEnable(GL_STENCIL_TEST);
		glDisable(GL_DEPTH_TEST); //Disable Depth test so that the floor wont cover up the Cube image
		glStencilFunc(GL_ALWAYS, 1, 0xff);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		glColorMask(0, 0, 0, 0);
		glDisable(GL_BLEND);
		drawFloor();
		glColorMask(1, 1, 1, 1);
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glStencilFunc(GL_EQUAL, 1, 0xff);
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

		glScalef(1, -1, 1);
		robot->draw();
		glDisable(GL_STENCIL_TEST);
		glDisable(GL_TEXTURE_2D);
		drawFloor();
		glEnable(GL_TEXTURE_2D);

	glPopMatrix();
	glPushMatrix();
		robot->update();
		glTranslatef(0, -0.4, 0);
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
	robot->move(moveX, moveY);
	glutPostRedisplay();
}

bool yawLock = 1;
float lastX, lastY;
void App::keyDown(int key)
{
	switch (key)
	{
	case'x': robot->setSkin((++iSkin) >= dbTex.size() ? dbTex[iSkin = dbTex.size() - 1] : dbTex[iSkin], 64); break;
	case'z': robot->setSkin((--iSkin) < 0 ? dbTex[iSkin = 0] : dbTex[iSkin], 64); break;
	case'b':
		robot->toggleAnimation(Skeleton::BOW);
		break;
	case'n':
		robot->toggleAnimation(Skeleton::SIT);
		break;
	case 'm':
		robot->toggleAnimation(Skeleton::SOMERSAULT);
		break;
	case 'g':
		robot->toggleAnimation(Skeleton::DA);
		break;
	case 'f':
		robot->toggleSword();
		break;
	case'h':
		robot->animate(Skeleton::PLACE_HEAD);
		robot->headStack();
		break;
	case'j':
		robot->headPop();
		break;
	case 'v':
		robot->animate(Skeleton::MEOW);
		break;
	case 'c':
		if (!mouseLock)
		{
			mouseLock = 1, yawLock = 1, glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(Display::windowWidth / 2, Display::windowHeight / 2);
			lastX = Display::windowWidth / 2, lastY = Display::windowHeight / 2;
			yawLock = 0;
		}
		else
		{
			mouseLock = 0, glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
		break;
	case KEY_SPACE:
		robot->jump();
		break;

	case KEY_ESC:
		if (mouseLock) mouseLock = 0, glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		else glutLeaveMainLoop();
		break;
	case '1':
		robot->toggleAnimation(Skeleton::HELLO);
		break;
	case '2':
		robot->toggleAnimation(Skeleton::DANCE);
		break;
	case'3':
		robot->toggleAnimation(Skeleton::GANGNAM);
		break;
	case'4':

		break;
	case 'q':
		day = (day + 1) % 2;
		break;
	case 'e':
		sai = (sai + 1) % 2;
		break;
	}
}
int counter = 0;
void App::inputMouse(int button, int state, int x, int y)
{
	switch (button)
	{
		case LEFT:
			robot->animate(Skeleton::WAVEHAND_R);
			robot->effect(++counter);
			break;
		case RIGHT:
			robot->animate(Skeleton::WAVEHAND_L);
			robot->effect(--counter);
			break;
		case MIDDLE:
			break;
		default:;
	}
}

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
			else
			{
				robot->changeYaw(x - lastX);
				robot->changePitch(y - lastY);
			}
		}
		else yawLock = 0;
		lastX = x;
		lastY = y;
	}
}