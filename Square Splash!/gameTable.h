#pragma once
#include "brick.h"
#include "gameGraphics.h"
#include "score.h"


class gameTable : public gameGraphics
{
private:
	brick** table;
public:
	gameTable();
	~gameTable();
	void swapOnTable(int x1, int y1, int x2, int y2);
	void paint(int CordX, int cordY);
	void setBlack();
	int checkColision(int x, int y);
	int checkVerticalColision(int x, int y);
	int checkHorizontalColision(int x, int y);
	void setVertical(int x, int y, int counter);
	void setHorizontal(int x, int y, int counter);
	void fallBricks();
	bool fillTable();
	void setBonuses(int maxBonus);
};

