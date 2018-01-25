#pragma once
#include "CarInterface.h"

class Car: public CarInterface {
    public:
	Car(string myname, int myspeed) {
		cout << "In Car Constructor";
		name = myname; speed = myspeed;
	};
	~Car() {}

	/*
	*	getName()
	*
	*	Returns the name of this car.
	*/
	string getName() const; 

	/*
	*	getSpeed()
	*
	*	Returns the speed of this car.
	*/
	virtual int getSpeed() const = 0;
protected:
	string name;
	int speed;
};