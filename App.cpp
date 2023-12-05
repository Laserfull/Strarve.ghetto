#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<iostream>
#include<Windows.h>
#include<SFML/Window.hpp>

#include "App.h"



App::App()
{
				//-------get native resolution-------//

	RECT desktop;
													// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
													// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	_screenResolution.x = desktop.right;
	_screenResolution.y = desktop.bottom;
	std::cout << _screenResolution.x << std::endl << _screenResolution.y<<std::endl;

	_units.x = _screenResolution.x / 1920;
	_units.y = _screenResolution.y / 1080;

	_window = new sf::RenderWindow(sf::VideoMode::VideoMode(_screenResolution.x, _screenResolution.y), std::string("Starve.Ghetto"), sf::Style::Fullscreen);
	_event = new sf::Event;

	_keyboard = new sf::Keyboard;
	_mouse = new sf::Mouse;
}

const sf::Vector2f& App::getUnit()
{
	return _units;
}

sf::Vector2f& App::getScreenResolution()
{
	return _screenResolution;
}

sf::RenderWindow* App::getWindow()
{
	return _window;
}

sf::Event* App::getEvent()
{
	return _event;
}

sf::Keyboard* App::getKeyboard()
{
	return _keyboard;
}

sf::Mouse* App::getMouse()
{
	return _mouse;
}

sf::Vector2f App::getMousePosition()
{
	return sf::Vector2f(_mouse->getPosition())+(_window->getView().getCenter()- sf::Vector2f(_screenResolution.x/2, _screenResolution.y / 2));
}

sf::Vector2f operator/(const sf::Vector2f& left, const sf::Vector2f& right) {
	return {left.x/right.x, left.y/right.y};
}


