#pragma once
#include <vector>
#include "score.h"

using namespace std;

class bestScores :
	public gameGraphics
{
private:
	vector<score> myScores;
	vector<score>::iterator it;
public:
	bestScores();
	~bestScores();
	void load_from_file();
	void paint(ALLEGRO_FONT *menuFont);
	void add_new_best(const score &newScore);
	void update_file();
};

