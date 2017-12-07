#pragma once
#include "Entity.h"
#include "Debris.h"

class Player2D : public Entity
{
public:
	//Prototype: Player2D()
	//Description: Default constructor for player variables needed for game functions
	//Precondition: Sets the position and size of the ship to be feed in to the game
	//Post Condition: returns the set value when called in the function
	//Protection Level: Public
	Player2D();
	//Prototype: ~Player2D()
	//Description: Deconstructs the Player variables for Player2D functionality
	//Precondition: Takes in the functionality of the default constructor
	//Post Condition: Frees ram in the default
	//Protection Level: Public
	~Player2D();
	//Prototype: void Update(float deltaTime)
	//Description: Updates the player's position, speed, and boundries
	//Precondition: gives the player's ship its position, speed, and boundries
	//Post Condition: Feeds the information into the main function and allows movement properties
	//Protection Level: Public
	void Update(float deltaTime);
	//Prototype: bool isAlive
	//Description: the condition controls the losing condition when the player is dead it causes game over status
	//Precondition: checks to see if the player is still alive
	//Post Condition: if the player doesnt make the time limit and dies, game over
	//Protection Level: Public
	bool isAlive;
};