#pragma once
#include <vector>
#include "score.h"

using namespace std;

class bestScores
{
private:
	vector<score> myScores;
public:
	bestScores();
	~bestScores();
};

