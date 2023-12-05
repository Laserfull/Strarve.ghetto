#include "SFML/Graphics.hpp"

#include "FollowRectangle.h"

FollowRectangle::FollowRectangle()
{
	_owner = nullptr;
}

FollowRectangle::FollowRectangle(sf::RectangleShape* owner)
{
	_owner = owner;
}

void FollowRectangle::setOwner(sf::RectangleShape* owner)
{
	_owner = owner;
}

void FollowRectangle::updatePosition()
{
	if (_owner != nullptr) {
		this->setPosition(_owner->getPosition());
	}
}

void FollowRectangle::updatePosition(sf::RectangleShape* scrollTo)
{
	this->setPosition(scrollTo->getPosition());
}
