#pragma once


// returns an angle from a vector of distances
float findAngle(sf::Vector2f distance);

// returns an angle from a radiant value
float findAngle(float orientation);

// returns the radiant value of a vector of distance
float findOrientation(sf::Vector2f distance);

// returns the radiant value of an angle
float findOrientation(float angle);


// returns a vector of 2 floats from a radiant value and a distance
sf::Vector2f rotateVectorRadiant(float orientation, float distance);

// returns a vector of 2 floats from an angle and a distance
sf::Vector2f rotateVectorAngle(float angle, float distance);


//returns a random number by value
int getRandom(int minimum, int maximum);				
