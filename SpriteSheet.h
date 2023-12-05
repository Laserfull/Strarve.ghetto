#pragma once
#include <SFML/Graphics.hpp>
class SpriteSheet
{
private:
	sf::RectangleShape* _owner;

	sf::Vector2u _spriteAmount;
	sf::Vector2u _spriteSize;
	sf::Vector2u _position;

public:
								//	constructors


	//default constructor
	//declare x, y amount of sprite (default x:1 y:1 full sheet)
	//assert if sprite amount is 0,0;
	SpriteSheet(sf::RectangleShape* owner, const sf::Vector2u& spriteAmount = {1,1});	

	// full constructor
	// declare texture, set it to the owner assert if texture isnt correctly initialized
	// declare x, y amount of sprite (default x:1 y:1 full sheet)
	SpriteSheet(sf::RectangleShape* owner, sf::Texture* texture, const sf::Vector2u& spriteAmount = { 1,1 });


	// default destructor with following exec
	// _owner = nullptr		_spriteAmount = {0,0}
	// _spriteSize = {0,0}		_position = {0,0}
	~SpriteSheet();


								//	setters
	

	// set the amount of sprite on the sheet assert if spriteAmount is 0,0
	// set sprite position will not work if amount or texture is not set properly
	void setSpriteAmount(const sf::Vector2u& spriteAmount);

	// sets the sprite of _owner to the new desired position
	// works by index (top left sprite is 0,0)
	// unexpected behavior may happen if out of range
	// if you get a blank/black texture, be sure to set the sprite size
	void setSpritePosition(const sf::Vector2u& newPosition);

	// assert if texture isnt initialized
	// sets the texture of _owner to the new precised texture
	// recalculates the size of each sprite depending on the current _spriteAmount
	void setSpriteSheetTexture(sf::Texture* texture);

	// assert if texture isnt initialized or sprite amount is 0,0
	// sets the texture of _owner to the new precised texture
	// recalculates the size of each sprite depending on the new specified spriteAmount
	void setSpriteSheetTexture(sf::Texture* texture, const sf::Vector2u& spriteAmount);
	

								//	getters


	//returns _spriteAmount
	sf::Vector2u getSpriteAmount() const;

	//returns _spriteSize
	sf::Vector2u getSpriteSize() const;

	//returns _position
	sf::Vector2u getSpritePosition() const;
};

