#pragma once
#include "brick.h"
#include "bonus.h"
class superBrick :
	public brick, public bonus
{
public:
	superBrick();
	superBrick(int bonusType) : bonus(bonusType){ R = 0; B = 0; G = 0; }
	~superBrick();
	void paint(int x, int y);
};

