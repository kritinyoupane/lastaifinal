#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 4.0;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;
public:
	Animation();
	Animation(int xPos, int yPos, int width, int height);
	void update(sf::Time dt);
	void applySprite(sf::Sprite& sp)const;
	void nxtUpdate();
};