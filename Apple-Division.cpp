/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	apple division https://cses.fi/problemset/task/1623
*/

#include <iostream>

const size_t MAX(20);

size_t N(0);
size_t WEIGHT[MAX];
size_t BEST(SIZE_MAX);
size_t CURRENT_SUM(0);
size_t TOTAL_SUM(0);

void calculAllDifference(size_t i){
	/*
		if i = N-1 we are at the endpoint and have succesfully calculated one combinaison of apple in groupe 1
		we then test if the difference with groupe 2 is better that the current best. 
		current difference = |groupe_1_sum - (total_sum - groupe_1_sum)|
	*/
	if(i == N-1){
		size_t currentDiff;
		if(CURRENT_SUM > TOTAL_SUM/2){
			currentDiff = CURRENT_SUM - (TOTAL_SUM - CURRENT_SUM);
		}else{
			currentDiff = (CURRENT_SUM - CURRENT_SUM) - CURRENT_SUM;
		}
		BEST = std::min(BEST, currentDiff);
		return;
	}

	/*
		create all combinaison for groupe 1, generate one sum with current apple i and one without it.
	*/
	CURRENT_SUM+=WEIGHT[i];
	calculAllDifference(i+1);
	CURRENT_SUM-=WEIGHT[i];
	calculAllDifference(i+1);
}

int main()
{
	size_t n, totalSum(0), currentSum(0), bestDiff(SIZE_MAX);
	std::cin >> n;

	for(size_t i(0); i<n; i++){
		std::cin >> WEIGHT[i];
		totalSum+=WEIGHT[i];
	}

	calculAllDifference(0);
	std::cout << BEST;
	return 0;
}