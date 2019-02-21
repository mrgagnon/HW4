/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"
#include "Organism.h"

//int n=0; //this initial value will be changed when the program is invoked
//Cell** myGridCells_ptr_array = (Cell**)nullptr;


/** Default constructor for a Grid
 *  Defaults to 10 rows and columns
 *
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}

/** Constructor for a Grid
 * @param nSquaresOnASide Number of squares along one side, the grid will be square
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
}

/** Sets the given cell to the given occupationStatus
 * @param r Row of the cell being set
 * @param c Column of the cell being set
 * @param g OccupationStatus that the cell will be set as
 * @return True if the cell could be set
 *
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
	//return (*(myGridCells_ptr_array + r) + c)->setOccupant(g);
}


/** Retrieves the occupant at the given cell
 * @param r Row of the cell being checked
 * @param c Column of the cell being checked
 * @return Returns the occupationStatus of the cell
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
	//return (*(myGridCells_ptr_array + r) + c)->getOccupant();
}

/**
 * Helper function for checking neighboring cells, used by ants and doodlebugs
 * Increments numOpenCells and updates the array of neighbors, depending on given occupationStatus
 * @param row The row of the cell whose neighbors we are checking
 * @param col The column of the cell whose neighbors we are checking
 * @param numOpenCells The number of open neighboring cells (determined by program, pass in 0)
 * @param openCells The array of neighbors, to be updated by the program
 * @param type The type of neighbor to search for, use empty or ant
 */
void Grid::checkNeighbors(int row, int col, int* numOpenCells, neighbor* openCells, occupationStatus type) {
	//occupationStatus x = this->getCellOccupant(row, col);
	//occupationStatus y = this->getCellOccupant(row-1, col); //returning ant when should be empty

	if ((row-1) >= 0 && this->getCellOccupant(row-1, col) == type){  //up
		(*numOpenCells)++;
		(*openCells).r = row-1;
		(*openCells).c = col;
		(*openCells).isOpen = true;
	}
	if ((col+1) < n && this->getCellOccupant(row, col+1) == type){ // right
		(*numOpenCells)++;
		(*(openCells+1)).r = row;
		(*(openCells+1)).c = col+1;
		(*(openCells+1)).isOpen = true;
	}
	if ((row+1) < n && this->getCellOccupant(row+1, col) == type){ // down
		(*numOpenCells)++;
		(*(openCells+2)).r = row+1;
		(*(openCells+2)).c = col;
		(*(openCells+2)).isOpen = true;
	}
	if ((col-1) >= 0 && this->getCellOccupant(row, col-1) == type){ // left
		(*numOpenCells)++;
		(*(openCells+3)).r = row;
		(*(openCells+3)).c = col-1;
		(*(openCells+3)).isOpen = true;
	}
	printf("%i open Neighbors Found\n", *numOpenCells);
}


/**
 * Prints the current grid
 * @param num The number of squares on each side of the grid
 */
void Grid::printGrid(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			occupationStatus c = myGridCells_ptr_array[i][j].getOccupant();
			if (myGridCells_ptr_array[i][j].getOccupant() == ant) {
				std::cout <<" o" ;
				//printf(" o ");
			}
			else if (myGridCells_ptr_array[i][j].getOccupant() == doodlebug){
				//printf(" x ");
				std::cout <<" x";
			}
			else {
				std::cout <<"  ";
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

/** Deconstrucs the grid
 *  Must step through the each cell to deconstruct it
 */
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

