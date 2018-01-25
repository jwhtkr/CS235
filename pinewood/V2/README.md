# pinewood derby simulation program
## Finishing the implementation
1. First we need to fill in the Race.h functions, lets start with addCar.  We wil use stringstream to parse the Name Type speed string we received.  Then we create a car of the specified type and push it into our vector.
  ```
bool Race::addCar(string info) {
  	stringstream ss(info);
	string name, type;
	int speed;
		
	if (ss >> name >> type >> speed) {
	  cout << "addCar got "<<name<<" "<<type<<" "<<speed<<endl;
		if (type == "R") { /* Rocket */
			cout << "Adding Rocket"<<endl;
			carVec.push_back(new Rocket(name, speed));
		}
		else if (type == "P") { /* Panda */
		  cout << "Adding Panda"<<endl;
			carVec.push_back(new Panda(name, speed));
		}
		else {
			return false; //not a valid type of car
		}
		return true;
	}
	return false; //invalid input, not enough tokens or wrong input type
}
  ```
2. The next function to fill in is removeCar.  We will be passed a name.  When we find it, call erase with the iterator corresponding to the position of the car.

  ```
bool Race::removeCar(string name) {
    for (int i = 0; i < carVec.size(); i++) {
		if (carVec.at(i)->getName() == name) {
			carVec.erase(carVec.begin() + i);
			return true;
		}
    }
    return false;
}
  ```
3. We fill in getCar by searching through the vector until we find a car with the same name.
  ```
  
CarInterface* Race::getCar(string name) {
	for (Car* cp : carVec) {
		if (cp->getName() == name) {
			return cp;
		}
	}
	return NULL;
}
  ```

4. Now your full application should be working and you should see something like this when you type "make" and "./pinewood
  ```
mjcleme:~/workspace/V2 $ ./pinewood
Start Size should be zero 0
addCar got Speedy R 20
Adding Rocket
In Car Constructor Speedy 20
Size should be 1 1
addCar got Slow P 10
Adding Panda
In Car Constructor Slow 10
Size should be 2 2
In Car getName Speedy
In Car getName Speedy
In Car getName Slow
Compare 40 5
In Car getName Speedy
Speedy Won!
In Car getName Slow
In Car getName Speedy
In Car getName Slow
Removed car2 Size should be one 1
  ```
5. If this were the lab, then you could compare this output to the expected output from the lab by redirecting the output to a file and then using sdiff to show you the differences.

  ```
  ./pinewood > myoutput.txt
  sdiff myoutput.txt key_file.txt
  ```
  You will then see a side by side comparison between your output and what was expected in the lab.
  
6. Now you will want to test your lab.  Don't rely on the TA test script, but test to make sure things are working by inserting test code into main().  You can comment your tests out when you want to compare with the key_file.  It would be really nice to be able to print out Car objects to make sure that things are working as you expect.  Remember that the Rocket and Panda both return a modified version of "speed", so it would be nice to see exactly what is there.  To do this, we are going to add an operator to "std" to allow us to directly print our cars out to "stdout".  First, put in a concrete getSpeed() function to Car.h 
 
  ```
virtual int getSpeed() const;
  ```
And add the implementation to Car.cpp

  ```
int Car::getSpeed() const {
	return (speed);
};
  ```
7. Now you can create a new Car since it is not an abstract class.  Lets add the operator to Car.h.

  ```
friend std::ostream& operator<< (std::ostream &out, const Car &mycar);
  ```
The operator returns an ostream reference and it passed two parameters (and ostream reference and a Car reference). 
8. Now add the implementation to Car.cpp
  ```
std::ostream& operator<< (std::ostream &out, const Car &ocar)
{
    // Since operator<< is a friend of the Car class, we can access Car's members directly.
    out << "Car(" << ocar.name << ", " << ocar.speed << ")";
 
    return out;
}
  ```
9. And add some test code to pinewood.cpp

  ```
#include "Car.h"
int main() {
	Car *testcar = new Car("testy", 300);
	cout << "Created a car "<<*testcar<<endl;
  ```
Now you can print out a Car anytime you have a question as to what it contains.

10. And you will want to add the "-g" flag to the compiler to allow you to debug your code when it crashes

  ```
CFLAGS=-std=c++11 -g

pinewood: pinewood.o Race.o Car.o Panda.o Rocket.o
		g++ $(CFLAGS) pinewood.o Race.o Car.o Panda.o Rocket.o -o pinewood
	
pinewood.o: pinewood.cpp Race.h
		g++ $(CFLAGS) -c pinewood.cpp
		
Race.o: Race.cpp Race.h CarInterface.h Rocket.h Panda.h RaceInterface.h Car.h
		g++ $(CFLAGS) -c Race.cpp

Car.o: Car.cpp Car.h CarInterface.h 
		g++ $(CFLAGS) -c Car.cpp
		
Panda.o: Panda.cpp Panda.h Car.h CarInterface.h 
		g++ $(CFLAGS) -c Panda.cpp
		
Rocket.o: Rocket.cpp Rocket.h Car.h CarInterface.h 
		g++ $(CFLAGS) -c Rocket.cpp

clean:
		rm pinewood.o Race.o Car.o Panda.o Rocket.o
  ```
