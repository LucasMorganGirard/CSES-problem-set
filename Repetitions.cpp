/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
    Repetitions https://cses.fi/problemset/task/1069
*/

#include <iostream>
#include <string>

int main(){
    unsigned current(1), max(0);
    std::string s;
    std::cin >> s;
    char previous(' ');

    for (char& c : s)
    {
        if(c==previous){
            current++;
        }else{
            current=1;
        }
        if(current>max){
            max=current;
        }
        previous = c;
    }
    
    std::cout << max;
}