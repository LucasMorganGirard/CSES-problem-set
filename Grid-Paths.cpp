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
 * @brief works but not realy fast yet, I could add more dead end detection
 * @version 2
 * @date 25/01/2022
 */

#include <iostream>

const size_t MATRICE_SIZE(7);
const size_t TOTAL_CASES(MATRICE_SIZE*MATRICE_SIZE);
char* INPUT;
size_t RESULT;

size_t DEBUG_ACC(0);

/**
 * @brief store the current path, its lenght and the current position.
 * Can check itself to see wich way is free. Offers methods to change the path.
 */
class grid{
private:
	/*
		y, x index of the cases visited by current path -> /!\ origin (0,0) at the TOP LEFT.
	*/
	bool visited[MATRICE_SIZE][MATRICE_SIZE];

	/*
		number of cases visited by current path
	*/
	size_t nbCaseVisited;

	/*
		current position in the path
	*/
	size_t currentX;
	size_t currentY;

public:
	/**
	 * @brief Construct a new grid object
	 * Set the path to its initial state.
	 */
	grid() : nbCaseVisited(1), currentX(0), currentY(0){
		for(size_t y(0); y < MATRICE_SIZE; y++){
			for(size_t x(0); x < MATRICE_SIZE; x++){
				this->visited[y][x] = 0;
			}
		}

		/*
			set starting case to visited
		*/
		this->visited[0][0] = 1;
	}

	size_t getNbCaseVisited() const{
		return nbCaseVisited;
	}

	bool isFreeUp() const{
		bool result(false);
		if(currentY > 0){
			if(!visited[currentY - 1][currentX]){
				result = true;
			}

		}
		return result;
	}

	bool isFreeRight() const{
		bool result(false);
		if(currentX < MATRICE_SIZE - 1){
			if(!visited[currentY][currentX + 1]){
				result = true;
			}
		}
		return result;
	}

	bool isFreeDown() const{
		bool result(false);
		if(currentY < MATRICE_SIZE - 1){
			if(!visited[currentY + 1][currentX]){
				result = true;
			}
		}
		return result;
	}

	bool isFreeLeft() const{
		bool result(false);
		if(currentX > 0){
			if(!visited[currentY][currentX - 1]){
				result = true;
			}
		}
		return result;
	}

	void goUp(bool forward){
		goDirection(forward, 0, -1);
	}

	void goRight(bool forward){
		goDirection(forward, 1, 0);
	}

	void goDown(bool forward){
		goDirection(forward, 0, 1);
	}

	void goLeft(bool forward){
		goDirection(forward, -1, 0);
	}

	void goDirection(bool forward, size_t x, size_t y){
		if(forward){
			this->nbCaseVisited++;
		}else{
			this->nbCaseVisited--;
			this->visited[currentY][currentX] = 0;
		}
		this->currentX += x;
		this->currentY += y;
		visited[currentY][currentX] = 1;
	}

	/**
	 * @brief test if the two cases around the end are blocking it.
	 * /!\ do not use, add time
	 * 
	 * @return true if the end is blocked
	 * @return false otherwise 
	 */
	bool blockedEnd(){
		return this->visited[MATRICE_SIZE - 2][0] && this->visited[MATRICE_SIZE - 1][1] && this->nbCaseVisited != TOTAL_CASES-1;
	}

	/**
	 * @brief test if current (x, y) are at the end point (0, MATRICE_SIZE - 1) and if they are test if
	 * all cases have been visited by current path
	*/
	bool isDone() const{
		return this->currentY == MATRICE_SIZE - 1 && this->currentX == 0;
	}

	/*
		debug only
	*/
	void printPath() const{
		std::cout << "(" << this->currentX << ", " << this->currentY << ")\n";

		std::cout << "\n";
		for(size_t y(0); y < MATRICE_SIZE; y++){
			for(size_t x(0); x < MATRICE_SIZE; x++){
				if(visited[y][x]){
					std::cout << "X ";
				}else{
					std::cout << "O ";
				}
			}
		}
		std::cout << "\n";
	}
};

void countPath(grid& path){
	DEBUG_ACC++;
	/*
		test if current (x, y) are at the end point (0, MATRICE_SIZE - 1) and if they are test if
		all cases have been visited by current path
	*/
	if(path.isDone()){
		if(path.getNbCaseVisited() == TOTAL_CASES){
			RESULT++;
		}
		return;
	}

	/*
		aviable paths
	*/
	bool up(false);
	bool right(false);
	bool down(false);
	bool left(false);
	bool forced(false);
	switch(INPUT[path.getNbCaseVisited() - 1]){
		case 'U': 
		if(path.isFreeUp()){
			up = true;
		}
		forced = true;
		break;
		case 'R': 
		if(path.isFreeRight()){
			right = true;
		}
		forced = true;
		break;
		case 'D': 
		if(path.isFreeDown()){
			down = true;
		}
		forced = true;
		break;
		case 'L':
		if(path.isFreeLeft()){
			left = true;
		}
		forced = true;
		break;
	}
	
	if(!forced){
		up = path.isFreeUp();
		left = path.isFreeLeft();
		down = path.isFreeDown();
		right = path.isFreeRight();
	}
	/*
		if two way split, path is not viable
	*/
	if((up && down && !right && !left))
		return;

	if((!up && !down && right && left))
		return;

	if(up){
		path.goUp(true);
		countPath(path);
		path.goDown(false);
	}
	if(right){
		path.goRight(true);
		countPath(path);
		path.goLeft(false);
	}
	if(down){
		path.goDown(true);
		countPath(path);
		path.goUp(false);
	}
	if(left){
		path.goLeft(true);
		countPath(path);
		path.goRight(false);
	}
}

int main(){
	RESULT = 0;
	char forcedPath[TOTAL_CASES-1];

	for(size_t i(0); i < TOTAL_CASES-1; i++){
		std::cin >> forcedPath[i];
	}

	INPUT = forcedPath;

	grid path;
	countPath(path);

	std::cout << RESULT << std::endl;
	return 0;
}