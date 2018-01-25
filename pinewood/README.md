# Pinewood derby simulation program
If you have worked with Cub Scouts, you know they get really excited about the pinewood derby race.  If your Cub Scout Pack is low on funds, they probably only have a 2 lane track and so you will have to race each pair of cars against each other to determine the winner.  Some cars have rockets on them, some cars have big stuffed animals on top that increase the wind resistance, but all of them need to be kept in the race conainer.  Build an application to simulate a pinewood derby race.

<img src="https://upload.wikimedia.org/wikipedia/commons/b/be/PinewoodFinish.jpg" width="200">

1. First, lets design our application.  What are the objects and what are the "isa" and "hasa" relationships?
  * Our main has a pointer to a Race.  You will need to create a new Race object that should inherit from the RaceInterface abstract class.
  * You should have a rocket and panda car classes that inherit from the CarInterface abstract class.
  * Practice drawing the UML diagram for your application.
2. Now add the functions that will be needed for each of these objects
3. Once you have the UML document, you can start creating concrete classes that inherit from your abstract classes.
  * Create a concrete class for Race that inherits from RaceInterface, put it in Race.h  Put the implementation in Race.cpp
  * Create a concrete class for Car that inherits from CarInterface, put it in Car.h Put the implementation in Car.cpp
  * Create a concrete class for Rocket that inherits from Car.h Put it in Rocket.h Put the implementation in Rocket.cpp
  * Create a concrete class for Panda that inherits from Car.h Put it in Panda.h Put the implementation in Panda.cpp
4. Now you have finished the design, lets go to the [implementation](V1/README.md)
