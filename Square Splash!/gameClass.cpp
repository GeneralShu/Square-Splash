#include "gameClass.h"
#include "gameTable.h"
#include "userInterface.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#define WIDTH 8
#define LENGTH 8
#define BRICKSIZE 85
#define STARTXTABLE 5
#define STARTYTABLE 5
#define FPS 30

gameClass::gameClass()
{
	doExit = false;

	myKeys[0] = false;
	myKeys[1] = false;
	myKeys[2] = false;
	myKeys[3] = false;
	myKeys[4] = false;

	cordX = WIDTH / 2;
	cordY = LENGTH / 2;

	al_init();

	display = al_create_display(1024, 720);

	al_init_primitives_addon();

	al_install_keyboard();

	al_init_font_addon();

	al_init_ttf_addon();

	timer = al_create_timer(1.0 / FPS);

	signFont = al_load_ttf_font("pirulen.ttf", 12, 0);

	scoreFont = al_load_ttf_font("pirulen.ttf", 26, 0);

	menuFont = al_load_ttf_font("pirulen.ttf", 32, 0);

	banerFont = al_load_ttf_font("pirulen.ttf", 40, 0);

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	prepareTable();
}


gameClass::~gameClass()
{
}

int gameClass::returnX()
{
	return cordX;
}

int gameClass::returnY()
{
	return cordY;
}

void gameClass::checkTable()
{
	int tempScore;
	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < LENGTH; k++)
		{
			tempScore=gameObject.checkColision(i, k);
			myScore.calculateScore(tempScore);

		}
	}
}

void gameClass::prepareTable()
{
	bool nextCheck;
	checkTable();
	gameObject.setBlack();
	gameObject.fallBricks();

	nextCheck = gameObject.fillTable();

	if (nextCheck == true)
		prepareTable();
	myScore.zeroPoints();
}

void gameClass::makeMove(int x1, int y1, int x2, int y2)
{
	this->gameObject.swapOnTable(x1, y1, x2, y2);
	paint();
}

void gameClass::afterMove()
{
	bool nextCheck;
	checkTable();
	gameObject.setBlack();

	paint();
	gameObject.fallBricks();
    //al_rest(2);

	paint();
	nextCheck=gameObject.fillTable();
	//al_rest(2);

	if (nextCheck == true)
		afterMove();

	paint();
}

void gameClass::doLogic(const ALLEGRO_EVENT &ev)
{
	switch (myKeys[4])
	{
	case true:
		if (myKeys[0] == true && cordY > 0)
		{
			makeMove(cordX, cordY, cordX, cordY - 1);
			afterMove();
			cordY--;
			myKeys[0] = false;
			myKeys[4] = false;
		}
		else if (myKeys[1] == true)
		{
			makeMove(cordX, cordY, cordX, cordY + 1);
			afterMove();
			cordY++;;
			myKeys[1] = false;
			myKeys[4] = false;
		}
		else if (myKeys[2] == true)
		{
			makeMove(cordX, cordY, cordX - 1, cordY);
			afterMove();
			cordX--;;
			myKeys[2] = false;
			myKeys[4] = false;
		}
		else if (myKeys[3] == true)
		{
			makeMove(cordX, cordY, cordX + 1, cordY);
			afterMove();
			cordX++;;
			myKeys[3] = false;
			myKeys[4] = false;
		}
		break;
	case false:
		if (myKeys[0] == true && cordY > 0)
		{
			cordY--;
			myKeys[0] = false;
		}
		else if (myKeys[1] == true)
		{
			cordY++;
			myKeys[1] = false;
		}
		else if (myKeys[2] == true)
		{
			cordX--;
			myKeys[2] = false;
		}
		else if (myKeys[3] == true)
		{
			cordX++;
			myKeys[3] = false;
		}
		break;
	}
}

void gameClass::catchMove(const ALLEGRO_EVENT &ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			if (cordY > 0)
				myKeys[0] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			if (cordY < 7)
				myKeys[1] = true;
			break;
		case ALLEGRO_KEY_LEFT:
			if (cordX > 0)
				myKeys[2] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			if (cordX < 7)
				myKeys[3] = true;
			break;
		case ALLEGRO_KEY_SPACE:
			if (myKeys[4] == true)
				myKeys[4] = false;
			else
				myKeys[4] = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			myKeys[0] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			myKeys[1] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			myKeys[2] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			myKeys[3] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			doExit = true;
			break;
		}
	}
}

void gameClass::paint()
{
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		myScore.paint(scoreFont);

		gameObject.paint(returnX(), returnY());

		al_draw_text(signFont, al_map_rgb(255, 255, 255), 840, 700, 0, "Pawel Nowak 2014");

		al_flip_display();
	}
}

void gameClass::startGame()
{
	prepareTable();
	paint();

	while (!doExit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		catchMove(ev);

		doLogic(ev);

		paint();
	}
}

void gameClass::go()
{
	int menuCounter;
	menuCounter = myMenu.run_menu(display, event_queue, signFont, menuFont, banerFont, timer);
	switch (menuCounter)
	{
	case 0 :
		startGame();
		break;
	case 1 :
		//highscores
		break;
	}
}
