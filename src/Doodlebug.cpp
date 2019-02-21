/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Maylee Gagnon
 *      Updated on: Mar 12, 2019
 */

#include <stdlib.h>
#include "Doodlebug.h"
#include "Grid.h"
#include "Cell.h"

/** Default constructor for a Doodlebug
 *
 */
Doodlebug::Doodlebug() {
	g = NULL;
	// TODO Auto-generated constructor stub

}

Doodlebug::Doodlebug(int r, int c, int life, Grid* grid) {
	// TODO Auto-generated constructor stub
	row = r;
	col = c;
	lifeCounter = life;
	g = grid;
	g->setCellOccupant(row, col, ant);

}

/** Changes the location of the Doodlebug to an adjacent cell with an ant or if no ant present an adjacent cell like an ant moves
 * @return True if the Doodlebug moved
 */
bool Doodlebug::move()
{
	if (Organism::move(ant)) {
		return true;
	}
	else {
		return Organism::move(empty);
	}
}

/** If the doodlebug survives 8 time steps
 *  Starving can not breed
 *  Acts before the Ant
 * @return True if the Doodlebug bred
 */
bool Doodlebug::breed()
{
	//Look into starvation
	return Organism::breed();
}

/** Deconstructs the Doodlebug
 *
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

