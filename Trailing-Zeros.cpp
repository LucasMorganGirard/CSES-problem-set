/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	trailing zeros https://cses.fi/problemset/task/1618
*/

#include <iostream>
#include <math.h>

//number of 5s
int main()
{
	unsigned long n;
	std::cin >> n;
	std::cout << floor(n / 5);
	return 0;
}