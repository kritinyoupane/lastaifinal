#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include"Player.h"
#include"Enemy.h"
//#include"Server.h"
//#include "Client.h"


class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;
	sf::Texture map;
	sf::RectangleShape obs[100];
	sf::Sprite sprite;
	void initWindow();
	float viewWidth;
	float viewHeight, baseHeight;
	Server server;
	Client client;
	
public:

	Game(unsigned viewWidth, unsigned viewHeight, std::string Ip, bool isPlayer);
	//void initPlayer();
	void updateEvents()
	{
		while (this->window->pollEvent(this->ev))
		{
			switch (this->ev.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			}
		}
	}
	void update(sf::Time deltaTime);
	void running();
	void render();
	void arena();
	//void collision();
	Player p;
	Enemy e;
};

