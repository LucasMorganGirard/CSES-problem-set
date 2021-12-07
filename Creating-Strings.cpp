/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	creating strings https://cses.fi/problemset/task/1622
*/

#include <iostream>
#include <algorithm>
#include <set>
unsigned n(0);

//heaps algorithm
void heapsAlg(std::set<std::string> &strSet, unsigned k, std::string &currentStr)
{
	if (k == 1)
	{
		strSet.insert(currentStr);
	}
	else
	{
		heapsAlg(strSet, k - 1, currentStr);
		for (unsigned i(0); i < k - 1; i++)
		{
			if (k & 1)
			{
				std::swap(currentStr[0], currentStr[k - 1]);
			}
			else
			{
				std::swap(currentStr[i], currentStr[k - 1]);
			}
			heapsAlg(strSet, k - 1, currentStr);
		}
	}
}

int main()
{
	std::string str;
	std::set<std::string> strSet;
	std::cin >> str;
	std::sort(str.begin(), str.end());

	heapsAlg(strSet, str.size(), str);
	std::cout << strSet.size() << '\n';
	for (auto it : strSet)
	{
		std::cout << it << "\n";
	}

	return 0;
}