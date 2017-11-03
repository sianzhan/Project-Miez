#pragma once
#include <string>
using namespace std;
class Display
{
private:
	const static std::string windowName;
	static int windowWidth;
	static int windowHeight;
	static void draw();
	static void reshape(int, int);
	static void keydown(unsigned char, int, int);
	static void keyup(unsigned char, int, int);
	static void timer(int);
public:
	static void init(int, char*[]);
	static void main_loop();
};
