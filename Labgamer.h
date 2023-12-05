#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Platform.h"
#include "MurWarning.h"

class Labgamer :public sf::RectangleShape, private Animation, private Platform
{
	enum directions{UP,DOWN,LEFT,RIGHT};

	directions _dir;

	MurWarning _warning;

	sf::Font _font;

public:
	Labgamer(sf::Texture* texture);

	void update(float deltaTime);

	const sf::Vector2f& getPosition();

	void draw(sf::RenderWindow* window);
};

