#include "Slime.h"
#include "Game.h"

extern Game* gameInfo;

extern sf::Texture* slimeTexture;

Slime::Slime(const sf::Vector2f& position) :Animation(this, slimeTexture, {8,3},0.2f,true)
{
	this->setPosition(position);
	this->setSize({ 100,100 });
	this->setAnimation(0);
	this->setMaxFrame(-1);
}

void Slime::update(const float& deltaTime)
{
	this->updateAnimation(deltaTime);

	if(gameInfo->_event->KeyPressed)
	{
		if (gameInfo->getKeyboard()->isKeyPressed(sf::Keyboard::Left))
		{
			this->setAnimation(1);
			this->setMaxFrame(4);
		}
		else if (gameInfo->getKeyboard()->isKeyPressed(sf::Keyboard::Right)) {
			this->setAnimation(2);
			this->setMaxFrame(3);
		}
		else if (gameInfo->getKeyboard()->isKeyPressed(sf::Keyboard::Up)) {
			this->setAnimation(0);
			this->setMaxFrame(-1);
		}
		if (gameInfo->getKeyboard()->isKeyPressed(sf::Keyboard::Space)) {
			this->pause();
		}
		else {
			this->unpause();
		}
	}

}
