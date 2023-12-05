#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Slime :public sf::RectangleShape, public Animation
{


public:
	Slime(const sf::Vector2f& position);

	void update(const float& deltaTime);
};

