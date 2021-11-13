/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    Premutations https://cses.fi/problemset/task/1070
*/

#include <iostream>

int main(){
    unsigned long permutationSize;
    std::cin >> permutationSize;

    if(permutationSize > 3 || permutationSize == 1){
        for(unsigned i(2); i <= permutationSize; i+=2){
            std::cout << i << " ";
        }
        for (unsigned i(1); i <= permutationSize; i+=2)
        {
            std::cout << i << " ";
        }
    }else{
        std::cout << "NO SOLUTION";
    }


    return 0;
}
