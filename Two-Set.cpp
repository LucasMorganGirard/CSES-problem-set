/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    two set https://cses.fi/problemset/task/1092
*/

#include <iostream>
#include <math.h>       /* ceil */
#include <vector>

int main(){
    unsigned long n, sumSet1(0);
    double sum, half;
    std::vector<unsigned> set1, set2;
    std::cin >> n;
    sum = (n+1)*n/2.0; 
    half = sum/2.0;
    
    //first set : add number until = half, the rest form the second set
    //if half is integer
    if(ceil(half)==half){
        
        std::cout << "YES\n";

        for(unsigned i(n); i > 0; i--){
            if(sumSet1+i<=half){
                set1.push_back(i);
                sumSet1+=i;
            }else{
                set2.push_back(i);
            }
        }

        std::cout << '\n' << set1.size() << '\n';
        for(unsigned x : set1){
            std::cout << x << ' ';
        }
        std::cout << '\n' << set2.size() << '\n';
        for(unsigned x : set2){
            std::cout << x << ' ';
        }

    }else{
        std::cout << "NO";
    }

    return 0;
}
