/*
Contains the code for a falling piece
*/

#include "Ship.h"


Ship::Ship() 
{
	mShipImage.loadFromFile("spaceShip.png"); 

	this->setTexture(mShipImage);
	this->setScale(2, 2); 
	this->setPosition(WINDOW_WIDTH / 2 - 64, WINDOW_HEIGHT - 128); 
}


void Ship::moveLeft()  
{
	if (this->getPosition().x > 0)
	{
		this->move(-0.4, 0);
	}
}

void Ship::moveRight()
{
	if (this->getPosition().x < WINDOW_WIDTH - 128)
	{
		this->move(0.4, 0);
	}
}

sf::CircleShape* Ship::shoot()
{
	sf::CircleShape* bullet = new sf::CircleShape(10);


	bullet->setPosition(this->getPosition().x + 54, this->getPosition().y);    
	
	return bullet; 
}

