# CPPND: Capstone Space Invaders Game

This is the basic implementation of the space invaders game. The player is at the bottom of the screen and shoots at the aliens coming from the top of the screen. Aliens are moving towards the player and shooting as well. 
Commands for playing are: left and right arrow for moving, space for shooting.

More about the game can be found at https://en.wikipedia.org/wiki/Space_Invaders
https://gofile.io/d/x9GsY1

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeInvaders`.


## Code structure
This project implements game loop consisting of the following steps : input, update and rendering. An abstract class GameObject defines virtual function "void Update();" and saves the coordinates of the object in the game. Other classes that represent objects in the game are inherited from this one, as can be seen in the following graph.

                GameObject
            /               \
        Shooter           Bullet
      /         \
    Player      Alien

Controller is responsible for handling the user input and renderer is responsible for handling the window and drawing the game.

## Rubric points addressed with this project
* The project demonstrates an understanding of C++ functions and control structures.
	** Using while loop, if - else statements, ..
	
* The project accepts user input and processes the input.
	** Class Controller accepts left and right key, space and handles player accordingly.
	
* The project uses Object Oriented Programming techniques.
	** Classes and inheritance is explained in the graph under previous heading.
	
* Classes use appropriate access specifiers for class members.
	** All class data members are explicity specified as public, protected or private.
	
* Class constructors utilize member initialization lists.
	** This can be seen in the header files as constructors are defined there.
	
* Classes abstract implementation details from their interfaces.
	** Member functions have declarative names to document their effects.
	
* Classes follow an appropriate inheritance hierarchy.
	**As can be seen in the mentioned graph.
	
* Derived class functions override virtual base class functions.
	** GameObject has pure virtual function "void Update()" that is implemented in Alien and Player class.
	
* The project makes use of references in function declarations.
	** Instead of copying by value, data is passed by reference accross the project.

* The project uses move semantics to move data, instead of copying it, where possible.
	** unique_ptr created inside Shoot function is returned using move semantics.
	
* The project uses smart pointers instead of raw pointers.
	** Instances of the Bullet class are stored in unique_ptr.