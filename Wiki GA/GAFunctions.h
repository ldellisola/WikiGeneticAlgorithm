#pragma once
#include "Individual.h"
#include "curses.h"
#include <vector>

using namespace std;

// It kills the lower half of the population and keeps the better half.
//
void elitistSelection(vector<Individual>& vect);

// It cuts the genome in half and it crates 2 new childs
void crossOverV1(vector<Individual>& vect);

void probabilisticSelection(vector<Individual>& pop);