#pragma once
#include "RaceInterface.h"
#include "CarInterface.h"
#include "Car.h"
#include <vector>
#include <string>

class Race: public RaceInterface
{
    private:
        vector<Car *> racecars;
    public:
	Race() {}
	~Race() {}

	/*
	*	addCar(string)
	*
	*	Adds a new car to the collection of cars in the race. 
	*
	*	Return true if a new car was added; false otherwise.
	*   The info string should have the name, type, speed
	*/
	bool addCar(string info);

	/*
	*	removeCar(string)
	*
	*	Removes the car whose name is equal to the given name.  
	*
	*	Return true if a car is removed; false otherwise.
	*/
	bool removeCar(string name);

	/*
	*	getCar(string)
	*
	*	Returns the memory address of a car whose name is equal to the given
	*	name.  Returns NULL if no fighter is found with the given name.
	*
	*	Return a memory address if a fighter is found; NULL otherwise.
	*/
	CarInterface* getCar(string name);

	/*
	*	getSize()
	*
	*	Returns the number of cars in the race.
	*
	*	Return a non-negative integer.
	*/
	int getSize() const;
};