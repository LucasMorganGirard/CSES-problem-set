/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	increasing array https://cses.fi/problemset/task/1094
*/

#include <iostream>

int main()
{
	long nbInput, currentInput, maxPreviousInput, difference, nbMove(0);
	std::cin >> nbInput;

	std::cin >> maxPreviousInput;

	for (long i(1); i < nbInput; i++)
	{
		std::cin >> currentInput;
		difference = maxPreviousInput - currentInput;

		if (difference > 0)
		{
			nbMove += difference;
		}
		else
		{
			maxPreviousInput = currentInput;
		}
	}

	std::cout << nbMove;

	return 0;
}