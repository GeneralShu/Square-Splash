#pragma once
#include "gameGraphics.h"


class brick 
	: public gameGraphics
{
protected:
	int R, G, B;
	bool ifDelete;
public:
	brick();
	void randomColor();
	virtual ~brick();
	void paint(int x, int y);
	bool operator == (const brick &ob) const;
	void swapBricks(brick &ob);
	void setDelete();
	void setBlack();
	void set();
	int ifBlack();
	int ifToPaint();
};

