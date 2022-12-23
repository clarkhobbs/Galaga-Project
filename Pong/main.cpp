/*
Authors: Andrew Edson, Clark Hobbs
Description: Plays the game chess using sfml graphics
*/

#include <SFML/Graphics.hpp>

#include "include-usings.h"
#include "Ship.h"
#include "Menu.h"
#include "Level1.h"
#include "Test.h"




int main()
{ 
	sf::RenderWindow MENU(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Galaga"); 
	Menu mainMenu(MENU.getSize().x, MENU.getSize().y);
	Test test;

	test.testShipConstructor();  
	test.testShipMoveLeft();
	test.testShipMoveRight();
	test.testEnemyConstructor();
	test.testLevel1IsBulletEmpty();

	while (MENU.isOpen())
	{
		sf::Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MENU.close();

			if (event.type == event.KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.moveUp();
					break;
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.moveDown();
					break;
				}

				if (event.key.code == sf::Keyboard::Enter)
				{
					sf::RenderWindow Play(sf::VideoMode(1000, 1000), "PLAY");
					sf::RenderWindow Rules(sf::VideoMode(800, 800), "RULES");

					int opt = mainMenu.menuPressed();

					if (opt == 0)
					{
						Ship p1;
						sf::CircleShape* bullet = nullptr;
						Level1 level;

						while (Play.isOpen())
						{
							sf::Clock clock; 

							sf::Event pEvent;
							while (Play.pollEvent(pEvent))
							{
								if (pEvent.type == sf::Event::Closed)
								{
									Play.close();
								}

								if (pEvent.type == sf::Event::KeyPressed)
								{
									if (pEvent.key.code == sf::Keyboard::Escape)
									{
										Play.close();

									}
								}
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{
								p1.moveLeft();
												}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							{
								p1.moveRight();		
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
							{
								if (bullet == nullptr)
								{
									bullet = p1.shoot();
								}
							}

							Rules.close();
							Play.clear();
							if (bullet != nullptr)
							{
								bullet->move(0, -1);

								if (bullet->getPosition().y <= 0)
								{
									bullet = nullptr; 
								}
							}
							
							float time = clock.getElapsedTime().asMicroseconds();

							if ((int)time % 100 == 0 && level.isBulletEmpty())       
							{
								level.shoot(); 
							}

							Play.draw(p1);

							if (bullet != nullptr)
							{
								bool success = false;
								Play.draw(*(bullet));
								success = level.checkCollison(*bullet);

								if (success == true)
								{
									bullet = nullptr; 
								}
							}

							level.moveShips(); 
							level.drawLevel(Play); 
							level.drawBullets(Play);  
							level.moveBullets(); 
							level.clearBullets(); 
							level.gotHit(p1, Play);  
							level.checkWin(Play); 
							

							Play.display();
						}
					}
					if (opt == 1)
					{
						while (Rules.isOpen())
						{
							sf::Event pEvent;
							while (Rules.pollEvent(pEvent))
							{
								if (pEvent.type == sf::Event::Closed)
								{
									Rules.close();
								}

								if (pEvent.type == sf::Event::KeyPressed)
								{
									if (pEvent.key.code == sf::Keyboard::Escape)
									{
										Rules.close();

									}
								}
							}
							Play.close();
							Rules.clear();
							Rules.display();
						}
					}

				}
			}
			MENU.clear();
			mainMenu.draw(MENU);
			MENU.display();
		}
	}


	return 0;
}