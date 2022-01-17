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
		y, x index of the cases visited by current path -> origin (0,0) at the top left.
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

	/*
		column completness count
		line completness count
		if a column/line is complete (=MATRICE_SIZE), any column/line on the side opposite to the end
		of the complete column/line must be complete too cause there is no path anymore to the other
		side of the complete column.
	*/
	size_t columnCount[MATRICE_SIZE];
	size_t lineCount[MATRICE_SIZE];

public:
	/*
		first grid constructor
	*/
	grid() : nbCaseVisited(1), currentX(0), currentY(0){

		for(size_t y(0); y < MATRICE_SIZE; y++){
			for(size_t x(0); x < MATRICE_SIZE; x++){
				this->visited[y][x] = 0;
			}
		}

		for (size_t i = 0; i < MATRICE_SIZE; i++){
			columnCount[i] = 0;
			lineCount[i] = 0;
		}

		/*
			set starting case to visited
		*/
		this->visited[0][0] = 1;
		this->columnCount[0]++;
		this->lineCount[0]++;
	}

	grid(grid& previousStep, size_t currentX, size_t currentY) : nbCaseVisited(previousStep.nbCaseVisited + 1), currentX(currentX), currentY(currentY){
		assert(currentX < MATRICE_SIZE);
		assert(currentY < MATRICE_SIZE);

		for(size_t y(0); y < MATRICE_SIZE; y++){
			for(size_t x(0); x < MATRICE_SIZE; x++){
				this->visited[y][x] = previousStep.visited[y][x];
			}
		}
		
		for (size_t i = 0; i < MATRICE_SIZE; i++){
			columnCount[i] = previousStep.columnCount[i];
			lineCount[i] = previousStep.lineCount[i];
		}

		/*
			set current location to visited
		*/
		this->visited[currentY][currentX] = 1;
		this->columnCount[currentX]++;
		this->lineCount[currentY]++;
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

	/**
	 * @brief check if adding a path in a specific line will block any other line from completing a path
	 * exemple : if line 2 is completed, line 1 and line 0 must be complete in order to have a valid path
	 * that goes trough every case.
	 * 
	 * @param y line number
	 * @return true if one case can be used in line @y without blocking an other line
	 */
	bool validCompletLine(size_t y) const{
		bool result(true);
		/*
			test if line[y] would be complete (=MATRICE_SIZE - 1)
			if so, verify that all line opposite to the end are complete
		*/
		if(this->lineCount[y] + 1 == MATRICE_SIZE){
			/*
				test if all line opposite to the new complete one are complete
			*/
			for(int i(y - 1); i >= 0; i--){
				if(lineCount[i] < MATRICE_SIZE){
					result = false;
				}
			}
		}
		return result;
	}

	/**
	 * @brief check if adding a path in a specific column will block any other column from completing a path
	 * exemple : if column 2 is completed, column 1 and column 0 must be complete in order to have a valid path
	 * that goes trough every case.
	 * 
	 * @param x column number
	 * @return true if one case can be used in column @x without blocking an other column
	 */
	bool validCompletColumn(size_t x) const{
		bool result(true);
		/*
			test if column[x] would be complete (=MATRICE_SIZE - 1)
			if so, verify that all column opposite to the end are complete
		*/
		if(this->columnCount[x] + 1 == MATRICE_SIZE){
			/*
				test if all column opposite to the new complete one are complete
			*/
			for(int i(x + 1); i < MATRICE_SIZE; i++){
				if(columnCount[i] < MATRICE_SIZE){
					result = false;
				}
			}
		}
		return result;
	}

	/*
		debug only
	*/
	void printPath() const{
		std::cout << "(" << this->currentX << ", " << this->currentY << ")\n";
		for(size_t x(0); x < MATRICE_SIZE; x++){
			std::cout << columnCount[x] << " ";
		}
		std::cout << "\n";
		for(size_t y(0); y < MATRICE_SIZE; y++){
			for(size_t x(0); x < MATRICE_SIZE; x++){
				if(visited[y][x]){
					std::cout << "X ";
				}else{
					std::cout << "O ";
				}
			}
			std::cout << lineCount[y] << "\n";
		}
		std::cout << "\n";
	}
};

void countPath(grid currentPath, size_t& accumulateur){
	/*
		test if current (x, y) are at the end point (0, MATRICE_SIZE - 1) and if they are test if
		all cases have been visited by current path
	*/
	if(currentPath.getCurrentY() == MATRICE_SIZE - 1 && currentPath.getCurrentX() == 0){
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
				if(currentPath.validCompletColumn(currentPath.getCurrentX()) && currentPath.validCompletLine(currentPath.getCurrentY() - 1)){
					grid nextSepTop(currentPath, currentPath.getCurrentX(), currentPath.getCurrentY() - 1);
					countPath(nextSepTop, accumulateur);
				}
			}
			if(right){
				if(currentPath.validCompletColumn(currentPath.getCurrentX() + 1) && currentPath.validCompletLine(currentPath.getCurrentY())){
					grid nextSepTop(currentPath, currentPath.getCurrentX() + 1, currentPath.getCurrentY());
					countPath(nextSepTop, accumulateur);
				}
			}
			if(down){
				if(currentPath.validCompletColumn(currentPath.getCurrentX()) && currentPath.validCompletLine(currentPath.getCurrentY() + 1)){
					grid nextSepTop(currentPath, currentPath.getCurrentX(), currentPath.getCurrentY() + 1);
					countPath(nextSepTop, accumulateur);
				}
			}
			if(left){
				if(currentPath.validCompletColumn(currentPath.getCurrentX() - 1) && currentPath.validCompletLine(currentPath.getCurrentY())){
					grid nextSepTop(currentPath, currentPath.getCurrentX() - 1, currentPath.getCurrentY());
					countPath(nextSepTop, accumulateur);
				}
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