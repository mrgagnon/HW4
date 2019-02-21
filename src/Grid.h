/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"
#include "Organism.h"

typedef struct {
		bool isOpen;
		int r;
		int c;
	} neighbor;

class Grid {
private:
	int n = 0;
	Cell** myGridCells_ptr_array = (Cell**)nullptr;
public:
	Grid();
	Grid(int nSquaresOnASide);
	bool setCellOccupant(int r, int c, occupationStatus g);
	occupationStatus getCellOccupant(int r, int c);
	virtual ~Grid();
	void checkNeighbors(int nrow, int ncol, int* numOpenCells_ptr, neighbor* openCells_ptr, occupationStatus x);
	void printGrid();
};

#endif /* GRID_H_ */
