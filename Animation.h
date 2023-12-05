#pragma once
class Animation
{
private:
	sf::Shape* _owner;

	sf::Vector2u _animationSize;
	sf::Vector2u _position;
	sf::Vector2u _frameSize;

	unsigned int _maxFrame;
	unsigned int _beginFrame;

	float _timePassed;
	float _frameTime;


	bool _canLoop;
	bool _pause;
	bool _updateAnimation;

public:


	Animation(sf::Shape* owner);
	Animation(sf::Shape* owner, sf::Texture* texture, sf::Vector2u animationSize = { 0,0 }, const float& frameTime = 0, bool canLoop = true);


	//update the animation (run this on every frame)
	void updateAnimation(const float& deltaTime);


	//updates the texture of the owner
	void updateFrame();

								//-------------------------//
							    //		   getters    	   //
							    //-------------------------//

	//returns _animationSize
	//X: the amount of frame max on the spriteSheet
	//Y: the amount of animations in the spriteSheet
	const sf::Vector2u& getAnimationSize() const;

	//returns _position 
	//X: the current frame Position
	//Y: the current animation Id
	const sf::Vector2u& getAnimationPosition() const;

	//returns _frameSize (the x/y size of a frame)
	const sf::Vector2u& getFrameSize() const;

  
	//returns _maxFrame
	unsigned int getMaxFrame() const;
	//returns _beginFrame
	unsigned int getBeginFrame() const;


	//returns _timePassed (the time that passed since the last frame update)
	const float& getTimePassed() const;

	//returns _frameTime (the time between each frame)
	const float& getFrameTime() const;


	//returns _canLoop (true if the animation can loop, false if cant)
	bool isLoop() const;

	//returns _pause (true if animation is paused, false if not)
	bool isPaused() const;

	//returns if position.x is at _maxFrame
	bool isAnimationEnd() const;

							 //-------------------------//
							 //			 setters		//
						     //-------------------------//

	//assert texture has to be initialized
	void setTexture(sf::Texture* texture);												

	//assert texture has to be initialized also sets animationSize
	void setTexture(sf::Texture* texture, const sf::Vector2u& animationSize, bool setMaxFrameAtMaxAnimation = true);

	//assert number has to be unsigned and over 0
	void setAnimationSize(const sf::Vector2u& animationSize, bool setMaxFrameAtMaxAnimation = true);

	//sets the animation on pause if true, unpause if false
	void setPause(bool pause);

	//sets if the animation can loop (true), or not (false)
	void setCanLoop(bool canLoop);

	//sets the max frame (put -1 in parameter to put at last frame (default))
	void setMaxFrame(int maxFrame = -1);

	//sets the beginning frame at the specified frame (leave empty to go to 0)
	void setBeginFrame(unsigned int beginFrame = 0);

	//sets the begin and max frame (leave empty to set delimitations to the whole animationSize)
	void setBeginMaxFrame(unsigned int beginFrame = 0, int maxFrame = -1);

	//sets the current frame (_position.x) at the specified id (assert for _animationSize.x range)
	//(does not contain asserts for _beginFrame and maxFrame so results may be unexpected, be sure to know what you are doing by using this method
	//if you want to use a safer version of this method for bug free results use setSafeFramePosition instead)
	void setFramePosition(unsigned int frameId);

	//safer version of setFramePosition (assert for animation position and _beginFrame and _maxFrame)
	void setSafeFramePosition(unsigned int frameId);

	//set the animation id (assert if outside animationSize.y range)
	void setAnimation(unsigned int animationId);

	//sets the frame time (no asserts if lower or equal to 0, animation wont update)
	void setFrameTime(const float& frameTime);


								//------------------//
							    //		action		//
								//------------------//

	//pause the animation
	void pause();
	//unpause the animation
	void unpause();

	//puts the frame back at the beginning and resets the _timePassed timer
	void resetAnimation();
};

