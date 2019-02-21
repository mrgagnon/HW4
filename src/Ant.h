/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"
#include <stdlib.h>

class Ant: public Organism {
private:

public:
	Ant();
	Ant(int r=0, int c = 0);
	Ant(int r, int c, int life, Grid* g);
	bool move();
	bool breed();
	 ~Ant();

};

#endif /* ANT_H_ */
