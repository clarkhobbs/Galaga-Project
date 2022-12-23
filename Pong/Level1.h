
/*
Contains header for 1st level
*/


#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "include-usings.h"
#include <cstdlib>
#include <ctime> 


class Level1
{
public:
	Level1(); 

	void drawLevel(sf::RenderWindow& window);

	bool checkCollison(const sf::CircleShape& bullet); 

	void shoot(); 

	void moveBullets(); 

	void drawBullets(sf::RenderWindow& window); 

	void gotHit(Ship& p1, sf::RenderWindow& window);  

	bool isBulletEmpty(); 

	void clearBullets(); 

	void checkWin(sf::RenderWindow& window);  

	void moveShips(); 


private:
	vector<Ship*> mLayout;  
	vector<sf::CircleShape*> mEnemyBullets; 
};

