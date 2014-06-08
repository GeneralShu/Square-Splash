#pragma once
#include "gameGraphics.h"


class brick 
	: public gameGraphics
{
protected:
	int R, G, B;
	bool ifDelete;
public:
	brick(); //bazowy konstruktor, zerujacy wartosci koloru, oraz zmienna odpowiadajaca za usuniecie
	void randomColor(); //metoda ustawiajaca losowy kolor dla obiektu klocek
	~brick(); //bazowy destruktor
	void paint(int x, int y); //dziedziczona metoda rysujaca klocek
	bool operator == (const brick &ob) const; //operator porownania kolorow dwoch klockow
	void swapBricks(brick &ob); //metoda relizujaca zamiane wartosci dwoch zmiennych typu klocek
	void setDelete(); //ustawia zmienna ifDelete na true
	void setBlack(); //zmienia kolor na czarny R=G=B=0
	void set(); //zmienia wartosc ifDelete na false
	int ifBlack(); //sprawdza czy R=G=B=0
	int ifToPaint(); //wyznacza wartosc ifDelete i zwraca ja
};

