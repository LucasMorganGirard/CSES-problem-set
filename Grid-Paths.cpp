/**
 * Lucas GIRARD, L3 informatique Universite Sciences et Techniques de Nantes
 * <lucas.girard@etu.univ-nantes.fr>
 * <lucasgirard1605@gmail.com>
*/

/*
	grid paths https://cses.fi/problemset/task/1625
*/

/**
 * @file Grid-Paths.cpp
 * @author lucas
 * @brief not ready yet, needs improvements to run faster
 * needs to detect dead ends
 * @version 1
 * @date 15/01/2022
 */

#include <iostream>
#include <assert.h>	/* assert */

const size_t MATRICE_SIZE(7);
const size_t TOTAL_CASES(MATRICE_SIZE*MATRICE_SIZE);
char* INPUT;

/**
 * @brief each recursion of the function generating the path have an instance of the grid with the current
 * path. The grid is not mean to be modified, to add to the path, create a new instance of grid.
 */
class grid{
private:
	/*
		x, y index of the cases visited by current path
	*/
	bool visited[MATRICE_SIZE][MATRICE_SIZE];

	/*
		number of cases visited by current path
	*/
	const size_t nbCaseVisited;

	/*
		current position in the path
	*/
	const size_t currentX;
	const size_t currentY;

public:
	/*
		first grid constructor
	*/
	grid() : nbCaseVisited(1), currentX(0), currentY(0){

		for(size_t i(0); i < MATRICE_SIZE; i++){
			for(size_t j(0); j < MATRICE_SIZE; j++){
				this->visited[i][j] = 0;
			}
		}

		/*
			set starting case to visited
		*/
		this->visited[0][0] = 1;
	}

	grid(grid& previousStep, size_t currentX, size_t currentY) : nbCaseVisited(previousStep.nbCaseVisited + 1), currentX(currentX), currentY(currentY){
		assert(currentX < MATRICE_SIZE);
		assert(currentY < MATRICE_SIZE);

		for(size_t i(0); i < MATRICE_SIZE; i++){
			for(size_t j(0); j < MATRICE_SIZE; j++){
				this->visited[i][j] = previousStep.visited[i][j];
			}
		}

		/*
			set current location to visited
		*/
		this->visited[currentX][currentY] = 1;
	}

	size_t getCurrentX() const{
		return currentX;
	}

	size_t getCurrentY() const{
		return currentY;
	}

	size_t getNbCaseVisited() const{
		return nbCaseVisited;
	}

	bool isFreeUp() const{
		bool result(false);
		if(currentX > 0){
			result = !visited[currentX - 1][currentY];
		}
		return result;
	}
	bool isFreeRight() const{
		bool result(false);
		if(currentY < MATRICE_SIZE - 1){
			result = !visited[currentX][currentY + 1];
		}
		return result;
	}
	bool isFreeDown() const{
		bool result(false);
		if(currentX < MATRICE_SIZE - 1){
			result = !visited[currentX + 1][currentY];
		}
		return result;
	}
	bool isFreeLeft() const{
		bool result(false);
		if(currentY > 0){
			result = !visited[currentX][currentY - 1];
		}
		return result;
	}

	/*
		debug only
	*/
	void printPath(){
		for(size_t i(0); i < MATRICE_SIZE; i++){
			for(size_t j(0); j < MATRICE_SIZE; j++){
				if(visited[i][j]){
					std::cout << "X ";
				}else{
					std::cout << "O ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
};

void countPath(grid currentPath, size_t& accumulateur){
	/*
		test if 
	*/
	if(currentPath.getCurrentX() == MATRICE_SIZE-1 && currentPath.getCurrentY() == 0){
		if(currentPath.getNbCaseVisited() == TOTAL_CASES){
			accumulateur++;
		}
	}else{
		/*
			aviable paths
		*/
		bool up(false);
		bool right(false);
		bool down(false);
		bool left(false);

		bool forced(false);

		switch(INPUT[currentPath.getNbCaseVisited() - 1]){
			case 'U': 
			if(currentPath.isFreeUp()){
				up = true;
			}
			forced = true;
			break;
			case 'R': 
			if(currentPath.isFreeRight()){
				right = true;
			}
			forced = true;
			break;
			case 'D': 
			if(currentPath.isFreeDown()){
				down = true;
			}
			forced = true;
			break;
			case 'L':
			if(currentPath.isFreeLeft()){
				left = true;
			}
			forced = true;
			break;
		}

		if(!forced){
			up = currentPath.isFreeUp();
			left = currentPath.isFreeLeft();
			down = currentPath.isFreeDown();
			right = currentPath.isFreeRight();
		}

		/*
			if two way split, path is not viable
		*/
		if(!(up && down && !right && !left)&&!(!up && !down && right && left)){
			if(up){
				grid nextSepTop(currentPath, currentPath.getCurrentX() - 1, currentPath.getCurrentY());
				countPath(nextSepTop, accumulateur);
			}
			if(right){
				grid nextSepTop(currentPath, currentPath.getCurrentX(), currentPath.getCurrentY() + 1);
				countPath(nextSepTop, accumulateur);
			}
			if(down){
				grid nextSepTop(currentPath, currentPath.getCurrentX() + 1, currentPath.getCurrentY());
				countPath(nextSepTop, accumulateur);
			}
			if(left){
				grid nextSepTop(currentPath, currentPath.getCurrentX(), currentPath.getCurrentY() - 1);
				countPath(nextSepTop, accumulateur);
			}
		}
	}
}

int main(){
	size_t anwser(0);
	char forcedPath[TOTAL_CASES-1];

	for(size_t i(0); i < TOTAL_CASES-1; i++){
		std::cin >> forcedPath[i];
	}

	INPUT = forcedPath;

	grid start;
	countPath(start, anwser);

	std::cout << anwser << std::endl;
	return 0;
}