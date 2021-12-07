/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	creating strings https://cses.fi/problemset/task/1622
*/

#include <iostream>
#include <math.h>

//we need all combinaison of all subset

int main()
{
	unsigned n, sum(0), nPow2, currentSum(0), weights[20], bestSum(0), halfSum;
	std::cin >> n;

	for (unsigned short i(0); i < n; i++)
	{
		std::cin >> weights[i], sum += weights[i];
	}
	halfSum = sum / 2.0;

	//one loop for each subset

	nPow2 = 1 << n;

	for (unsigned j(0); j < nPow2; j++)
	{
		currentSum = 0;
		for (unsigned short k(0); k < n; k++)
		{
			if ((j >> k) & 1)
			{
				currentSum += weights[k];
			}
		}
		if (currentSum <= halfSum)
		{
			bestSum = std::max(bestSum, currentSum);
		}
	}
	std::cout << sum - bestSum * 2;

	return 0;
}