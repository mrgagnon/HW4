/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"
#include "Grid.h"
#include "Cell.h"
#include <stdlib.h>
#include <iostream>
bool amAnt = false;

/** Default constructor for an Organism
 *
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}

/** Constructor for an Organism which sets the status of amAnt
 * @param b Boolean whether the organism is an amAnt
 */
Organism::Organism(bool b) {
	amAnt = b;

}

/**
 * Movement for organism
 * @return true if organism was able to move
 */
bool Organism::move(occupationStatus target) {
	bool status = true;
	int numOpenCells = 0;
	int* numOpenCells_ptr = &numOpenCells;

	//initializing openCells with a 'blank' neighbor struct
	neighbor blankNeighbor;
	blankNeighbor.c = -1;
	blankNeighbor.r = -1;
	blankNeighbor.isOpen = false;

	neighbor* openCells = (neighbor*)malloc(4 * sizeof(neighbor));
	for (int i=0; i<4; i++) {
		*(openCells + i) = blankNeighbor; //initializing elements for error checking
	}

	//clearing our previous location in grid
	g->setCellOccupant(row, col, empty);

	// invoking helper function to look at neighboring cells and update numOpenCells and openCells[]
	g->checkNeighbors(row, col, numOpenCells_ptr, openCells, empty);

	//if there are no open cells, row and col are not updated, and we will return false
	if (numOpenCells == 0){
		status = false;
	}

	//if we only have one option, we must iterate through openCells[] and move it to the one which is open
	else if (numOpenCells == 1){
		for (int i = 0; i < 4; i++){
			if ((*(openCells+i)).isOpen == true) {
				row = (*(openCells+i)).r;
				col = (*(openCells+i)).c;
				status = true;
			}
		}
	} // end 1 option

	else {
		int num = rand();
		num = num % numOpenCells; // random #, 0-number of possible slots
		if (num < 0 ){
			num+=numOpenCells;
		}
		int ct = 0;

		for ( int i = 0; i < 4; i++){  // right now moving to the first open spot
			if ((*(openCells+i)).isOpen) {
				if ( ct != num){
					ct++;
				}
				else {
					row = (*(openCells+i)).r;
					col = (*(openCells+i)).c;
					status = true;
				}
			}
		}
	} // end mult options


	//updating grid after movement
	printf("ant location after movement: (%i, %i)\n", row, col);

	occupationStatus self;
	if (this->isPrey()) {
		self = ant;
	}
	else {
		self = doodlebug;
	}

	g->setCellOccupant(row, col, self);

	free(openCells);

	return status;
}

bool Organism::breed() {
	//TODO breed
	return true;
}

/** Checking whether the organism is an ant or a doodlebug
 * @return True if the organism is an ant, False if it is a doodlebug
 */
bool Organism::isPrey()
{
	return amAnt;
}

/** Set the status of am Ant
 * @param b If the organism is an ant pass true, if it is a doodlebug pass false
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

/** Deconstructs the organism
 *
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

