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

//void probabilisticSelection(vector<Individual>& pop)
//{
//	int size = pop.size();
//
//
//	vector<float> relativeFitness;
//	vector<Individual>father;
//
//	float fitnessSum = 0;
//
//	for (Individual& ind : pop) 
//		fitnessSum += ind.getFitness();
//
//	for (int i = 0; i < size; i++)
//		relativeFitness.push_back(pop[i].getFitness()/fitnessSum );
//
//	for (int i = 0; i < size; i++) {
//		if (((rand() % 1000) / 1000) > relativeFitness[i])
//			father.push_back(pop[i]);
//	}
//
//	if (father.size() > size / 2)
//		for (int i = father.size(); i > size / 2; i++)
//			father.pop_back();
//	else if (father.size() > size / 2)
//		for (int i =)
//
//
//
//
//}
