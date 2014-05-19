#include "brick.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>

#define WIDTH 8
#define LENGTH 8
#define BRICKSIZE 85
#define STARTXTABLE 5
#define STARTYTABLE 5

brick::brick()
{
	ifDelete = false;
	R = 0; 
	B = 0; 
	G = 0;
}

void brick::randomColor()
{
	int randomize;
	{
		randomize = rand() % 6;
		switch (randomize)
		{
		case 0: //czerwony
			R = 204;
			G = 0;
			B = 0;
			break;
		case 1: //zielony
			R = 0;
			G = 204;
			B = 0;
			break;
		case 2: //niebieski
			R = 0;
			G = 76;
			B = 255;
			break;
		case 3: //pomaranczowy
			R = 255;
			G = 128;
			B = 0;
			break;
		case 4: //zolty
			R = 255;
			G = 255;
			B = 0;
			break;
		case 5: //rozowy
			R = 255;
			G = 102;
			B = 255;
			break;
		}
	}
}


brick::~brick()
{
}

void brick::paint(int y, int x)
{
	int localR = R, localB = B, localG = G;
	for (int i = 0; i <= BRICKSIZE - 5 - STARTYTABLE; i++)
	{
		if (localR > 0)
			localR = localR - 1;
		if (localB > 0)
			localB = localB - 1;
		if (localG > 0)
			localG = localG - 1;
		al_draw_line(STARTXTABLE + 5 + x * BRICKSIZE, i + STARTYTABLE + 5 + y * BRICKSIZE, x * BRICKSIZE + BRICKSIZE, i + STARTYTABLE + 5 + y * BRICKSIZE, al_map_rgb(localR, localG, localB), 1);
	}
}

bool brick::operator == (const brick &ob) const
{
	if ((this->R == ob.R) && (this->G == ob.G) && (this->B == ob.B)) return true;
	else return false;
}

void brick::swapBricks(brick &ob)
{
	brick temp;

	temp.R = this->R;
	temp.G = this->G;
	temp.B = this->B;

	this->B = ob.B;
	this->R = ob.R;
	this->G = ob.G;

	ob.B = temp.B;
	ob.R = temp.R;
	ob.G = temp.G;
}

void brick::setDelete()
{
	ifDelete = true;
}

void brick::setBlack()
{
	this->R = 0;
	this->G = 0;
	this->B = 0;
}


void brick::set()
{
	ifDelete = false;
}

int brick::ifBlack()
{
	if (this->B == 0 && this->R == 0 && this->G == 0) 
		return 1;
	else
		return 0;
}

int brick::ifToPaint()
{
	if (this->ifDelete == true)
		return 1;
	else
		return 0;
}