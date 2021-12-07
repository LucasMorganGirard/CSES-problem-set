/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	weird algorithm https://cses.fi/problemset/task/1068/
*/

#include <iostream>

int main()
{
	unsigned long n;

	std::cin >> n;
	std::cout << n << ' ';

	while (n > 1)
	{
		if (n & 1)
		{ //odd
			n *= 3;
			n++;
		}
		else
		{ //even
			n /= 2;
		}

		std::cout << n << ' ';
	}

	return 0;
}