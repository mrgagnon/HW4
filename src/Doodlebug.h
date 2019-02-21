/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include <stdlib.h>
#include "Organism.h"
#include "Grid.h"
#include "Cell.h"

class Doodlebug: public Organism {
private:
/*	int row = 0;
	int col = 0;
	int lifeCounter = 0;
	Grid* g;*/
public:
	Doodlebug();
	Doodlebug(int r, int c, int life, Grid* grid);
	bool move();
	bool breed();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
