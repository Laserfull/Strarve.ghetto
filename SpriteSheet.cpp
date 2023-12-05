#include <SFML/Graphics.hpp>
#include <assert.h>

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(sf::RectangleShape* owner, const sf::Vector2u& spriteAmount)
{
	assert(spriteAmount.x != 0 && spriteAmount.y != 0);				

	_owner = owner;
	_spriteAmount = spriteAmount;

	if(_owner->getTexture()->getSize().x != 0 && _owner->getTexture()->getSize().y != 0)	//if texture is initialized, set sprite size
	{
		_spriteSize.x = _owner->getTexture()->getSize().x / spriteAmount.x;
		_spriteSize.y = _owner->getTexture()->getSize().y / spriteAmount.y;
	}
	else {					//set sprite size to 0,0
		_spriteSize = { 0,0 };
	}

	_position = { 0,0 };
}

SpriteSheet::SpriteSheet(sf::RectangleShape* owner, sf::Texture* texture, const sf::Vector2u& spriteAmount)
{
	assert(texture->getSize().x != 0 && texture->getSize().y != 0 && spriteAmount.x != 0 && spriteAmount.y != 0);		//assert if uninitialized
	_position = { 0,0 };
	_owner = owner;
	_owner->setTexture(texture);


	_spriteAmount = spriteAmount;

	_spriteSize.x = _owner->getTexture()->getSize().x / spriteAmount.x;
	_spriteSize.y = _owner->getTexture()->getSize().y / spriteAmount.y;

}

SpriteSheet::~SpriteSheet()
{
	_owner = nullptr;

	_spriteAmount = { 0,0 };
	_spriteSize = { 0,0 };
	_position = { 0,0 };
}

void SpriteSheet::setSpriteAmount(const sf::Vector2u& spriteAmount)
{
	assert(spriteAmount.x != 0 && spriteAmount.y != 0);

	_spriteAmount = spriteAmount;

				//find size of each sprite

	_spriteSize.x = _owner->getTexture()->getSize().x / _spriteAmount.x;
	_spriteSize.y = _owner->getTexture()->getSize().y / _spriteAmount.y;
}

void SpriteSheet::setSpritePosition(const sf::Vector2u& newPosition)
{

	_position = newPosition;

	_owner->setTextureRect(sf::IntRect(_spriteSize.x * _position.x, _spriteSize.y * _position.y, _spriteSize.x, _spriteSize.y));
}

void SpriteSheet::setSpriteSheetTexture(sf::Texture* texture)
{
	assert(texture->getSize().x != 0 && texture->getSize().y != 0);

	_owner->setTexture(texture);

				//find size of each sprite

	_spriteSize.x = _owner->getTexture()->getSize().x / _spriteAmount.x;
	_spriteSize.y = _owner->getTexture()->getSize().y / _spriteAmount.y;
}

void SpriteSheet::setSpriteSheetTexture(sf::Texture* texture, const sf::Vector2u& spriteAmount)
{
	assert(texture->getSize().x != 0 && texture->getSize().y != 0);

	_owner->setTexture(texture);

	this->setSpriteAmount(spriteAmount);
}

sf::Vector2u SpriteSheet::getSpriteAmount() const
{
	return _spriteAmount;
}

sf::Vector2u SpriteSheet::getSpriteSize() const
{
	return _spriteSize;
}

sf::Vector2u SpriteSheet::getSpritePosition() const
{
	return _position;
}
