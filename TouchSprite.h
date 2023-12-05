#pragma once
#include "AnimationSprite.h"

class TouchSprite : public AnimationSprite
{
public:
    ~TouchSprite();// destructor

    TouchSprite();//default constructor
    TouchSprite(const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop);//with animation constructor
    TouchSprite(sf::Texture* texture, const sf::Vector2u& gridSize, const float& frametime, const bool& canLoop);//with animation constructor and texture



    void updateState(const sf::Time& deltaTime);
    void updateState(const float& deltaTime);

    friend bool isCollision(const TouchSprite& thisObject, const sf::Shape& that);
    friend bool isCollision(const TouchSprite& thisObject, const sf::Shape* that);
    friend bool isCollision(const TouchSprite* thisObject, const sf::Shape* that);
    friend bool isCollision(const TouchSprite* thisObject, const sf::Shape& that);

    void update();
};

