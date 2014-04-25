#include "bestScores.h"
#include "fstream"
#include <algorithm>

#define MIDDLEX 512
#define BASEY 200
#define BESTCAPACITY 5


using namespace std;

bestScores::bestScores()
{
}


bestScores::~bestScores()
{
}

void bestScores::load_from_file()
{
	int exp=1, temp;
	fstream file;

	for (int k = 0; k < myScores.size(); k++)
		myScores.pop_back();

	file.open("data.txt", std::ios::in);

	if (file.good() != true)
		throw exp;

	while ( !file.eof() )
	{
			file >> temp;
			score newScore(temp);
			myScores.push_back(newScore);
	}

	file.close();
}

void bestScores::paint(ALLEGRO_FONT *menuFont)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY - 100, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES:");

	for (int k = 0; k < myScores.size() - 1; k++)
	{
		//char number[3] = (k + 1) + '. ';
		char temp[10];
		_itoa_s(myScores.at(k).retrunPoints(), temp, 10);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY + k*50, ALLEGRO_ALIGN_CENTRE, temp);
	}

	al_flip_display();
	al_rest(3);
}

void bestScores::add_new_best(const score &newScore)
{
	myScores.push_back(newScore);
	int counter = myScores.size();
	for (int k = myScores.size()-2; k >= 0; k--)
	{
		if (myScores.at(k) < myScores.at(counter - 1))
		{
			swap(myScores[k], myScores[counter-1]);
			counter--;
		}
	}
	myScores.pop_back();
}

void bestScores::update_file()
{
	fstream file;

	file.open("data.txt", std::ios::out | std::ofstream::trunc);

	for (int k = 0; k < BESTCAPACITY; k++)
	{
		file << myScores.at(k).retrunPoints() << "\n";
	}

	file.close();
}