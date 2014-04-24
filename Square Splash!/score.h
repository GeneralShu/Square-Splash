#pragma once
#include "gameGraphics.h"
#include <allegro5/allegro_font.h>

class score :
	public gameGraphics
{
private:
	int points;
	char* name;
public:
	score();
	~score();
	void calculateScore(int crashCounter);
	void paint(ALLEGRO_FONT* font);
	void zeroPoints();
};
