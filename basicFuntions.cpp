#include <SFML/Graphics.hpp>
#include "basicFuntions.h"


float findAngle(sf::Vector2f distance)
{
	return ((findOrientation(distance) * 180) / 3.14159);
}

float findAngle(float orientation)
{
	return ((orientation * 180) / 3.14159);
}

float findOrientation(sf::Vector2f distance)
{
	return atan2f(-distance.y, -distance.x);
}

float findOrientation(float angle) {
	return angle * 3.14159 / 180;
}

sf::Vector2f rotateVectorRadiant(float orientation, float distance)
{
	return sf::Vector2f(cos(orientation), sin(orientation)) * distance;
}

sf::Vector2f rotateVectorAngle(float angle, float distance)
{
	float orientation = findOrientation(angle);
	return sf::Vector2f(cos(orientation), sin(orientation)) * distance;
}

int getRandom(int minimum, int maximum)
{
	return rand() % (maximum + 1 - minimum) + minimum;
}
