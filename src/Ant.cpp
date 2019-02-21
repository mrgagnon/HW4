/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Maylee Gagnon
 */

#include "Ant.h"
#include "Grid.h"
#include <stdlib.h>
#include <iostream>

/** Default constructor for an Ant
 *  Sets organism to true when created
 */
Ant::Ant()
//:Organism(true)
{
	g = NULL;

}

/** Constructor for an Ant, sets it's position based on the given location values, sets organism to true when created
 * @param r Row of the current Ant
 * @param c Col of the current Ant
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
	g = NULL;
}

/** Constructor for an Ant, sets it's position based on the given location values, sets organism to true when created
 * @param r Row of the current Ant
 * @param c Col of the current Ant
 * @param
 * @param grid Grid in which the ant lives
 */
Ant::Ant(int r, int c, int life, Grid* grid)
:Organism(true)
{
	row = r;
	col = c;
	lifeCounter = life;
	g = grid;
	g->setCellOccupant(row, col, ant);
}

/** Changes the Ant's location to an adjacent cell
 * @return bool Returns true if the Ant has moved
 */
bool Ant::move()
{
	return Organism::move(empty);
}

/** The Ant breed if it survives 3 time steps, new Ant is located in an adjacent cell (if more than one than choosen randomly)
 *  If no cell available then it does not breed
 * @ return bool returns true if the Ant has been able to breed
 */
bool Ant::breed()
{
	return Organism::breed();
}


/** Deconstructs the Ant
 *
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

