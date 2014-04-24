#include "superBrick.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>

#define WIDTH 8
#define LENGTH 8
#define BRICKSIZE 85
#define STARTXTABLE 5
#define STARTYTABLE 5


superBrick::superBrick()
{
}


superBrick::~superBrick()
{
}

void superBrick::paint(int y, int x)
{
	int localR = R, localB = B, localG = G;
	for (int i = 0; i <= BRICKSIZE - 5 - STARTYTABLE; i++)
	{
		if (localR > 0)
			localR = localR - 2;
		if (localB > 0)
			localB = localB - 2;
		if (localG > 0)
			localG = localG - 2;
		al_draw_line(STARTXTABLE + 5 + x * BRICKSIZE, i + STARTYTABLE + 5 + y * BRICKSIZE, x * BRICKSIZE + BRICKSIZE, i + STARTYTABLE + 5 + y * BRICKSIZE, al_map_rgb(localR, localG, localB), 1);
	}
	al_draw_line(STARTXTABLE + 5 + x * BRICKSIZE, STARTYTABLE + 5 + y * BRICKSIZE, x * BRICKSIZE + BRICKSIZE, STARTYTABLE + 5 + y * BRICKSIZE, al_map_rgb(0, 0, 0), 5);
}