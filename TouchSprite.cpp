#include"SFML/Graphics.hpp"
#include<vector>
#include "basicFuntions.h"
#include "AnimationSprite.h"
#include "TouchSprite.h"



TouchSprite::~TouchSprite()
{
	
}

TouchSprite::TouchSprite()
{

}

TouchSprite::TouchSprite(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop) :AnimationSprite(gridSize, frametime, canLoop)
{
}

TouchSprite::TouchSprite(sf::Texture* texture, const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop) :AnimationSprite(texture, gridSize, frametime, canLoop)
{
}

void TouchSprite::updateState(const sf::Time& deltaTime)
{
	this->updateState(deltaTime.asSeconds());
}

void TouchSprite::updateState(const float& deltaTime)
{
	this->AnimationSprite::updateState(deltaTime);
}

void TouchSprite::update()
{
	this->AnimationSprite::update();
}

bool isCollision(const TouchSprite& thisObject, const sf::Shape& that)
{
	return thisObject.getGlobalBounds().intersects(that.getGlobalBounds());
}

bool isCollision(const TouchSprite& thisObject, const sf::Shape* that)
{
	return thisObject.getGlobalBounds().intersects(that->getGlobalBounds());
}

bool isCollision(const TouchSprite* thisObject, const sf::Shape* that)
{
	return thisObject->getGlobalBounds().intersects(that->getGlobalBounds());
}

bool isCollision(const TouchSprite* thisObject, const sf::Shape& that)
{
	return thisObject->getGlobalBounds().intersects(that.getGlobalBounds());
}
