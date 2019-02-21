/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
class Grid;

enum occupationStatus { empty, ant, doodlebug};

class Organism {
protected:
	int row = 0;
	int col = 0;
	int lifeCounter = 0;
	Grid* g;
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	bool move(occupationStatus target);
	bool breed();
	void setAmAnt(bool b);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
