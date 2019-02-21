/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"

int timestepsLeft=100;

/** Constructor for production
 *
 */
Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	int timestepsLeft = 100; //initialize available timesteps
}

/** Runs through the timesteps
 *
 */
bool Production::runProduction()
{
	bool result = true;
	while(timestepsLeft-- > 0)
	{
		//dbs.step;
		//ants.step;
	}
	return result;
}

/** Deconstructs the production
 *
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

