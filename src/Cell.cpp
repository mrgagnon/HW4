/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include "Cell.h"
#include <stdlib.h>


/** Default constructor for Cell,
 *  Guest gets set to empty
 *
 */
Cell::Cell() {

	o = NULL;
	guest = empty;
}

/** If a cell is empty then set it to the given occupationStatus,
 * @param g
 * @return Returns true if the cell can be and has been set to the given status,
 * false if the cell was already occupied
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;

	if (guest != empty) {
		result = false;
	}

	guest = g;

	return result;
}

/** Assessor method to retrieve the occupationStatus of the cell
 * @return guest at that cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/** Removes the cell from memory
 *
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

