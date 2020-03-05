#include "Player.h"

Player::Player()
{
	Coordinate.x = 300;
	Coordinate.y = 300;
	Velocity.x = 0;
	Velocity.y = 0;
	maxVelocity.x = 10;
	maxVelocity.y = 10;
	dampingConstant = 50;
	gravity = 9.8;
	////animations[int(AnimationIndex::walkingLeft)] = Animation(0, 1200, 300, 600);
	////animations[int(AnimationIndex::walkingRight)] = Animation(0, 0, 300, 600);
	//animations[int(AnimationIndex::flyingLeft)] = Animation(0, 1800, 300, 600);
	//animations[int(AnimationIndex::flyingRight)] = Animation(0, 600, 300, 600);
	//
}

void Player::update(sf::Time deltaTime,Server& server)
{
	this->deltaTime = deltaTime;
	//animations[int(curAnimation)].update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Velocity.y = -100;
		//curAnimation = AnimationIndex::flyingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Velocity.x = -100;
		//curAnimation = AnimationIndex::walkingLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Velocity.x = +100;
		//curAnimation = AnimationIndex::walkingRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Velocity.y = +100;
		//curAnimation = AnimationIndex::flyingRight;
	}
	handlePlayerCollision();
    updateCoordinates();
	//animations[int(curAnimation)].update(deltaTime);
	
	server.update('n', 100, getCoordinate(), 10);
	
   
	//std::cout << getCoordinate().x << "," << getCoordinate().y << std::endl;
}


void Player::updateVelocity()
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
void Player::collisionVelocity()
{
	Velocity = -Velocity*elasticConstant;
	Coordinate.x -= 10;
	Coordinate.y -= 10;
}

void Player::draw(sf::RenderWindow* window)
{
	spritePlayer.setScale(0.5, 0.5);
	spritePlayer.setPosition(getCoordinate().x, getCoordinate().y);
	std::cout << getCoordinate().x << " ," << getCoordinate().y << std::endl;

	
	//animations[int(curAnimation)].applySprite(spritePlayer);
	

}

void Player::updateCoordinates()
{
	Coordinate.x += Velocity.x * deltaTime.asSeconds();
	Coordinate.y += Velocity.y * deltaTime.asSeconds();
}

sf::Vector2f Player::getCoordinate()
{

	return sf::Vector2f(Coordinate);
}


sf::Vector2f Player::getVelocity()
{
	return sf::Vector2f(Velocity);
}

void Player::handlePlayerCollision()
{
	if (e.coolenemy.getGlobalBounds().intersects(spritePlayer.getGlobalBounds()))
	{
		collisionVelocity();
	}
	else
	{
		updateVelocity();
	}
	

		
	
}