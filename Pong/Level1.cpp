

#include "Level1.h"


Level1::Level1()
{
	int xPos = 0;

	while (xPos <= 880)
	{
		Enemy* newEnemy = new Enemy;

		newEnemy->setPosition(xPos, 100);

		mLayout.push_back(newEnemy);

		xPos += 220;
	}
}

void Level1::drawLevel(sf::RenderWindow& window)
{
	int index = 0;

	while (index < 5)
	{
		if (mLayout[index] != nullptr)
		{
			window.draw(*mLayout[index]);
		}

		++index;
	}
}

bool Level1::checkCollison(const sf::CircleShape& bullet)
{
	int index = 0;
	bool success = false;

	while (index < 5)
	{
		if (mLayout[index] != nullptr)
		{
			if (mLayout[index]->getGlobalBounds().intersects(bullet.getGlobalBounds()))
			{
				mLayout[index] = nullptr;
				success = true;
				return success;
			}
		}
		++index;
	}
}

void Level1::shoot()
{
	srand(time(NULL));

	int index = rand() % 6;

	mEnemyBullets.clear();

	while (index < 5)
	{
		if (mLayout[index] != nullptr)
		{
			mEnemyBullets.push_back(mLayout[index]->shoot());
		}
		++index;
	}
}

void Level1::moveBullets()
{
	srand(time(NULL));

	int index = 0;
	int end = mEnemyBullets.size();

	if (!mEnemyBullets.empty())
	{
		while (index < end)
		{
			mEnemyBullets[index]->move(0, .8);
			++index;
		}
	}
}

void Level1::drawBullets(sf::RenderWindow& window)
{

	int index = 0;
	int end = mEnemyBullets.size();

	if (!mEnemyBullets.empty())
	{
		while (index < end)
		{
			window.draw(*mEnemyBullets[index]);
			++index;
		}
	}
}

void Level1::gotHit(Ship& p1, sf::RenderWindow& window)
{
	int index = 0;
	int end = mEnemyBullets.size();

	if (!mEnemyBullets.empty())
	{
		while (index < end)
		{
			if (mEnemyBullets[index]->getGlobalBounds().intersects(p1.getGlobalBounds()))
			{
				std::cout << "Game Over Hit By Enemy" << std::endl;
				window.close();
			}
			++index;
		}
	}
}


bool Level1::isBulletEmpty()
{
	return mEnemyBullets.empty();
}

void Level1::clearBullets()
{
	if (!mEnemyBullets.empty())
	{
		if (mEnemyBullets[0]->getPosition().y >= 1000)
		{
			mEnemyBullets.clear();
		}
	}
}


void Level1::checkWin(sf::RenderWindow& window)
{
	int index = 0;

	while (index < 5)
	{
		if (mLayout[index] != nullptr)
		{
			return;
		}
		++index;
	}

	window.close();
	std::cout << "ALL SHIPS GONE     YOU WON!!!!!!!" << std::endl;


}


void Level1::moveShips()
{
	int index = 0;

	while (index < 5)
	{
		int direction = rand() % 4 + 1;
		if (mLayout[index] != nullptr)
		{
			switch (direction)
			{
			case 1:
				if (mLayout[index]->getPosition().x <= 878)
				{
					mLayout[index]->move(.1, 0);
				}
				break;
			case 2:
				if (mLayout[index]->getPosition().x >= 0)
				{
					mLayout[index]->move(-.1, 0);
				}
				break;
			case 3:
				if (mLayout[index]->getPosition().y <= 450)
				{
					mLayout[index]->move(0, .1);
				}
				break;
			case 4:
				if (mLayout[index]->getPosition().y >= 0)
				{
					mLayout[index]->move(0, -.1);
				}
				break;
			}
		}
		++index;
	}
}