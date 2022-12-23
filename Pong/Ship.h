/*
Contains base class code for pieces of tetris
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "include-usings.h"

class Ship : public sf::Sprite
{
public:
	Ship();

	void moveLeft();

	void moveRight();

	virtual sf::CircleShape* shoot(); 

protected:

	sf::Texture mShipImage; 

};