/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	chessboard and queens https://cses.fi/problemset/task/1624
*/

#include <iostream>
#include <stdlib.h>
#include <algorithm>

const int N(8);
const int NB_CASES(N*N);
char INPUT[N][N];

struct board{

    board() : nbPermut(0){
        /**
         * @brief at the start initialise each queen to a different hight so
         * when we permute this, we don't have to check for horizontal collisions
         * cause it's not part of the possibilities of permutations
         */
        for(int i(0); i < N; i++)
            queenIndex[i] = i;
    }

    size_t getNbPermut(){
        permute(0);
        return nbPermut;
    }

private:
    /**
     * @brief hight of the queens in each row
     */
    int queenIndex[8];
    int nbPermut;

    bool testQueenCollision(){
        bool noCollision(true);

        for(int i(0); i < N && noCollision; i++){
            if(INPUT[queenIndex[i]][i] == '*'){
                noCollision = false;
            }
        }

        /*
            test for diagonals collisions
        */
        for(int i(0); i < N && noCollision; i++){
            for (int j(i); j < N && noCollision; j++){
                if(i!=j){
                    if(std::abs(queenIndex[i] - queenIndex[j]) == std::abs(i - j)){
                        noCollision = false;
                    }
                }
            }
        }

        return noCollision;
    }

    /**
     * @brief basic permutation method + condition to check if valid queen combinaison
     */
    void permute(int startIdx){
        for(int i(startIdx); i < N; i++){
            std::swap(queenIndex[i], queenIndex[startIdx]);
            permute(startIdx + 1);
            std::swap(queenIndex[startIdx], queenIndex[i]);
        }
        if(startIdx == N-1){
            if(testQueenCollision())
                nbPermut++;
        }
    }
};

int main()
{
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < N; j++){
            std::cin >> INPUT[j][i];
        }
    }

    board board;
    std::cout << board.getNbPermut() << "\n";

	return 0;
}