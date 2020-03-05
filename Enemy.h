#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include "Client.h"
class Enemy
{
	sf::RenderWindow window;
	sf::Vector2f Coordinate;
	sf::Vector2f Velocity;
	sf::Vector2f maxVelocity;
	sf::Vector2f targetVelocity;
	float dampingConstant;
	double gravity;
	sf::Time deltaTime;
	
	//sf::RectangleShape spritePlayer;
	float elasticConstant;
	//Animation animations[int(AnimationIndex::MaxCount)];
	//AnimationIndex curAnimation = AnimationIndex::walkingLeft;
public:
	Enemy();
	void initEnemy();
	sf::Texture cool;
	sf::Sprite coolenemy;
	void update(sf::Time deltaTime,Client& client);
	sf::Vector2f getCoordinate();
	sf::Vector2f getVelocity();
	void handlePlayerCollision(sf::RectangleShape other);
	void updateCoordinates();
	void updateVelocity();
	void collisionVelocity();
	void collision();
	void draw(sf::RenderWindow* window);
};

