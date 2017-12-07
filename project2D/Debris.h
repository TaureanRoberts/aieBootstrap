#pragma once
#include "Entity.h"
#include "time.h"

class Debris : public Entity
{
public:
	//Prototype: Debris().
	//Description: Default constructor that holds all determined set values.
	//Precondition: Sets values of the debris and gives it its size and position.
	//Post Condition: returns the values to the shape when its name is called.
	//Protection Level: Public.
 	Debris();
	//Prototype: Debris(Vector2 pos, Vector2 scale);
	//Description: Calls in the math .lib Vector2 class and gives additional output to the debris size.
 	//Precondition: takes in a argument for the position and the scale to be seeded in the spawning process.
	//Post Condition: Gives the game a value to go to when the astroids hit the edge of the screen to reset to.
	//Protection Level: Public
	Debris(Vector2 pos, Vector2 scale);
	//Prototype: ~Debris() 
	//Description: Deconstructs the default contructor to allocate memory
	//Precondition: DeAllocates the variables called in the default constructors
	//Post Condition: Frees up memory in default constructor
	//Protection Level: Public
	~Debris();
	//Prototype: bool Move(Float deltaTime)
	//Description: Gives the debris information on movement, direction, and speed when called
	//Precondition: Takes in a float as a arguement
	//Post Condition: returns the given movement, direction, and speed
	//Protection Level: Public
	bool Move(float deltaTime);
	//Prototype: void resetRock(float deltaTime)
	//Description: Gives the astroids its reset areas to spawn and despawn from
	//Precondition: Hardsets the position for the X axis and randomizes the Y axis.
	//Post Condition: Gives the Y axis new locations for the astroids to spawn from
	//Protection Level: Public
	void resetRock(float deltaTime);
};
