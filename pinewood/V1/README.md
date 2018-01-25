# pinewood derby simulation implementation
## So, Lets get started
Your design (in UML) should look something like this
<img src="https://mjcleme.github.io/pinewood.png" width="600">

1. First, lets create the Race class in Race.h.  Here we use the notation used in the book to keep the class from being defined multiple times.  The `#ifndef RACE_H_` will protect the class from being included again if it has already been included. Notice that we inherit from RaceInterface, and include the array of Cars.  The main.cpp code will be calling addCar with a string that will create either a Panda or a Rocket, so we will include those files for future implementation.  But for now, the major addition is the vector of Car pointers.
	```c++
	#ifndef RACE_H_
	#define RACE_H_
	#include "RaceInterface.h"
	#include "CarInterface.h"
	#include "Car.h"
	#include "Rocket.h"
	#include "Panda.h"
	#include <vector>
	#include <sstream>

	class Race: public RaceInterface {
	    private:
		vector<Car*> carVec;

	    public:
		Race() {}
		~Race() {}

		bool addCar(string info); 

		bool removeCar(string name);

		CarInterface* getCar(string name);

		int getSize() const;
	};
	#endif
	```

2. And of course, we need to create Race.cpp which holds the implementation of the class functions.  I try to put all of the include files needed in the Race.h file, so the cpp file only includes the class Race.h file.  Notice that we are starting with just stubs for all of the functions.  We will fill them in later once we have the code compiling.
	```c++
	#include "Race.h"


	using namespace std;
	bool Race::addCar(string info) {
	}

	bool Race::removeCar(string name) {
	}

	CarInterface* Race::getCar(string name) {
	}

	int Race::getSize() const {
	}
	```
3. Now you need to create a Car class in Car.h that inherits from CarInterface.h.  This time, we will use the `#pragma once` notation to keep the class from being included multiple times.  Notice that we are putting the data elements for name and speed in the Car class so that the other classes that inherit from Car will not have to duplicate the declaration.  Try to remove any duplicate code from your implementation by thinking through the use cases.  These variables are "protected" instead of "private" so that subclasses can access them.  Notice that we have included a constructor that will set the "name" and "speed" class variables.
	```c++
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
	```
4. And of course, we need to include the implementation in Car.cpp.  We are implementing getName, so that subclasses wont need to duplicate code for this function.  But we make getSpeed a pure virtual function so that subclasses will have to override it to create polymorphic behavior in the subclasses. Notice that I am starting to insert testing code even though this is just a simple getter.  This will allow us to test that the polymorphism is behaving as we expect.
	```c++
	#include "Car.h"
	string Car::getName() const {
		cout << "In Car getName"<<endl;
		return name;
	};
	```
5. Now create Rocket.h which will inherit from Car.  Notice that we now have a concrete implemention of the getSpeed() function.  Also notice that we are calling teh constructor for the superclass Car from the constructor for Rocket.
	```c++
	#pragma once
	#include "Car.h"

	class Rocket:public Car {
	    public:    
	    Rocket(string pandaname, int pandaspeed):Car(pandaname,pandaspeed){};
	    ~Rocket(){};
	    int getSpeed() const;
	};
	```
6. Here is the implementation for Rocket.cpp.  Notice that in this case, we are including the full implementation of getSpeed that multiplies the parent class "speed" variable by 2.  Notice that we are putting magic numbers in defines.

	```c++
	#include "Rocket.h"
	#define SPEED_INCREASE 2
	int Rocket::getSpeed() const
	{
	    return speed*SPEED_INCREASE;
	}
	```
7.  Now we just need to do the same thing to create Panda.h
	```c++
	#pragma once
	#include "Car.h"

	class Panda: public Car {
	public:    
	    Panda(string pandaname, int pandaspeed):Car(pandaname,pandaspeed){};
	    ~Panda(){};
	    int getSpeed() const;
	};
	```
8. And Panda.cpp

	```c++
	#include "Panda.h"
	#define SPEED_DECREASE 2
	int Panda::getSpeed() const
	{
	    return speed/SPEED_DECREASE;
	}
	```
4. Now we have the basic project created, but we still have stubs in Race.cpp so we need to [finish](../V2/README.md)
