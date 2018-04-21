#include "Individual.h"
#include <math.h>

static const char alphanum[] =
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,/';:<>\][{}|=+-_)(*&^%$#@!`~?";
;

const int stringLength = sizeof(alphanum) - 1;

Individual::Individual(int lenght)
{
	fitness = 0.0f;
	for(int i = 0 ; i < lenght ; i++)
		genome.push_back(alphanum[rand() % stringLength]);
}

Individual::Individual(string genome_)
{
	fitness = 0;
	genome = genome_;
}

float Individual::getFitness()
{
	return fitness;
}

string Individual::getGenome()
{
	return genome;
}


bool Individual::operator<(Individual & a)
{
	return (a.fitness >this->fitness);
}

bool Individual::operator>(Individual & a)
{
	return (a.fitness<  this->fitness);
}

Individual::~Individual()
{
}


void Individual::calculateFitnessV1(const char * perfect)
{
	fitness = 0;
	int size = genome.size();
	for (int i = 0; i < size ; i++) {
		if (genome[i] == perfect[i])
			fitness++;
	}
}

void Individual::calculateFitnessV2(const char * perfect)
{
	fitness = 0;
	int size = genome.size();
	for (int i = 0; i < size; i++) {
		fitness += abs(genome[i] - perfect[i]);
	}
}

void Individual::Mutate()
{
	for (int i = 0; i < genome.size(); i++) {
		if (!(rand() % mutationRate)) {
			char a = alphanum[rand() % stringLength];
			genome[i] = a;
		}
	}
}
	


void Individual::setGenome(string a)
{
	genome = a;
}
