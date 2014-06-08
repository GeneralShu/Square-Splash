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

	int cordX, cordY, movesRemaining; //aktualne polezenie wskaznika oraz ilosc pozostalych ruchow
	bool myKeys[5]; //tablica sprawdzajaca wcisniecie klawiszy strzalek i spacji
	bool doExit; //zmienna sprawdzajaca czy wcisniety zostal klawisz ESC
public:
	gameClass(); //bazowy konstruktor
	~gameClass(); //bazowy destruktor
	int returnX(); //zwraca wartosc polozenia wskaznika X
	int returnY(); //zwraca wartosc polozenia wskaznika Y
	void checkTable(); //sprawdza czy na stole wystepuje zbicie klocek po klocku
	void prepareTable(); //przygotwuje stol do gry (eliminuje poczatkowe zbicia)
	void makeMove(int x1, int y1, int x2, int y2); //wlacza metody odpowiedzialne za zamiane dwoch roznych klockow
	void afterMove(); //wykonuje metody sprawdzania stolu po kazdym ruchu
	void doLogic(const ALLEGRO_EVENT &ev); //wykonuje logike konieczna do poprawnego dzialania aplikacji, wywolujac w odpowiedniej kolejnosci metody oraz sprawdzajac logike
	void catchMove(const ALLEGRO_EVENT &ev); //na podstawie eventow ALLEGRO sprawdza czy zostal wcisniety klawisz
	void paint(); //odziedziczona metoda sluzaca do rysowania ramek stolu, oraz wywolania pozostalych paintow w trakcie gry
	int startGame(); //metoda startujaca gre
	void go(); //metoda startujaca aplikacje
};

