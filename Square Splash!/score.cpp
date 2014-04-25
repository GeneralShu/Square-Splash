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

score::score(int points) : points(points){}

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
	al_draw_text(font, al_map_rgb(255, 255, 255), 700, 80, 0, "SCORE: ");
	al_draw_text(font, al_map_rgb(255, 255, 255), 835, 80, 0, temp);
}

int score::retrunPoints()
{
	return points;
}
void score::zeroPoints()
{
	points = 0;
}

bool score::operator < (const score &ob) const
{
	if (this->points < ob.points)
		return true;
	else
		return false;
}