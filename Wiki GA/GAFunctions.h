#pragma once
#include "Individual.h"
#include "curses.h"
#include <vector>

using namespace std;


void elitistSelection(vector<Individual>& vect);
void crossOverV1(vector<Individual>& vect);