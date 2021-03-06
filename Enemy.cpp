#include "Enemy.h"

Enemy::Enemy()
{
	Coordinate.x = 50;
	Coordinate.y = 50;
	Velocity.x = 0;
	Velocity.y = 0;
	maxVelocity.x = 10;
	maxVelocity.y = 10;
	dampingConstant = 50;
	gravity = 9.8;

}

void Enemy::initEnemy()
{
	cool.loadFromFile("enemy.png");
	coolenemy.setTexture(cool);
	coolenemy.setScale(0.15, 0.15);
}


void Enemy::update(sf::Time deltaTime,Client& client)
{
	this->deltaTime = deltaTime;
	//animations[int(curAnimation)].update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		Velocity.y = -100;
		//curAnimation = AnimationIndex::flyingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		Velocity.x = -100;
		//curAnimation = AnimationIndex::walkingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Velocity.x = +100;
		//curAnimation = AnimationIndex::walkingRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		Velocity.y = +100;
		//curAnimation = AnimationIndex::flyingRight;
	}
	void handlePlayerCollision(sf::RectangleShape recta);
	updateCoordinates();
	updateVelocity();
	client.getRecievedData();
	//std::cout << getCoordinate().x << "," << getCoordinate().y << std::endl;
}


void Enemy::updateVelocity()
{

	if (abs(Velocity.x) < 0.5)
	{
		Velocity.x = 0;
	}
	else
	{
		Velocity.x -= dampingConstant * deltaTime.asSeconds() * (Velocity.x / abs(Velocity.x));
	}
	if (abs(Velocity.y) < 0.5)
	{
		Velocity.y = 0;
	}
	else
	{
		Velocity.y -= gravity * 50 * deltaTime.asSeconds() * (Velocity.y / abs(Velocity.y));
	}
}
void Enemy::collisionVelocity()
{
	Velocity = -Velocity * elasticConstant;
	Coordinate.x -= 10;
	Coordinate.y -= 10;
}

void Enemy::draw(sf::RenderWindow* window)
{
	
	std::cout << getCoordinate().x << " ," << getCoordinate().y << std::endl;
	
	coolenemy.setPosition(getCoordinate().x, getCoordinate().y);
	//animations[int(curAnimation)].applySprite(spritePlayer);
	window->draw(coolenemy);

}

void Enemy::updateCoordinates()
{
	Coordinate.x += Velocity.x * deltaTime.asSeconds();
	Coordinate.y += Velocity.y * deltaTime.asSeconds();
}

sf::Vector2f Enemy::getCoordinate()
{

	return sf::Vector2f(Coordinate);
}


sf::Vector2f Enemy::getVelocity()
{
	return sf::Vector2f(Velocity);
}

void Enemy::handlePlayerCollision(sf::RectangleShape other)
{





}
