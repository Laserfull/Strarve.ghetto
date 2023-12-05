#include "ErrorMessage.h"

#include "Game.h";

extern sf::Font* gameFont;

extern Game* gameInfo;

extern sf::Texture* errorTexture;

ErrorMessage::ErrorMessage(const char* text)
{
    this->setSize({ gameInfo->getUnit().x * 720,gameInfo->getUnit().y * 200 });
    this->setTexture(errorTexture);
    this->setOrigin({ this->getSize().x / 2,this->getSize().y / 2 });

    _text.setFont(*gameFont);
    _text.setCharacterSize(gameInfo->getUnit().x * 24);
    _text.setFillColor(sf::Color::Red);
    _text.setOutlineColor(sf::Color::Black);
    _text.setOutlineThickness(gameInfo->getUnit().x*3);
    _text.setStyle(sf::Text::Bold);

    //maybe add outline thickness

    this->changeText(text);
}

ErrorMessage::~ErrorMessage()
{
    _lifeTime = NULL;
}

void ErrorMessage::changeText(const char* text)
{
    _lifeTime = 3;
    _text.setString(text);
}

void ErrorMessage::update(const float& deltaTime)
{
    _lifeTime -= deltaTime;
}

bool ErrorMessage::isDead() const
{
    return (_lifeTime <=0);
}

void ErrorMessage::draw(sf::RenderWindow* window, const sf::Vector2f& position)
{
    this->setPosition(position);//place box at pos

                  // place text at x pos - (messageSize* charSize)                                     , at y pos - size of char
   _text.setPosition({ position.x - (_text.getString().getSize() * (_text.getCharacterSize() / 4)) , position.y - (_text.getCharacterSize()/2) });

    window->draw(*this);//draw box
    window->draw(_text);//draw text
}
