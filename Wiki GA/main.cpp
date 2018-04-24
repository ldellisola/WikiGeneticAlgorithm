#include "curses.h"
#include "Individual.h"
#include <algorithm>
#include <time.h>
#include <vector>

#include "GAFunctions.h"

// GA functions

void elitistGAFitnessV2CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize);
void elitistGAFitnessV1CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize);
void elitistGAFitnessV3CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize);


// Others

void printPop(vector<Individual>& vect, int generation, const char * perfect, const int perfectSize);

bool sorty(Individual &a, Individual & b) { return a.getFitness() > b.getFitness(); }

int main() {
	srand(time(NULL));
	vector<Individual> population;
	const char * perfect = "To be or not to be To be or not to be To be or not to be";
	const int perfectSize = strlen(perfect);
	const int populationSize = 1000;

	//elitistGAFitnessV2CrossOverV1(population, perfect, perfectSize, populationSize);
	//population.clear();
	elitistGAFitnessV1CrossOverV1(population, perfect, perfectSize, populationSize);
	population.clear();
	elitistGAFitnessV3CrossOverV1(population, perfect, perfectSize, populationSize);
	population.clear();


	
	return 0;

}
bool order(Individual& a, Individual& b)
{
	return (a.getFitness() > b.getFitness());
}

void elitistGAFitnessV1CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize) {
	WINDOW * display = initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	immedok(display, true);
	noecho();

	color_set(1, NULL);

	int generation = 0;



	for (int i = 0; i < populationSize; i++)
		population.push_back(Individual(perfectSize));	// Inicializacion

	bool waitingForPerfect = true;

	while (waitingForPerfect)
	{
		for (Individual& ind : population)			// Calculo el fitness
			ind.calculateFitnessV1(perfect);

		for (Individual& ind : population)
			if (!ind.getGenome().compare(perfect))
				waitingForPerfect = false;

		if (waitingForPerfect) {

			for (Individual& ind : population)			// Calculo el fitness
				ind.calculateFitnessV1(perfect);

			sort(population.begin(), population.end(), order);	// Ordeno al arreglo

			printPop(population, generation, perfect, perfectSize);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
		else
			printPop(population, generation, perfect, perfectSize);
	}
	sort(population.begin(), population.end(),order);
	printPop(population, generation, perfect, perfectSize);
	getch();

	color_set(2, NULL);
	mvdeleteln(0, 0);
	mvprintw(0, 0, "Genetic Algorithm Over. Generation: %d \t Perfet String: %s", generation, perfect);

	printPop(population, generation, perfect, perfectSize);

	getch();
	endwin();
}

void elitistGAFitnessV2CrossOverV1(vector<Individual>& population,const char * perfect, int perfectSize, int populationSize) {
	WINDOW * display = initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	immedok(display, true);
	noecho();

	color_set(1, NULL);

	int generation = 0;



	for (int i = 0; i < populationSize; i++)
		population.push_back(Individual(perfectSize));	// Inicializacion

	bool waitingForPerfect = true;

	while (waitingForPerfect)
	{
		for (Individual& ind : population)			// Calculo el fitness
			ind.calculateFitnessV2(perfect);

		for (Individual& ind : population)
			if (!ind.getGenome().compare(perfect))
				waitingForPerfect = false;

		if (waitingForPerfect) {

			for (Individual& ind : population)			// Calculo el fitness
				ind.calculateFitnessV2(perfect);

			sort(population.begin(), population.end());	// Ordeno al arreglo

			printPop(population, generation, perfect, perfectSize);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
		else
			printPop(population, generation, perfect, perfectSize);
	}
	sort(population.begin(), population.end());
	printPop(population, generation, perfect, perfectSize);
	getch();

	color_set(2, NULL);
	mvdeleteln(0, 0);
	mvprintw(0, 0, "Genetic Algorithm Over. Generation: %d \t Perfet String: %s", generation, perfect);

	printPop(population, generation, perfect, perfectSize);

	getch();
	endwin();
}

void elitistGAFitnessV3CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize) {
	WINDOW * display = initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	immedok(display, true);
	noecho();

	color_set(1, NULL);

	int generation = 0;



	for (int i = 0; i < populationSize; i++)
		population.push_back(Individual(perfectSize));	// Inicializacion

	bool waitingForPerfect = true;

	while (waitingForPerfect)
	{
		for (Individual& ind : population)			// Calculo el fitness
			ind.calculateFitnessV3(perfect);

		for (Individual& ind : population)
			if (!ind.getGenome().compare(perfect))
				waitingForPerfect = false;

		if (waitingForPerfect) {

			for (Individual& ind : population)			// Calculo el fitness
				ind.calculateFitnessV3(perfect);

			sort(population.begin(), population.end(), order);	// Ordeno al arreglo

			printPop(population, generation, perfect, perfectSize);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
		else
			printPop(population, generation, perfect, perfectSize);
	}
	sort(population.begin(), population.end(), order);
	printPop(population, generation, perfect, perfectSize);
	getch();

	color_set(2, NULL);
	mvdeleteln(0, 0);
	mvprintw(0, 0, "Genetic Algorithm Over. Generation: %d \t Perfet String: %s", generation, perfect);

	printPop(population, generation, perfect, perfectSize);

	getch();
	endwin();
}



























void printPop(vector<Individual>& vect, int generation, const char * perfect, const int perfectSize) {

	for (int i = 0; i < 20; i++) {
		if (vect[i].getFitness() > perfectSize / 2)
			color_set(1, NULL);
		else
			color_set(2, NULL);
		string a = vect[i].getGenome() + "";
		int b =(int) vect[i].getFitness();
		mvprintw(2 + i, 0, "Genome Number: %d \t Fitness: %d \t Genome: %s", i + 1,b , a.c_str());
	}
	color_set(1, NULL);
	mvprintw(0, 0, "Genetic Algorithm Running. Generation: %d \t Perfet String: %s", generation, perfect);


}

