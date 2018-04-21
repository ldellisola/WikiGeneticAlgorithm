#pragma once
#include <string>



using namespace std;
class Individual
{
public:
	Individual(int lenght);
	Individual(string genome_);
	
	~Individual();

	void calculateFitnessV1(const char * perfect);
	void calculateFitnessV2(const char * perfect);
	void Mutate();

	void setGenome(string a);

	float getFitness();
	string getGenome();

	bool operator< (Individual& a);
	bool operator> (Individual& a);
private:
	float fitness;
	string genome;

	 int mutationRate = 100;
};

