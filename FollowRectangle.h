#pragma once
#include<SFML/Graphics/RectangleShape.hpp>

class FollowRectangle :
    public sf::RectangleShape
{
private:
    sf::RectangleShape* _owner;

public:
    FollowRectangle();// default constructor (owner = nullptr)
    FollowRectangle(sf::RectangleShape* owner);//constructor with preset owner

    void setOwner(sf::RectangleShape* owner);//sets the scroll position owner

    void updatePosition();//goes to the present owner position
    void updatePosition(sf::RectangleShape* scrollTo);//goes to a specified owner position
};

