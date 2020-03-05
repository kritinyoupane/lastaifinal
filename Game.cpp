#include "Game.h"


void Game::initWindow()
{
	this->VideoMode.height = 800;
	this->VideoMode.width = 800;
	this->window = new sf::RenderWindow(this->VideoMode, "Game");
	this->window->setFramerateLimit(144);
}

void Player::initPlayer()
{
	
	player1.loadFromFile("Images/player.png");
	spritePlayer.setTexture(player1);
	/*animations[int(AnimationIndex::walkingLeft)] = Animation(0, 1200, 300, 600);
	animations[int(AnimationIndex::walkingRight)] = Animation(0, 0, 300, 600);
	animations[int(AnimationIndex::flyingLeft)] = Animation(0, 1800, 300, 600);
	animations[int(AnimationIndex::flyingRight)] = Animation(0, 600, 300, 600);
*/	
}

Game::Game(unsigned viewWidth, unsigned viewHeight, std::string Ip, bool isPlayer1): server(isPlayer1 ? 11000 : 10000),
client(Ip, isPlayer1 ? 10000 : 11000)
{
   
	this->initWindow();
	this->p.initPlayer();
	this->e.initEnemy();
	this->arena();
	

}

void Game::running()
{
	sf::Clock clock;


	while (this->window->isOpen())
	{
		sf::Time deltaTime = clock.restart();
		updateEvents();
		update(deltaTime);
		render();
	}
}

void Game::update(sf::Time deltaTime)
{
	this->updateEvents();
	p.update(deltaTime,server);
	e.update(deltaTime,client);
	p.collision();
	
}




void Game::render()
{
	
	this->window->clear();
	this->window->draw(sprite);
    for (const auto& object : obs)
    {
        window->draw(object);

    }
	p.draw(window);
	this->window->draw(p.spritePlayer);
	e.draw(window);

	this->window->display();

}

void Game::arena()
{
	
	map.loadFromFile("arena.png");
	sprite.setTexture(map);
    
    for (int i = 0; i < 100; i++)
    {
        obs[i].setFillColor(sf::Color::Green);
    }
    obs[0].setPosition(755.f, 517.f);
    obs[0].setSize(sf::Vector2f(85.f, 8.f));
    obs[1].setPosition(0.f, 520.f);
    obs[1].setSize(sf::Vector2f(89.f, 9.f));
    obs[2].setPosition(0.f, 512.f);
    obs[2].setSize(sf::Vector2f(85.f, 8.f));
    obs[3].setPosition(756.f, 509.f);
    obs[3].setSize(sf::Vector2f(85.f, 8.f));
    obs[4].setPosition(0.f, 529.f);
    obs[4].setSize(sf::Vector2f(80.f, 39.f));
    obs[5].setPosition(761.f, 525.f);
    obs[5].setSize(sf::Vector2f(78.f, 39.f));
    obs[6].setPosition(0.f, 373.f);
    obs[6].setSize(sf::Vector2f(87.f, 20.f));
    obs[7].setPosition(756.f, 370.f);
    obs[7].setSize(sf::Vector2f(89.f, 20.f));
    obs[8].setPosition(756.f, 390.f);
    obs[8].setSize(sf::Vector2f(25.f, 28.f));
    obs[9].setPosition(60.f, 390.f);
    obs[9].setSize(sf::Vector2f(25.f, 28.f));
    obs[10].setPosition(118.f, 510.f);
    obs[10].setSize(sf::Vector2f(110.f, 200.f));
    obs[11].setPosition(612.f, 510.f);
    obs[11].setSize(sf::Vector2f(110.f, 200.f));
    obs[12].setPosition(225.f, 540.f);
    obs[12].setSize(sf::Vector2f(110.f, 100.f));
    obs[13].setPosition(502.f, 540.f);
    obs[13].setSize(sf::Vector2f(110.f, 100.f));
    obs[14].setPosition(335.f, 560.f);
    obs[14].setSize(sf::Vector2f(200.f, 50.f));
    obs[15].setPosition(120.f, 385.f);
    obs[15].setSize(sf::Vector2f(102.f, 29.f));
    obs[16].setPosition(614.f, 385.f);
    obs[16].setSize(sf::Vector2f(102.f, 29.f));
    obs[17].setPosition(0.f, 326.f);
    obs[17].setSize(sf::Vector2f(113.f, 8.f));
    obs[18].setPosition(0.f, 320.f);
    obs[18].setSize(sf::Vector2f(120.f, 8.f));
    obs[19].setPosition(730.f, 326.f);
    obs[19].setSize(sf::Vector2f(113.f, 8.f));
    obs[20].setPosition(725.f, 320.f);
    obs[20].setSize(sf::Vector2f(120.f, 8.f));
    obs[21].setPosition(0.f, 0.f);
    obs[21].setSize(sf::Vector2f(120.f, 250.f));
    obs[22].setPosition(720.f, 0.f);
    obs[22].setSize(sf::Vector2f(120.f, 259.f));
    obs[23].setPosition(232.f, 245.f);
    obs[23].setSize(sf::Vector2f(157.f, 43.f));
    obs[24].setPosition(450.f, 245.f);
    obs[24].setSize(sf::Vector2f(157.f, 43.f));
    obs[25].setPosition(232.f, 288.f);
    obs[25].setSize(sf::Vector2f(51.f, 35.f));
    obs[26].setPosition(560.f, 288.f);
    obs[26].setSize(sf::Vector2f(47.f, 35.f));
    obs[27].setPosition(340.f, 368.f);
    obs[27].setSize(sf::Vector2f(165.f, 23.f));
    obs[28].setPosition(360.f, 383.f);
    obs[28].setSize(sf::Vector2f(131.f, 23.f));
    obs[29].setPosition(375.f, 396.f);
    obs[29].setSize(sf::Vector2f(105.f, 23.f));
    obs[30].setPosition(368.f, 134.f);
    obs[30].setSize(sf::Vector2f(104.f, 33.f));
    obs[31].setPosition(358.f, 164.f);
    obs[31].setSize(sf::Vector2f(124.f, 13.f));
    obs[32].setPosition(349.f, 173.f);
    obs[32].setSize(sf::Vector2f(141.f, 10.f));
    obs[33].setPosition(345.f, 182.f);
    obs[33].setSize(sf::Vector2f(151.f, 8.f));
    
	
}

void Player::collision()
{
	if (spritePlayer.getGlobalBounds().intersects(e.coolenemy.getGlobalBounds()))
	{
		std::cout << "collided";
	}
}



