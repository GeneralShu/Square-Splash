#pragma once
#include "brick.h"
class superBrick :
	public brick
{
private:
	int bonusType;
public:
	superBrick();
	superBrick(int bonusType) : bonusType(bonusType){}
	virtual ~superBrick();
	void paint(int x, int y);
};

