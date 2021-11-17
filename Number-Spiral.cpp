/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    number spiral https://cses.fi/problemset/task/1071
*/

#include <iostream>

int main(){
    unsigned long nbInput, x, y;
    std::cin >> nbInput;

    for(unsigned long i(0); i < nbInput; i++){
        std::cin >> y >> x;
        if(x>y){
            std::cout << (x-1)*(x-1) + (2*x-y)*(x&1) + (y)*!(x&1);
        }else{
            std::cout << (y-1)*(y-1) + (2*y-x)*!(y&1) + (x)*(y&1);
        }
        std::cout << "\n";
    }

    return 0;
}
