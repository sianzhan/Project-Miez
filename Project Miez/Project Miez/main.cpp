#include <stdio.h>
#include "Texture.h"
#include "App.h"
#include "stdio.h"
int main(int argc, char *argv[])
{ 
	printf("Hey, starts working NOW!\n"); 
	App app;
	app.init();
	app.start();
	return 0;
}