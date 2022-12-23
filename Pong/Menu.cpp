#include "Menu.h"

Menu::Menu(float width, float height)
{
	menuSelected = 0;

	font.loadFromFile("Pieces/tetrisFont.otf");


	//Play
	text[0].setFillColor(sf::Color::White);
	text[0].setFont(font);
	text[0].setString("Play");
	text[0].setCharacterSize(70);
	text[0].setPosition(400, 300);

	//Rules
	text[1].setFillColor(sf::Color::White);
	text[1].setFont(font);
	text[1].setString("Rules");
	text[1].setCharacterSize(70);
	text[1].setPosition(400, 400);

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; ++i)
	{
		window.draw(text[i]);
	}
}

void Menu::moveUp()
{
	menuSelected = 0;

	text[menuSelected].setFillColor(sf::Color::Blue);
	text[menuSelected + 1].setFillColor(sf::Color::White);
}
void Menu::moveDown()
{
	menuSelected = 1;

	text[menuSelected].setFillColor(sf::Color::Blue);
	text[menuSelected - 1].setFillColor(sf::Color::White);

}