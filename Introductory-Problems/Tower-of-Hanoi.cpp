/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	tower of hanoi https://cses.fi/problemset/task/2165
*/

#include <iostream>

/**
 * @brief implemented from https://en.wikipedia.org/wiki/Tower_of_Hanoi
 * 
 * @param n number of disk, start at 1
 * @param start starting column
 * @param middle intermediaire column
 * @param end destination column
 */
void hanoi(unsigned n, unsigned start, unsigned middle, unsigned end){
	if(n>=1){
		hanoi(n-1, start, end, middle);
		std::cout << start << " " << end << "\n";
		hanoi(n-1, middle, start, end);
	}
}

int main()
{
	unsigned n;
	std::cin >> n;
	std::cout << ((1<<n)-1) << "\n"; //2^n - 1 can be remplaced by std::pow(2, n)
	hanoi(n, 1, 2, 3);
	return 0;
}