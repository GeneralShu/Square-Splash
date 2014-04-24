#include "score.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>


score::score()
{
	points = 0;
	name = "Template";
}


score::~score()
{
}

void score::calculateScore(int crashCounter)
{
	if (crashCounter >= 3)
		this->points = points + crashCounter * (60 * (crashCounter - 2));
}

void score::paint(ALLEGRO_FONT *font)
{
	char temp[10];
	_itoa_s(points, temp, 10);
	al_draw_text(font, al_map_rgb(255, 255, 255), 700, 20, 0, "SCORE: ");
	al_draw_text(font, al_map_rgb(255, 255, 255), 835, 20, 0, temp);
}

void score::zeroPoints()
{
	points = 0;
}