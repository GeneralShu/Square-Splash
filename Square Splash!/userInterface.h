#pragma once
#include "allegro5/allegro.h"
#include "gameGraphics.h"
#include <allegro5/allegro_ttf.h>

class userInterface :
	public gameGraphics
{
private:
	bool doExit; //zmienna sprawdzajaca czy wcisniety zostal ESC
	bool myKeys[3]; //zmienne sprawdzajace czy zostala wcisnieta strzalka w gore, w dol lub spacja
	int menuCounter; //odpowiada za pozycje wskaznika w menu
public:
	userInterface(); //bazowy konstruktor
	~userInterface(); //bazowy destruktor
	void paint(ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont); //dziedziczona metoda do rysowania menu
	void doLogic(const ALLEGRO_EVENT &ev); //sprawdza logike menu (poruszanie sie, wyjscie etc)
	void catchMove(const ALLEGRO_EVENT &ev); //sprawdza czy wcisniety zostal klawisz
	int run_menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont, ALLEGRO_TIMER *timer); //zawiera petle dzialania menu
};

