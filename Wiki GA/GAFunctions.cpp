#include "GAFunctions.h"


void elitistSelection(vector<Individual>& vect) {

	int size = vect.size();

	for (int i = 0; i < size / 2; i++)
		vect.pop_back();
}

void crossOverV1(vector<Individual>& vect) {
	int size = vect.size();
	for (int i = 0; (i + 1) <= size; i += 2) {
		string a = vect[i].getGenome();
		string b = vect[i + 1].getGenome();

		int size_ = a.size();

		string c;
		string d;

		for (int i = 0; i < size_ / 2; i++) {
			c += a[i];
			d += b[i];
		}
		for (int i = size_ / 2; i < size_; i++) {
			c += b[i];
			d += a[i];
		}


		vect.push_back(Individual(c));
		vect.push_back(Individual(d));
	}
}