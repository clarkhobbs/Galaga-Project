/*
Contains the header for enemy ships
*/



#pragma once

#include <SFML/Graphics.hpp>
#include "Ship.h"


class Enemy : public Ship
{
public:
	Enemy(); 

	sf::CircleShape* shoot(); 
};


