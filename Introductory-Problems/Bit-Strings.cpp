/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	bit strings https://cses.fi/problemset/task/1617
*/

#include <iostream>
#include <math.h>

int main()
{
	unsigned long long n, res(2);
	std::cin >> n;

	//pow too slow, manualy compute 2 power n
	for (unsigned i(1); i < n; i++)
	{
		res <<= 1;
		res %= 1000000007;
	}

	std::cout << res;
}