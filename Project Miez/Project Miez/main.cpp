#include <stdio.h>
#include "Texture.h"
#include "Display.h"
#include "Craftian/CraftBody.h"
#include "stdio.h"
int main(int argc, char *argv[])
{ 
	printf("Hey, starts working NOW!\n"); 
	Display::init(argc, argv);
	Display::main_loop();
	return 0;
}