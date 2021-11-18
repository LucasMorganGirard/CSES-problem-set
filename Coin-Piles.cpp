/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    coin piles https://cses.fi/problemset/task/1754
*/

#include <iostream>

int main(){
    unsigned long n, a, b;
    std::cin >> n;

    for(unsigned long i(0); i < n; i++){
        std::cin >> a >> b;

        //yes if sum a+b multiple of 3 (coins are removed 3 by 3) 
        //and if a is not more than twice b or the contrary because at best you remove two for one
        //also yes if a+b is already 0
        if(((a+b)%3==0 && (float)a/(float)b >= 0.5 && (float)a/(float)b <= 2) || (a==0&&b==0)){
            std::cout << "YES ";
        }else{
            std::cout << "NO ";
        }
    }
    return 0;
}