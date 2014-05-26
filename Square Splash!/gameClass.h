#pragma once
#include "gameTable.h"
#include "gameGraphics.h"
#include "score.h"
#include "bestScores.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_font.h>
#include "userInterface.h"

class gameClass 
	: public gameGraphics
{
private:
	userInterface myMenu;
	gameTable gameObject;
	score myScore;
	myIntScores myBestScores;

	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_FONT* scoreFont, * signFont, * menuFont, *banerFont;

	int cordX, cordY, movesRemaining;
	bool myKeys[5];
	bool doExit;
public:
	gameClass();
	~gameClass();
	int returnX();
	int returnY();
	void checkTable();
	void prepareTable();
	void makeMove(int x1, int y1, int x2, int y2);
	void afterMove();
	void moveBrick();
	void doLogic(const ALLEGRO_EVENT &ev);
	void catchMove(const ALLEGRO_EVENT &ev);
	void paint();
	int startGame();
	void go();
};

