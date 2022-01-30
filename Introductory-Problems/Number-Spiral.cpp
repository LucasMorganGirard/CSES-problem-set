/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    number spiral https://cses.fi/problemset/task/1071
*/

#include <iostream>

int main()
{
	unsigned long nbInput, x, y;
	std::cin >> nbInput;

	for (unsigned long i(0); i < nbInput; i++)
	{
		std::cin >> y >> x;
		if (x > y)
		{
			if (x & 1)
			{
				std::cout << x * x - y + 1;
			}
			else
			{
				x--;
				std::cout << x * x + y;
			}
		}
		else
		{
			if (y & 1)
			{
				y--;
				std::cout << y * y + x;
			}
			else
			{
				std::cout << y * y - x + 1;
			}
		}
		std::cout << "\n";
	}

	return 0;
}
