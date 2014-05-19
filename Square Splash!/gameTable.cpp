#include "gameTable.h"
#include "superBrick.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>

#define WIDTH 8
#define LENGTH 8
#define BRICKSIZE 85
#define STARTXTABLE 5
#define STARTYTABLE 5

gameTable::gameTable()
{
	srand(time(0));
	this->table = new brick*[WIDTH];
	for (int i = 0; i < WIDTH; i++) this->table[i] = new brick[LENGTH];
	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < LENGTH; k++)
			table[i][k].randomColor();
	}
}

gameTable::~gameTable()
{
	//for (int i = 0; i < WIDTH; i++) delete this->table[i];
	//delete this->table;
}

void gameTable::swapOnTable(int x1, int y1, int x2, int y2)
{
	this->table[y1][x1].swapBricks(this->table[y2][x2]);
}

void gameTable::paint(int cordX, int cordY)
{
	al_draw_rectangle(3, 3, 687, 687, al_map_rgb(64, 64, 64), 3);
	al_draw_rectangle(STARTXTABLE + cordX * BRICKSIZE, STARTYTABLE + cordY * BRICKSIZE, BRICKSIZE + STARTXTABLE + cordX * BRICKSIZE, BRICKSIZE + STARTXTABLE + cordY * BRICKSIZE, al_map_rgb(64, 64, 64), 5);
	brick *temp;
	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < LENGTH; k++)
		{
			temp = &table[k][i];
			temp->paint(k, i);
		}
	}
}

void gameTable::setBlack()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < LENGTH; k++)
		{
			if (table[i][k].ifToPaint() == 1)
				table[i][k].setBlack();
		}
	}
}

int gameTable::checkColision(int x, int y)
{
	int horizontal, vertical;
	horizontal = checkHorizontalColision(x, y);
	vertical = checkVerticalColision(x, y);
	setHorizontal(x, y, horizontal);
	setVertical(x, y, vertical);
	if (horizontal >= 3 && vertical >= 3)
	{
		return horizontal + vertical;
	}
	else if (horizontal >= 3)
		return horizontal;
	else if (vertical >= 3)
		return vertical;
	else
		return 0;
}


int gameTable::checkVerticalColision(int x, int y)
{
	int counter = 0;
	for (int i = y; i < WIDTH; i++)
	{
		if (table[y][x] == table[i][x])
			counter++;
		else
			break;
	}
	return counter;
}

int gameTable::checkHorizontalColision(int x, int y)
{
	int counter = 0;
	for (int i = x; i < WIDTH; i++)
	{
		if (table[y][x] == table[y][i])
			counter++;
		else
			break;
	}
	return counter;
}

void gameTable::setVertical(int x, int y, int counter)
{
	if (counter >= 3)
	{
		for (int i = y; i < counter + y; i++)
		{
			table[i][x].setDelete();
		}
	}
}
void gameTable::setHorizontal(int x, int y, int counter)
{
	if (counter >= 3)
	{
		for (int i = x; i < counter + x; i++)
		{
			table[y][i].setDelete();
		}
	}
}

void gameTable::fallBricks()
{
	for (int i = WIDTH - 1; i >= 0; i--)
		for (int k = LENGTH - 1; k >= 0; k--)
			if (table[k][i].ifBlack() == 1)
				for (int n = k - 1; n >= 0; n--)
				if (table[n][i].ifBlack() == 0)
					table[k][i].swapBricks(table[n][i]);
}

bool gameTable::fillTable()
{
	bool ifFilled = false;
	for (int i = WIDTH - 1; i >= 0; i--)
	{
		for (int k = LENGTH - 1; k >= 0; k--)
		{
			table[k][i].set();
			if (table[k][i].ifBlack() == 1)
			{
				ifFilled = true;
				table[k][i].randomColor();
			}
		}
	}
	return ifFilled;
}