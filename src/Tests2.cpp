/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Maylee Gagnon
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	if ( ok3 == true){
		puts("antsMoveTest() passed.");
	}
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();

	bool ok11 = printGridTest();
		puts ("see above print statments.");
		if (ok11 ){
			puts("printGridTest() passed.");
	}
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10  && ok11;
	return results;
}
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4, 0, myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)!=ant)
	{
		std::cout << "Cell 3,4 not set to ant" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

bool Tests2::antsMoveTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	Grid* myGrid_p = new Grid(2);
	//	Grid* myGrid_p = new Grid(2);

	std::cout << "Running the move ants test" << std::endl;

	if(myGrid_p->getCellOccupant(1, 1)!=empty) {
		std::cout << "Cell 1,1 not initially empty" << std::endl;
	}
	Ant* a1 = new Ant(1,1, 0, myGrid_p); //putting an ant into the first cell
	if(myGrid_p->getCellOccupant(1, 1)!=ant) { //checking if it was placed into cell properly
		std::cout << "Cell 1,1 not set to ant" << std::endl;
	}
	//myGrid_p->printGrid(2);

	(*a1).move(); //our ant will now move to a random cell
	if(myGrid_p->getCellOccupant(1, 1)!=empty) { //checking if it was placed into cell properly
		std::cout << "ant did not move" << std::endl;
	}
	//can check every other element for the grid if we want
	else {
		ok1 = true;
	}


	//	(*a1).move(); //we move once more, it MUST go to 1,1

	if(myGrid_p->getCellOccupant(1, 1)==ant) {
		ok2 = true;
	}

	//setting all the neighbors back to empty
	myGrid_p->setCellOccupant(1,0, ant);
	myGrid_p->setCellOccupant(0,1, ant);

	//	(*a1).move();

	if (myGrid_p->getCellOccupant(1,0)== ant || myGrid_p->getCellOccupant(0,1)== ant) { //our ant must have moved to one of these
		ok3 = true;
	}

	if (ok1 && ok2 && ok3) {
		result = true;
	}
	else {
		result = false;
	}

	//TODO free grid?

	return result;
}

bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}

bool Tests2:: printGridTest() {
	bool result = true;

	Grid* grid = new Grid(3);
	Doodlebug* b1 = new Doodlebug(0,2,0,grid);
	grid->setCellOccupant(0, 0, ant);
	grid->setCellOccupant(0, 1, empty);
	grid->setCellOccupant(0, 2, doodlebug);

	grid->setCellOccupant(1, 0, doodlebug);
	grid->setCellOccupant(1, 1, empty);
	grid->setCellOccupant(1, 2, ant);

	grid->setCellOccupant(2, 0, ant);
	grid->setCellOccupant(2, 1, ant);
	grid->setCellOccupant(2, 2, ant);

	std::cout <<"Print grid" << std::endl;
	grid->printGrid();

	std::cout <<"What it should look like" << std::endl;
	std::cout <<" o   x " << std::endl;
	std::cout <<" x   o " << std::endl;
	std::cout <<" o o o " << std::endl;

	return result;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

