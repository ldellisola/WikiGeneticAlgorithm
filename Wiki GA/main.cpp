#include "curses.h"
#include "Individual.h"
#include <algorithm>
#include <time.h>
#include <vector>


void elitistSelection(vector<Individual>& vect);
void printPop(vector<Individual>& vect, int generation, const char * perfect, const int perfectSize);
void crossOverV1(vector<Individual>& vect);

bool sorty(Individual &a, Individual & b) { return a.getFitness() > b.getFitness(); }

int main() {
	srand(time(NULL));
	vector<Individual> population;
	const char * perfect = "Mi Algoritmo genetico es hermoso";
	const int perfectSize = strlen(perfect);
	const int populationSize = 1000;

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
			if (ind.getFitness() == 0)			
				waitingForPerfect = false;

		if (waitingForPerfect) {

			for (Individual& ind : population)			// Calculo el fitness
				ind.calculateFitnessV2(perfect);

			sort(population.begin(), population.end());	// Ordeno al arreglo

			printPop(population,generation,perfect, perfectSize);

			elitistSelection(population);				// Seleccion

			crossOverV1(population);					// crossover

			for (Individual& ind : population)
				ind.Mutate();
			generation++;
		}
		else
			printPop(population, generation, perfect, perfectSize);


		//getch();
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
	return 0;

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

		for (int i = 0; i < size_ / 2; i++){
			c += a[i];
			d += b[i];
		}
		for (int i = size_ / 2; i < size_; i++){
			c += b[i];
			d += a[i];
		}


		vect.push_back(Individual(c));
		vect.push_back(Individual(d));
	}
}