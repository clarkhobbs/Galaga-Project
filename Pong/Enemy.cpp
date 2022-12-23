#include "Enemy.h"


Enemy::Enemy()
{
	mShipImage.loadFromFile("EnemyShip.png");

	this->setTexture(mShipImage);
	this->setScale(2, 2);
	this->setPosition(sf::Vector2f(0, 0)); 

}

sf::CircleShape* Enemy::shoot()
{
	sf::CircleShape* bullet = new sf::CircleShape(10);


	bullet->setPosition(this->getPosition().x + 54, this->getPosition().y + 132);

	return bullet;
}