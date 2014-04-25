#pragma once
#include "brick.h"
class superBrick :
	public brick
{
private:
	int bonusType;
public:
	superBrick();
	superBrick(int bonusType) : bonusType(bonusType){ R = 0; B = 0; G = 0; }
	~superBrick();
	void paint(int x, int y);
};

