

#include "Test.h"


void Test::testShipConstructor()
{
	Ship test;

	if (test.getPosition() == sf::Vector2f(436, 872))
	{
		cout << "Ship initialized properly. Test Passed" << endl; 
	}
	else
	{
		cout << "Ship not initialized properly. Test Failed" << endl; 
	}
}

void Test::testShipMoveLeft()
{
	Ship test;

	test.moveLeft(); 

	if (test.getPosition() == sf::Vector2f(435.6, 872))
	{
		cout << "Ship moved left properly. Test Passed" << endl;
	}
	else
	{
		cout << "Ship did not move left properly. Test Failed" << endl;
	}
}


void Test::testShipMoveRight()
{
	Ship test;

	test.moveRight();

	if (test.getPosition() == sf::Vector2f(436.4, 872))
	{
		cout << "Ship moved right properly. Test Passed" << endl;
	}
	else
	{
		cout << "Ship did not move right properly. Test Failed" << endl;
	}
}


void Test::testEnemyConstructor()
{
	Enemy test; 

	if (test.getPosition() == sf::Vector2f(0, 0))
	{
		cout << "Enemy Ship initialized properly. Test Passed" << endl;
	}
	else
	{
		cout << "Enemy Ship not initialized properly. Test Failed" << endl;
	}
}

void Test::testLevel1IsBulletEmpty()
{
	Level1 test;

	bool ans = test.isBulletEmpty(); 

	if (ans == true)
	{
		cout << "Bullet vector read properly. Test Passed" << endl; 
	}
	else
	{
		cout << "Bullet vector not read properly. Test Failed" << endl;
	}
}