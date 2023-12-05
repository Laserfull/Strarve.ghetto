#include <SFML/Graphics.hpp>
#include <assert.h>

#include "Animation.h"

Animation::Animation(sf::Shape* owner)
{
	_owner = owner;

	_position = { 0,0 };
	_animationSize = { 0,0 };
	_frameSize = { 0,0 };

	_maxFrame = 0;
	_beginFrame = 0;

	_timePassed = 0;
	_frameTime = 0;
	
	_canLoop = false;
	_pause = false;
	_updateAnimation = false;
}

Animation::Animation(sf::Shape* owner, sf::Texture* texture, sf::Vector2u animationSize, const float& frameTime, bool canLoop)
{
	_owner = owner;

	_position = { 0,0 };
	this->setTexture(texture, animationSize);

	_beginFrame = 0;

	_timePassed = 0;
	_frameTime = frameTime;

	_canLoop = canLoop;
	_pause = false;
	_updateAnimation = false;
}

void Animation::updateAnimation(const float& deltaTime)
{
	if (!_pause && _frameTime > 0 && (_animationSize.x > 0 && _animationSize.y > 0)) {		//if not paused && if time is initialized && if animationSize is initialized 

		_timePassed += deltaTime;	//adds the time passed to the timer

		while (_timePassed >= _frameTime) {								//as long as the frame needs to be updated;

			_timePassed -= _frameTime;									//one less frame

			if(_position.x + 1 < _animationSize.x && _position.x < _maxFrame)		//if the position of the current frame is withing sprite sheet and the max frame
			{
				_position.x++;
				_updateAnimation = true;
			}
			else if (_canLoop) {													//if you are at the end of the animation and can loop, loop back to pos 0
				_position.x = _beginFrame;
				_updateAnimation = true;
			}
			else {
				break;				//exit the loop 
			}
		}

		if (_updateAnimation) {		//if the frame needs to update, update the frame
			this->updateFrame();
		}

	}
}

void Animation::updateFrame()
{
	_owner->setTextureRect(sf::IntRect(_position.x * _frameSize.x, _position.y * _frameSize.y, _frameSize.x, _frameSize.y));		//update the frame
	_updateAnimation = false;		//mark the frame has been updated
}

const sf::Vector2u& Animation::getAnimationSize() const
{
	return _animationSize;
}

const sf::Vector2u& Animation::getAnimationPosition() const
{
	return _position;
}

const sf::Vector2u& Animation::getFrameSize() const
{
	return _frameSize;
}

unsigned int Animation::getMaxFrame() const
{
	return _maxFrame;
}

unsigned int Animation::getBeginFrame() const
{
	return _beginFrame;
}

const float& Animation::getTimePassed() const
{
	return _timePassed;
}

const float& Animation::getFrameTime() const
{
	return _frameTime;
}

bool Animation::isLoop() const
{
	return _canLoop;
}

bool Animation::isPaused() const
{
	return _pause;
}

bool Animation::isAnimationEnd() const
{
	return _position.x == _maxFrame;
}

void Animation::setTexture(sf::Texture* texture)
{
	assert(texture->getSize().x > 0 && texture->getSize().y > 0);		//texture has to be initialized
	
	_owner->setTexture(texture);		//set the new texture

	if(_animationSize.x > 0 && _animationSize.y > 0)		//only if animation size is initialized
	{
		this->setAnimationSize(_animationSize);
	}
}

void Animation::setTexture(sf::Texture* texture, const sf::Vector2u& animationSize, bool setMaxFrameAtMaxAnimation)
{
	assert(texture->getSize().x > 0 && texture->getSize().y > 0);				//texture has to be initialized

	_owner->setTexture(texture);												//set the new texture
	this->setAnimationSize(animationSize, setMaxFrameAtMaxAnimation);			//set animation size (x/y has to be greater than 0)
}

void Animation::setAnimationSize(const sf::Vector2u& animationSize, bool setMaxFrameAtMaxAnimation)
{
	assert(animationSize.x > 0 && animationSize.y > 0);		//animationSize has to be greater than 0

	_animationSize = animationSize;

	_frameSize.x = _owner->getTexture()->getSize().x / animationSize.x;
	_frameSize.y = _owner->getTexture()->getSize().y / animationSize.y;

	if (setMaxFrameAtMaxAnimation) { //if set at max frame is at true set max frame at end of animation
		_maxFrame = _animationSize.x - 1;
	}
}

void Animation::setPause(bool pause)
{
	_pause = pause;
}

void Animation::setCanLoop(bool canLoop)
{
	_canLoop = canLoop;
}

void Animation::setMaxFrame(int maxFrame)
{
	assert(maxFrame == -1 || (maxFrame >= _beginFrame && maxFrame < _animationSize.x) && _animationSize.x > 0);	//assert if begin frame is higher than max frame

	if (maxFrame == -1) {					//puts it at last frame
		_maxFrame = _animationSize.x - 1;
	}
	else {								//specified value
		_maxFrame = maxFrame;
	}
}

void Animation::setBeginFrame(unsigned int beginFrame)
{
	assert(beginFrame <= _maxFrame);	//assert if begin frame is higher than max frame

	_beginFrame = beginFrame;
}

void Animation::setBeginMaxFrame(unsigned int beginFrame, int maxFrame)
{
	assert(beginFrame <= maxFrame || (maxFrame == -1 && beginFrame < _animationSize.x) && maxFrame < _animationSize.x && _animationSize.x > 0);		// min frame has to be lower than max frame and both have to be in animationsize

	if (maxFrame == -1) {
		_maxFrame = _animationSize.x - 1;
	}
	else {
		_maxFrame = maxFrame;
	}
	_beginFrame = beginFrame;
}

void Animation::setFramePosition(unsigned int frameId)
{
	assert(frameId < _animationSize.x);

	_position.x = frameId;
}

void Animation::setSafeFramePosition(unsigned int frameId)
{
	assert(frameId >= _beginFrame && frameId <= _maxFrame);

	this->setFramePosition(frameId);
}

void Animation::setAnimation(unsigned int animationId)
{
	assert(animationId < _animationSize.y);

	_position.y = animationId;

	this->updateFrame();
}

void Animation::setFrameTime(const float& frameTime)
{
	_frameTime = frameTime;
}

void Animation::pause()
{
	_pause = true;
}

void Animation::unpause()
{
	_pause = false;
}

void Animation::resetAnimation()
{
	_timePassed = 0;
	_position.x = _beginFrame;
}

