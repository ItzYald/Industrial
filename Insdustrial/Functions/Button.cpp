#include "Button.h"

Button::Button(sf::Vector2f _coords, sf::Vector2f _size,
    sf::String _message, sf::Color _color, sf::Color _activeColor, sf::Color _colorBorder,
    sf::Color _activeColorBorder, sf::Color _colorTitle, sf::Color _activeColorTitle,
    sf::Vector2f _hitBox, int _borderSize, int _fontSize) :
    coords(_coords), size(_size), message(_message), color(_color), activeColor(_activeColor),
    colorBorder(_colorBorder), activeColorBorder(_activeColorBorder),
    colorTitle(_colorTitle), activeColorTitle(_activeColorTitle),
    hitBox(_hitBox), borderSize(_borderSize), fontSize(_fontSize)
{
    center = 2;
    font = sf::Font();
    font.loadFromFile("Font/Undertale-Font.ttf");
    buttonLeftPressed = false;
    buttonRightPressed = false;
}

Button::Button(sf::Vector2f _coords, sf::Vector2f _size,
    sf::String _message, sf::Color _color, sf::Color _activeColor, sf::Color _colorBorder,
    sf::Color _activeColorBorder, sf::Color _colorTitle, sf::Color _activeColorTitle,
    int _center, int _borderSize, int _fontSize) :
    coords(_coords), size(_size), message(_message), color(_color), activeColor(_activeColor),
    colorBorder(_colorBorder), activeColorBorder(_activeColorBorder),
    colorTitle(_colorTitle), activeColorTitle(_activeColorTitle),
    center(_center), borderSize(_borderSize), fontSize(_fontSize)
{
    hitBox = sf::Vector2f(0, 0);
    font = sf::Font();
    font.loadFromFile("Font/Undertale-Font.ttf");
    buttonLeftPressed = false;
    buttonRightPressed = false;
}
// Только отрисовать
void Button::Draw(sf::RenderWindow& rw)
{
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    Rectangle(rw);
    PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);

    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
    {
        Rectangle(rw, false);
        if (activeColorTitle != sf::Color::Transparent)
            PrintText(rw, message, coords + hitBox, fontSize, activeColorTitle, center);
        else
            PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);
    }
}
// Отрисовать и проверить на отжатие
bool Button::DrawCheckLeft(sf::RenderWindow& rw)
{
    bool click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    Rectangle(rw);
    PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);
    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
    {
        Rectangle(rw, false);
        if (activeColorTitle != sf::Color::Transparent)
            PrintText(rw, message, coords + hitBox, fontSize, activeColorTitle, center);
        else
            PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);
        if (click)
        {
            if (!buttonLeftPressed)
                buttonLeftPressed = true;
        }
        else
        {
            if (buttonLeftPressed)
            {
                buttonLeftPressed = false;
                return true;
            }
        }
    }
    else
        buttonLeftPressed = false;
    return false;
}
// Проверить на отжатие
bool Button::CheckLeft(sf::RenderWindow& rw)
{
    bool click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
    {
        if (click)
        {
            if (!buttonLeftPressed)
                buttonLeftPressed = true;
        }
        else
        {
            if (buttonLeftPressed)
            {
                buttonLeftPressed = false;
                return true;
            }
        }
    }
    else
        buttonLeftPressed = false;
    return false;
}
// Проверить нажатие левой кнопки мыши
bool Button::CheckRight(sf::RenderWindow& rw)
{
    bool click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
    {
        if (click)
        {
            if (!buttonRightPressed)
                buttonRightPressed = true;
        }
        else
        {
            if (buttonRightPressed)
            {
                buttonRightPressed = false;
                return true;
            }
        }
    }
    else
        buttonRightPressed = false;
    return false;
}
// Отрисовать и проверить на наведение
bool Button::DrawAim(sf::RenderWindow& rw)
{
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    Rectangle(rw);
    PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);

    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
    {
        Rectangle(rw, false);
        if (activeColorTitle != sf::Color::Transparent)
            PrintText(rw, message, coords + hitBox, fontSize, activeColorTitle, center);
        else
            PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);

        return true;
    }
    return false;

}

bool Button::Aim(sf::RenderWindow& rw)
{
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);
    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
        return true;
    return false;
}

void Button::PrintText(sf::RenderWindow& rw, sf::String mes, sf::Vector2f pos, int _size, sf::Color col, int center)
{
    text = sf::Text(mes, font, _size);
    text.setFont(font);
    text.setCharacterSize(_size);
    if (center == 0)
    {
        text.setPosition(sf::Vector2f(pos.x + size.x / 2 - mes.getSize() + 0.5 * _size / 2, pos.y));
    }
    else if (center == 1)
    {
        text.setPosition(sf::Vector2f(pos.x + size.x / 2 - mes.getSize() * _size / 4 - _size / 4, pos.y));
    }
    else
    {
        text.setPosition(pos);
    }
    text.setFillColor(col);
    rw.draw(text);
}

void Button::Rectangle(sf::RenderWindow& rw)
{
    rect = sf::RectangleShape();
    rect.setPosition(coords);
    rect.setSize(size);
    rect.setFillColor(color);
    rect.setOutlineColor(colorBorder);
    rect.setOutlineThickness(borderSize);
    rw.draw(rect);
}

void Button::Rectangle(sf::RenderWindow& rw, bool)
{
    rect = sf::RectangleShape();
    rect.setPosition(coords);
    rect.setSize(size);
    rect.setFillColor(activeColor);
    rect.setOutlineColor(activeColorBorder);
    rect.setOutlineThickness(borderSize);
    rw.draw(rect);
}
