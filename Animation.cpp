#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(int xPos, int yPos, int width, int height)
{
	texture.loadFromFile("play.png");
	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { xPos + i * width, yPos, width, height };
	}
}

void Animation::update(sf::Time dt)
{
	time += 20 * dt.asSeconds();
	while (time >= holdTime)
	{
		time -= holdTime;
		nxtUpdate();
	}
}

void Animation::applySprite(sf::Sprite& sp) const
{
	sp.setTexture(texture);
	sp.setTextureRect(frames[iFrame]);
}


void Animation::nxtUpdate()
{
	if (++iFrame >= nFrames)
	{
		iFrame = 0;
	}
}