#pragma once

/// <summary>
/// the source of all the problems on earth
///                animations
///              i hate them :D
///        they are horrible to program
///     theres something brown in my pants
///       and its a pile of animations
/// </summary>

class AnimationSprite :// simple animation system
    public sf::RectangleShape
{
private:

    sf::Vector2u _animationSize;// x = number of frames in the animation y = amount of animation
    sf::Vector2u _position;//the position the reader is at (index)
    sf::Vector2u _textureSize;//the resolution of the image
    sf::Vector2u _frameSize;//the resolution of a frame (a grid case)

    unsigned int _maxFrame;

    float _timePassed = 0;//the time that passed (in seconds)
    float _frameTime;//the time between each frame

    bool _frameUpdated = false; //if the frame hasa been updated
    bool _canLoop;//if true, the animation can loop
    bool _pauseAnimation;//stops updating the animation if is true

public:

                  //--------constructors---------//

    AnimationSprite();//empty animation
    AnimationSprite(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop); //not empty animation
    AnimationSprite(sf::Texture* texture, const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop); //not empty animation with texture

    ~AnimationSprite();

                    //--------getters---------//


    sf::Vector2u getAnimationSize() const;//return the size of the texture
    sf::Vector2u getAnimationPosition() const;//returns the current frame returned to the object
    sf::Vector2u getFrameSize()const; //returns the size of a frame

    float getFrameTime()const; //returns the time between eachframe

    bool isAnimationPaused()const;//returns the pause state of the animation

    sf::RectangleShape* getRectangleShapePtr();

                    //--------setters---------//


    void setAnimation(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop);//calls the constructor

    void setTexture(const sf::Texture* newTexture);//set new texture (the dimensions will acutalize automatically)
    void setFrameTime(const float& time);//set the frame time (in seconds)
    void setFrameTime(const sf::Time& time);//set the frame time

    void setAnimation(const unsigned int& animationId); //set the
    void setAnimationSize(const sf::Vector2u& animationSize);//set la size de l'animation et updateTexture
    void setAnimationFrame(const int& frame);//set the animation to a precise point

    void setAnimationCanLoop(bool canLoop);//sets the can loop state

    void setMaxFrame(int newMaxFrame);//sets the new max frame (-1 to not have a max frame)


                    //------action methods-----//


    void updateState(const float& deltaTime);//update the animation (sets the frame)
    void updateState(const sf::Time& deltaTime);//update the animation (sets the frame)

    void refreshTextureInfo();//recalculates the dimensions of the animation
    void updateTexture();//update in case of texture change


    void resetAnimation();//sets the current animation and position at 0

    void pauseAnimation();//pause the animation
    void unpauseAnimation();//pause the animation

};