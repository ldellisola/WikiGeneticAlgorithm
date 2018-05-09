#include "curses.h"
#include "Individual.h"
#include "Timer.h"
#include <algorithm>
#include <time.h>
#include <vector>

#include "GAFunctions.h"

// GA functions

void elitistGAFitnessV2CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize, bool print);
void elitistGAFitnessV1CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize, bool print);


// Others

void printPop(vector<Individual>& vect, int generation, const char * perfect, const int perfectSize, bool);

bool sorty(Individual &a, Individual & b) { return a.getFitness() > b.getFitness(); }

int main() {

	WINDOW * display = initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	immedok(display, true);
	noecho();
	bool leave = false;
	bool print = false;
	color_set(1, NULL);

	mvprintw(0, 0, "Press 'P' to print the algorithm while running \nPress 'Q' to leave \nPress any other key to run the algorithm");
	switch (getch()) {
	case 'p': print = true;
		break;
	case 'q': leave = true;
	default: print = false;
	}

	color_set(1, NULL);

	srand(time(NULL));
	vector<Individual> population;
	const char * perfect = "Genetic Algorithm";
	const int perfectSize = strlen(perfect);
	const int populationSize = 1000;

	while (!leave) {

		clear();
		Timer time;
		mvprintw(0, 0, "Running First Algorithm");
		time.start();
		elitistGAFitnessV1CrossOverV1(population, perfect, perfectSize, populationSize, print);
		time.stop();
		population.clear();
		clear();
		if (!print) {
			mvprintw(0, 0, "It took %f seconds", time.getTime() / 1000.0);
			mvprintw(2, 0, "Press enter to continue");
			getch();
			clear();
		}
		mvprintw(0, 0, "Running Second Algorithm");
		time.start();
		elitistGAFitnessV2CrossOverV1(population, perfect, perfectSize, populationSize, print);
		time.stop();
		population.clear();
		clear();
		if (!print) {
			mvprintw(0, 0, "It took %f seconds", time.getTime() / 1000.0);
			mvprintw(2, 0, "Press enter to continue");
			getch();
			clear();
		}

		mvprintw(0, 0, "Press 'P' to print the algorithm while running \nPress 'Q' to leave \nPress any other key to run the algorithm");
		switch (getch()) {
		case 'p': print = true;
			break;
		case 'q': leave = true;
		default: print = false;
		}


	}








	endwin();


	
	return 0;

}
bool order(Individual& a, Individual& b)
{
	return (a.getFitness() > b.getFitness());
}

void elitistGAFitnessV1CrossOverV1(vector<Individual>& population, const char * perfect, int perfectSize, int populationSize, bool print) {

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

			if (print)
				printPop(population, generation, perfect, perfectSize,false);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
	}
	sort(population.begin(), population.end(),order);
	if (print){

		color_set(2, NULL);
		clear();
		mvprintw(0, 0, "Genetic Algorithm Over. Generation: %d \t Perfet String: %s", generation, perfect);


		printPop(population, generation, perfect, perfectSize, false);
		getch();
	}


}

void elitistGAFitnessV2CrossOverV1(vector<Individual>& population,const char * perfect, int perfectSize, int populationSize, bool print) {


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

			if (print)
				printPop(population, generation, perfect, perfectSize, true);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
	}
	sort(population.begin(), population.end());
	if (print) {
		color_set(2, NULL);
		clear();
		mvprintw(0, 0, "Genetic Algorithm Over. Generation: %d \t Perfet String: %s", generation, perfect);
		printPop(population, generation, perfect, perfectSize, true);
		getch();
	}
}





void printPop(vector<Individual>& vect, int generation, const char * perfect, const int perfectSize, bool fitnessToCero) {

	for (int i = 0; i < 20; i++) {
		if (!fitnessToCero) {
			if (vect[i].getFitness() > perfectSize / 1.5)
				color_set(1, NULL);
			else
				color_set(2, NULL);
		}
		else{
			if (vect[i].getFitness() <perfectSize / 3)
				color_set(1, NULL);
			else
				color_set(2, NULL);
		}

		string a = vect[i].getGenome() + "";
		int b =(int) vect[i].getFitness();
		mvprintw(2 + i, 0, "Genome Number: %d \t Fitness: %d \t Genome: %s", i + 1,b , a.c_str());
	}
	color_set(1, NULL);
	mvprintw(0, 0, "Genetic Algorithm Running. Generation: %d \t Perfet String: %s", generation, perfect);


}

