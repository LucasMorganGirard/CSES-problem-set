/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    missing number https://cses.fi/problemset/task/1083
*/

#include <iostream>

int main(){
    unsigned long n, input, sum(0);
    std::cin >> n;

    for (unsigned long i(0); i < n-1; i++)
    {
        std::cin >> input;
        sum+=input;
    }
    
    //expected sum of 1+2+..+n-1+n - actual sum = missing number
    std::cout << ((n+1)*n)/2-sum;

    return 0;
}