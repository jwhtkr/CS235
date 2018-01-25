#pragma once
#include "CarInterface.h"
#include <string>


class Car: public CarInterface
{
    public:
	Car() {}
	virtual ~Car() {}

	/*
	*	getName()
	*
	*	Returns the name of this car.
	*/
	virtual string getName() const;

	/*
	*	getSpeed()
	*
	*	Returns the speed of this car.
	*/
	virtual int getSpeed() const;
};