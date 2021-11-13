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
    unsigned currentConsecNbOfChar(1), maxConsecNbOfChar(0);
    std::string str;
    std::cin >> str;
    char previousChar(' ');

    for (char& currentChar : str)
    {
        if(currentChar == previousChar){
            currentConsecNbOfChar++;
        }else{
            currentConsecNbOfChar = 1;
        }

        if(currentConsecNbOfChar > maxConsecNbOfChar){
            maxConsecNbOfChar = currentConsecNbOfChar;
        }
        
        previousChar = currentChar;
    }
    
    std::cout << maxConsecNbOfChar;
}