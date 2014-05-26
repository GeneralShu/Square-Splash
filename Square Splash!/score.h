#pragma once
#include <fstream>
#include <iostream>
#include "gameGraphics.h"
#include <allegro5/allegro_font.h>

using namespace std;

class score :
	public gameGraphics
{
private:
	int points;
	void addScore(int temp){ points = temp; }
public:
	score();
	score(int points);
	~score();
	void calculateScore(int crashCounter);
	void paint(ALLEGRO_FONT* font);
	void zeroPoints();
	int retrunPoints();
	bool operator < (const score &ob) const;
	friend ifstream& operator >> (ifstream& in, score &h);
	friend ofstream& operator << (ofstream& out, score &h);
};

