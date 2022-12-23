#pragma once
#include "include-usings.h"

class Menu
{
public:

	Menu(float width, float height);

	void draw(sf::RenderWindow& window);

	void moveUp();
	void moveDown();

	int menuPressed()
	{
		return menuSelected;
	}

	~Menu() {};


private:
	int menuSelected;
	sf::Font font;
	sf::Text text[2];
};