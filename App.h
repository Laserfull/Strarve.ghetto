#pragma once
#include <SFML/Graphics.hpp>


class App
{
public:

	sf::Vector2f _screenResolution;

	sf::Vector2f _units;		//measurements units

	sf::RenderWindow* _window;
	sf::Event* _event;

	sf::Keyboard* _keyboard;
	sf::Mouse* _mouse;


	App();		//app constructor

				//----------getters---------//
	const sf::Vector2f& getUnit();

	sf::Vector2f& getScreenResolution();

	sf::RenderWindow* getWindow();
	sf::Event* getEvent();
	sf::Keyboard* getKeyboard();
	sf::Mouse* getMouse();

	sf::Vector2f getMousePosition();
};

sf::Vector2f operator/(const sf::Vector2f& left, const sf::Vector2f& right);