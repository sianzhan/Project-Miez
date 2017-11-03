#include <stdio.h>
#include "Display.h"


int main(int argc, char *argv[])
{ 
	printf("Hey, starts working NOW!\n"); 

	Display::init(argc, argv);
	Display::main_loop();

	return 0;
}