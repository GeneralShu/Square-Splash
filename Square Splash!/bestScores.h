#pragma once
#include <vector>
#include "score.h"
#include "bestScores.h"
#include "fstream"
#include <algorithm>

#define MIDDLEX 512
#define BASEY 200
#define BESTCAPACITY 5




#ifndef hijo_h
#define hijo_h

using namespace std;

template <typename T>
class bestScores :
	public gameGraphics
{
protected:
	vector<T> myScores;
public:
	bestScores();
	~bestScores();
	void load_from_file();
	void paint(ALLEGRO_FONT *menuFont);
	void add_new_best(const score &newScore);
	void update_file();
	void make_best_scores_file();
};

typedef bestScores <score> myIntScores;

template<typename T>
bestScores<T>::bestScores()
{
}

template<typename T>
bestScores<T>::~bestScores()
{
}
template<typename T>
void bestScores<T>::load_from_file()
{
	int temp = 0;
	char exp[30] = "Cannot find best scores file";
	ifstream file;

	for (int k = 0; k < myScores.size(); k++)
		myScores.pop_back();

	file.open("data.txt", std::ios::in);

	if (file.good() != true)
		throw exp;

	while (!file.eof())
	{
		score newScore(temp);
		file >> newScore;
		myScores.push_back(newScore);
	}

	file.close();
}
template<typename T>
void bestScores<T>::paint(ALLEGRO_FONT *menuFont)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY - 100, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES:");

	for (int k = 0; k < myScores.size() - 1; k++)
	{
		char temp[10];
		_itoa_s(myScores.at(k).retrunPoints(), temp, 10);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), MIDDLEX, BASEY + k * 50, ALLEGRO_ALIGN_CENTRE, temp);
	}

	al_flip_display();
	al_rest(3);
}
template<typename T>
void bestScores<T>::add_new_best(const score &newScore)
{
	myScores.push_back(newScore);
	int counter = myScores.size();
	for (int k = myScores.size() - 2; k >= 0; k--)
	{
		if (myScores.at(k) < myScores.at(counter - 1))
		{
			swap(myScores[k], myScores[counter - 1]);
			counter--;
		}
	}
	myScores.pop_back();
}
template<typename T>
void bestScores<T>::update_file()
{
	ofstream file;

	file.open("data.txt", std::ios::out | std::ofstream::trunc);

	for (int k = 0; k < myScores.size() - 1; k++)
	{
		file << myScores.at(k) << "\n";
	}

	file.close();
}
template<typename T>
void bestScores<T>::make_best_scores_file()
{
	ofstream file("data.txt");
	for (int i = 0; i < BESTCAPACITY; i++)
	{
		file << 0 << "\n";
	}
	file.close();
}
#endif