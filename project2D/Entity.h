#pragma once
#include <Vector_2.h>
#include <ListType.h>

class Entity
{
public:
	//Prototype: Entity()
	//Description: Handles the Vector/Matrix classes when its child class is called
	//Precondition: handles the Vector/Matrix classes
	//Post Condition: returns places for used calls
	//Protection Level: Public
	Entity();
	//Prototype: ~Entity()
	//Description: Deconstructs the information given on in the default
	//Precondition: Takes in the default construture
	//Post Condition: deallocates memory
	//Protection Level: Public
	~Entity();
	//Prototype: Vector2 mScale
	//Description: Sets the size of a object or item
	//Precondition: takes in a X and Y scale to size upon
	//Post Condition: Returns its size given
	//Protection Level: Public
	Vector2 mScale;
	//Prototype: Vector2 mPos
	//Description: Gives cordinates to use for placement of debris and player classes
	//Precondition: takes in two values and gives a X & Y axis for placement
	//Post Condition: returns the positon 
	//Protection Level: Public
	Vector2 mPos;
};