/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	palindrome reorder https://cses.fi/problemset/task/1755
*/

#include <iostream>

/*  The idea to solve this is to add one to an array of 26 case every time the corresponding  
	letter appears in the input. Once we know how many character of each letter appears we can 
	put half the caracter of one letter on the right and the other half on the left
	If half on one character is not pair, this letter can only be in the middle
	Only one character can be present in impaire number, otherwise no solution

	T[] = {number of As, number of Bs... number of Zs}
	result : print half the As to the right, and the other half to the left
*/
int main()
{
	//array initialistion to 0
	unsigned tabOfAlphabet[26] = {0};
	//true if on letter appears an impair number of time in the input string
	bool hasImpaireAlready = false;
	std::string str, res("");
	std::cin >> str;

	//count the number of time each letter appears
	//add one to the corresponding array element at each apparition of the letter
	//char A = 65 in ascii
	for (char c : str)
	{
		tabOfAlphabet[c - 65]++;
	}

	//look for a letter that appear an impair number of time and save it in a string
	//to be displayed at the middle of the palindrome
	//if more than one number appears an impair number of time, no palindrome can be constructed
	for (unsigned i(0); i < 26; i++)
	{
		if (tabOfAlphabet[i] & 1)
		{
			if (hasImpaireAlready)
			{
				std::cout << "NO SOLUTION ";
				return 0;
			}
			else
			{
				hasImpaireAlready = true;
				for (unsigned j(0); j < tabOfAlphabet[i]; j++)
				{
					res += (char)(i + 65);
				}
				tabOfAlphabet[i] = 0;
			}
		}
	}

	//print half of each characters that appears a pair number of times
	for (unsigned i(0); i < 26; i++)
	{
		for (unsigned j(0); j < tabOfAlphabet[i] / 2; j++)
		{
			std::cout << (char)(i + 65);
		}
	}

	//print the character that appear an impair number of time (if there is one)
	std::cout << res;

	//print the other half of each characters that appears a pair number of times
	for (int i(25); i >= 0; i--)
	{
		for (unsigned j(tabOfAlphabet[i] / 2); j < tabOfAlphabet[i]; j++)
		{
			std::cout << (char)(i + 65);
		}
	}

	return 0;
}