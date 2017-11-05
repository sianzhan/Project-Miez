#include "Input.h"
#include <algorithm>
#include <vgl.h>
Input::Input(void)
{
	std::fill_n(m_Keyboard, sizeof(bool) * 256, 0);
}


Input::~Input(void)
{
}

Input * Input::target_input = nullptr;
void Input::KeyboardFunc(unsigned char key, int x, int y)
{
	target_input->Input_Keyboard(key, true);
}

void Input::KeyboardUpFunc(unsigned char key, int x, int y)
{
	target_input->Input_Keyboard(key, false);
}

void Input::SKeyboardFunc(int key, int x, int y)
{
	target_input->Input_Keyboard(key, true);
}

void Input::SKeyboardUpFunc(int key, int x, int y)
{
	target_input->Input_Keyboard(key, false);
}

void Input::MouseFunc(int button, int state, int x, int y)
{
	target_input->inputMouse(button, state, x, y);
}

void Input::MotionFunc(int x, int y)
{
	target_input->inputMouse(0, 0, x, y);
}

void Input::PassiveMotionFunc(int x, int y)
{
	target_input->moveMouse(x, y);
}

/////////////////////////////////////////////////////////////////////////

void Input::init()
{
	target_input = this;

	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SKeyboardFunc);
	glutSpecialUpFunc(SKeyboardUpFunc);
	glutMouseFunc(MouseFunc);
	glutMotionFunc(MotionFunc);
	glutPassiveMotionFunc(PassiveMotionFunc);
}

void Input::Input_Keyboard(int key, bool status)
{
	if (status)
	{
		if (!m_Keyboard[key])keyDown(key);
		else keyPress(key);
		m_Keyboard[key] = true;
	}
	else {
		keyUp(key);
		m_Keyboard[key] = false;
	}
}

void Input::keyUp(int key)
{
	glutPostRedisplay();
}

void Input::keyDown(int key)
{
	switch (key) {
	case KEY_ESC:
		glutLeaveMainLoop();
		break;
	case KEY_F4:
		glutFullScreenToggle();
		break;
	}
	glutPostRedisplay();
}

void Input::keyPress(int key)
{
	glutPostRedisplay();
}

void Input::inputMouse(int button, int state, int x, int y)
{
	glutPostRedisplay();
}