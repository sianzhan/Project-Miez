//Display encapsulation

#pragma once
#include "Texture.h"
#include "Craftian/Craftian.h"
#include <string>
using namespace std;
class Display
{
private:
	static Craftian *robot;
	static int iSkin;
	const static std::string windowName;
	static int windowWidth;
	static int windowHeight;
	static void draw();
	static void reshape(int, int);
	static void keydown(unsigned char, int, int);
	static void keyup(unsigned char, int, int);
	static void timer(int);
	static std::vector<GLuint> dbTex;
public:
	static void init(int, char*[]);
	static void main_loop();
};
