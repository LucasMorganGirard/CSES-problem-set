/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	missing number https://cses.fi/problemset/task/1083
*/

#include <iostream>

int main()
{
	unsigned long nbInputs, input, sumOfInputs(0);
	std::cin >> nbInputs;

	for (unsigned long i(0); i < nbInputs - 1; i++)
	{
		std::cin >> input;
		sumOfInputs += input;
	}

	//expected sum of 1+2+..+n-1+n - actual sum = missing number
	std::cout << ((nbInputs + 1) * nbInputs) / 2 - sumOfInputs;

	return 0;
}