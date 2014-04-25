#include "userInterface.h"
#include "allegro5/allegro.h"

#define FPS 30
#define MIDDLEX 512
#define BASEY 200

userInterface::userInterface()
{
	doExit = false;
	myKeys[0] = false;
	myKeys[1] = false;
	myKeys[2] = false;
}


userInterface::~userInterface()
{
}

void userInterface::paint(ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(banerFont, al_map_rgb(0, 102, 0), MIDDLEX, BASEY-150, ALLEGRO_ALIGN_CENTRE, "Square Splash! v1.0");

	switch (menuCounter)
	{
	case 0 :
		al_draw_text(menuFont, al_map_rgb(64, 64, 64), MIDDLEX, BASEY, ALLEGRO_ALIGN_CENTRE, "START GAME");

		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, 275, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES");

		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, 350, ALLEGRO_ALIGN_CENTRE, "EXIT");

		break;
	case 1:
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY, ALLEGRO_ALIGN_CENTRE, "START GAME");

		al_draw_text(menuFont, al_map_rgb(64, 64, 64), MIDDLEX, 275, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES");

		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, 350, ALLEGRO_ALIGN_CENTRE, "EXIT");

		break;
	case 2:
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY, ALLEGRO_ALIGN_CENTRE, "START GAME");

		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, 275, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES");

		al_draw_text(menuFont, al_map_rgb(64, 64, 64), MIDDLEX, 350, ALLEGRO_ALIGN_CENTRE, "EXIT");

		break;
	}
	al_flip_display();
}

void userInterface::doLogic(const ALLEGRO_EVENT &ev)
{
	if (myKeys[0] == true)
	{
		if (menuCounter == 0)
			menuCounter = 2;
		else
			menuCounter--;
		myKeys[0] = false;
	}
	else if (myKeys[1] == true)
	{
		if (menuCounter == 2)
			menuCounter = 0;
		else
			menuCounter++;
		myKeys[1] = false;
	}
	else if (myKeys[2] == true)
	{
		doExit = true;
		myKeys[2] = false;
	}
}

void userInterface::catchMove(const ALLEGRO_EVENT &ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
				myKeys[0] = true;
			break;
		case ALLEGRO_KEY_DOWN:
				myKeys[1] = true;
			break;
		case ALLEGRO_KEY_SPACE:
				myKeys[2] = true;
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
		case ALLEGRO_KEY_SPACE:
			myKeys[2] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			doExit = true;
			menuCounter = 2;
			break;
		}
	}
}

int userInterface::run_menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *signFont, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *banerFont, ALLEGRO_TIMER *timer)
{
	while (!doExit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		catchMove(ev);

		doLogic(ev);

		paint(signFont, menuFont, banerFont);
	}
	return menuCounter;
}