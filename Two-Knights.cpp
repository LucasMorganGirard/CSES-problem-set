/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	Two Knights https://cses.fi/problemset/task/1072
*/

#include <iostream>
#include <cmath> /* std::pow */

/**
 * @brief 2 choose n^2 total combinaison minus knights intersections : 4*(n-1)(n-2) -> can be found by drawing on
 * a grid how many times do knight interact with each other in only one L disposition on a n*n board and then multiply
 * it by 4. (knight attack in 8 ways but when two knight attack each other they attack two different L ways)
 * 
 * 2 choose n^2 -> (n^2)!/(2!(n^2-2)!) = (n^4-n^2)/2
 * 4(n-1)(n-2) = 4n^2-12n+8
 * (2 choose n^2) - 4(n-1)(n-2) = ( n^4 - 9n^2 + 24n - 16 )/2
 */
int main()
{
	size_t n;
	std::cin >> n;

	for(size_t i(1); i<=n; i++){
        std::cout << (((i*i*i*i) - 9*(i*i) + 24*i - 16)>>1) << "\n";
	}

	return 0;
}