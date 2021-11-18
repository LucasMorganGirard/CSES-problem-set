/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    gray code https://cses.fi/problemset/task/2205
*/

#include <iostream>
#include <bitset>
#include <math.h>

int main(){
    unsigned n, total;
    std::cin >> n;
    std::bitset<16> gray;

    //total number of ways to organise n bits
    total = pow(2, n);

    //loop over each decimal number that can be stored in n bits
    //convert it to binary set and xor each bit with the next one 
    //to get the equivalent gray code
    for(unsigned i = 0; i < total; i++){
        std::bitset<16> binary(i);
        for(unsigned j = 0; j<n-1; j++){
            gray[j] = binary[j]^binary[j+1];
        }
        //last bit doesn't need to xor with next bit, because it's always 0
        gray[n-1]=binary[n-1];

        //had to substring it to remove the extra 0s
        std::cout << gray.to_string().substr(16-n) << "\n";
    }
    return 0;
}