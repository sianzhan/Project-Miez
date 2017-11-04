#include <stdio.h>
#include "Display.h"
#include "Texture.h"
#include "Craftian/CraftBody.h"
#include "stdio.h"
int main(int argc, char *argv[])
{ 
	printf("Hey, starts working NOW!\n"); 
	Display::init(argc, argv);
	CraftBody::init();
	Display::main_loop();
	return 0;
}