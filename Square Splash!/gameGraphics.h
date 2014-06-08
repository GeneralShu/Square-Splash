#pragma once
class gameGraphics
{
public:
	gameGraphics(); //konstruktor
	virtual ~gameGraphics(); //wirtualny destruktor
	virtual void paint(); //metoda dziedziczona przez wszystkie pozostale funkcje, sluzaca do rysowania poszczegolnych elementow
};

