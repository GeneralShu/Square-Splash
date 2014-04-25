#pragma once
#include "allegro5/allegro.h"
#include "gameGraphics.h"
#include <allegro5/allegro_ttf.h>

class userInterface :
	public gameGraphics
{
private:
	bool doExit;
	bool myKeys[3];
	int menuCounter;
public:
	userInterface();
	~userInterface();
	void paint(ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont);
	void doLogic(const ALLEGRO_EVENT &ev);
	void catchMove(const ALLEGRO_EVENT &ev);
	int run_menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont, ALLEGRO_TIMER *timer);
};

