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
	int points; //zmienna przechowujaca wartosc punktow
	void addScore(int temp){ points = temp; } //metoda dodajaca ilosc punktow do points, konieczna do dzialania operatora ifstream
public:
	score(); //konstruktor bazowt
	score(int points); //konstruktor z parametrem do ustawienia poczatkowej wartosci points
	~score(); //bazowy destruktor
	void calculateScore(int crashCounter); //oblicza ile punktow ma zostac dodane do points na podstawie zmiennej
	void paint(ALLEGRO_FONT* font); //wypisuje/wyrysowuje wynik podczas rozgrywki
	void zeroPoints(); //zeruje wartosc points
	int retrunPoints(); //zwraca wartosc zmiennej points
	bool operator < (const score &ob) const; //przeladowany operator do porownywania punktow
	friend ifstream& operator >> (ifstream& in, score &h); //przeladowany operator wczytywania z pliku
	friend ofstream& operator << (ofstream& out, score &h); //przeladowany operator zapisywania do pliku
};

