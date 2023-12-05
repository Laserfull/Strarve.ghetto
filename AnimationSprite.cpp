#include <cassert>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "TouchSprite.h"
#include "AnimationSprite.h"

using namespace sf;

AnimationSprite::AnimationSprite()
{
	_timePassed = 0;
	_textureSize = { 1,1 };
	_frameTime = 0;
	_position = { 0,0 };
	_canLoop = false;
	_animationSize = { 1,1 };
	_maxFrame = 0;
	_pauseAnimation = false;
}


AnimationSprite::AnimationSprite(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop)
{
	assert(gridSize.x > 0 && gridSize.y > 0);

	_timePassed = 0;
	_position = { 0,0 };
	_textureSize = this->getTexture()->getSize();

	if (_textureSize.x <= 0 || _textureSize.y <= 0) {
		_textureSize.x = 1;
		_textureSize.y = 1;
	}

	_animationSize = gridSize;

	_frameSize.x = _textureSize.x / _animationSize.x;
	_frameSize.y = _textureSize.y / _animationSize.y;

	_maxFrame = gridSize.x;
	_frameTime = frametime;
	
	_canLoop = canLoop;
	_pauseAnimation = false;
}

AnimationSprite::AnimationSprite(sf::Texture* texture, const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop)
{
	assert(gridSize.x > 0 && gridSize.y > 0);

	this->RectangleShape::setTexture(texture);

	_timePassed = 0;
	_position = { 0,0 };
	_textureSize = this->getTexture()->getSize();
	_animationSize = gridSize;


	_frameSize.x = _textureSize.x / _animationSize.x;
	_frameSize.y = _textureSize.y / _animationSize.y;

	_maxFrame = gridSize.x;
	_frameTime = frametime;

	_canLoop = canLoop;
	_pauseAnimation = false;

	this->updateTexture();
}

AnimationSprite::~AnimationSprite()
{
	
}

void AnimationSprite::setAnimation(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop)
{
	this->AnimationSprite::AnimationSprite(gridSize, frametime, canLoop);
}

void AnimationSprite::updateState(const float& deltaTime)
{
	
	if (_frameTime > 0 && !_pauseAnimation && (_position.x < _maxFrame || _canLoop))  //if frametime is initialized and not paused
	{
		_timePassed += deltaTime;


		while (_timePassed >= _frameTime)			//update the texture
		{
			

			if (_position.x < _animationSize.x - 1 && _position.x < _maxFrame)		//if the animation hasnt reached its end and is lower than it's max position
			{
				_frameUpdated = true;			//tells the object the texture has been updated

				_position.x++;
				_timePassed -= _frameTime;
			}
			else if (_canLoop) {			//loops the animation back if it can

				_frameUpdated = true;			//tells the object the texture has been updated
				this->resetAnimation();
				_timePassed = 0;
			}
			else {
				break;
			}
		}
	}

	if (_frameUpdated)// update the texture if the texture has been updated
	{
		this->updateTexture();
		_frameUpdated = false;
	}
	
}

void AnimationSprite::updateState(const sf::Time& deltaTime)
{
	this->updateState(deltaTime.asSeconds());
}

void AnimationSprite::refreshTextureInfo()
{
	_textureSize = this->getTexture()->getSize();
	_frameSize = { this->getTexture()->getSize().x / _animationSize.x, this->getTexture()->getSize().y / _animationSize.y };
	this->updateTexture();

}

sf::Vector2u AnimationSprite::getAnimationSize() const
{
	return _animationSize;
}
sf::Vector2u AnimationSprite::getAnimationPosition() const
{
	return _position;
}

sf::Vector2u AnimationSprite::getFrameSize() const
{
	return _textureSize;
}

float AnimationSprite::getFrameTime() const
{
	return _frameTime;
}

bool AnimationSprite::isAnimationPaused() const
{
	return _pauseAnimation;
}

sf::RectangleShape* AnimationSprite::getRectangleShapePtr()
{
	return this;
}

void AnimationSprite::setTexture(const sf::Texture* newTexture)
{
	this->RectangleShape::setTexture(newTexture);
	this->refreshTextureInfo();
	_maxFrame = _animationSize.x+1;
}

void AnimationSprite::updateTexture()
{
	this->setTextureRect(sf::IntRect(_frameSize.x * _position.x, _frameSize.y * _position.y, _frameSize.x , _frameSize.y));//set the texture pos
}

void AnimationSprite::setFrameTime(const float& time)
{
	assert(time >= 0);
	_frameTime = time;
}

void AnimationSprite::setFrameTime(const sf::Time& time)
{
	this->setFrameTime(time.asSeconds());
}

void AnimationSprite::setAnimation(const unsigned int& animationId)
{
	assert(animationId >= 0 && animationId < _animationSize.y);
	_position.y = animationId;

	this->resetAnimation();
}

void AnimationSprite::setAnimationSize(const sf::Vector2u& animationSize)
{
	_animationSize = animationSize;
	_frameSize = { this->getTexture()->getSize().x / _animationSize.x, this->getTexture()->getSize().y / _animationSize.y }; //set frame size x and y based on current texture
}

void AnimationSprite::setAnimationFrame(const int& frame)
{
	assert(frame >= 0 && frame <= _animationSize.x);

	_timePassed = 0;
	_position.x = frame;

	this->updateTexture();//update the texture
}

void AnimationSprite::setAnimationCanLoop(bool canLoop)
{
	_canLoop = canLoop;
}

void AnimationSprite::setMaxFrame(int newMaxFrame)
{
	assert(newMaxFrame <= -1 && newMaxFrame <= _animationSize.x);//max frame has to be within -1 and its amount of frame

	if (newMaxFrame == -1) { //sets it at the max
		_maxFrame = _animationSize.x + 1;
	}
	else {
		_maxFrame = newMaxFrame;
	}
}

void AnimationSprite::resetAnimation()
{
	_timePassed = 0;
	_position.x = 0;
}

void AnimationSprite::pauseAnimation()
{
	_pauseAnimation = true;
}

void AnimationSprite::unpauseAnimation()
{
	_pauseAnimation = false;
}
