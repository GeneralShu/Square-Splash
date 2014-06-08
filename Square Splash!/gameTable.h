#pragma once
#include "brick.h"
#include "gameGraphics.h"
#include "score.h"


class gameTable : public gameGraphics
{
private:
	brick** table; //dwuwymiarowa tablica klockow
public:
	gameTable(); //konstruktor bazowy
	~gameTable(); //bazowy destruktor
	void swapOnTable(int x1, int y1, int x2, int y2); //wybiera pozycje na stole ktora maja zostac zamienione miejscami
	void paint(int CordX, int cordY); //rysuje stol wywolujac metode paint na poszczegolnych klockach
	void setBlack(); //petla wywolujaca setBlack dla poszczegolnych klockow
	int checkColision(int x, int y); //dwie petla sprawdzajace kolizje dla kazdego klocka z osobna
	int checkVerticalColision(int x, int y); //sprawdza kolizje w poziomie
	int checkHorizontalColision(int x, int y); //sprawdza kolizje w pionie
	void setVertical(int x, int y, int counter); //ustawia zbicie klockow w poziomie
	void setHorizontal(int x, int y, int counter); //ustawia zbicie klockow w pionie
	void fallBricks(); //realizuje opadania klockow po zbiciu
	bool fillTable(); //uzueplnia braki na stole powstale w wyniku zbicia i opadania
};

