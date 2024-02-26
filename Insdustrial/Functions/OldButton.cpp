#include "OldButton.h"

OldButton::OldButton(sf::Vector2f _coords, sf::Vector2f _size, sf::String _message,
    sf::Color _color, sf::Color _activeColor, sf::Color _downColor,
    sf::Color _colorBorder, sf::Color _activeColorBorder, sf::Color _downColorBorder,
    sf::Color _colorTitle, sf::Color _activeColorTitle, sf::Color _downColorTitle,
    sf::Vector2f _hitBox, int _borderSize, int _fontSize) :
    coords(_coords), size(_size), message(_message),
    color(_color), activeColor(_activeColor), downColor(_downColor),
    colorBorder(_colorBorder), activeColorBorder(_activeColorBorder), downColorBorder(_downColorBorder),
    colorTitle(_colorTitle), activeColorTitle(_activeColorTitle), downColorTitle(_downColorTitle),
    hitBox(_hitBox), borderSize(_borderSize), fontSize(_fontSize)
{
    center = 2;
    font = sf::Font();
    font.loadFromFile("Font/Undertale-Font.ttf");
    buttonLeftPressed = false;
    buttonRightPressed = false;
    click = false;
}


OldButton::OldButton(sf::Vector2f _coords, sf::Vector2f _size,
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
    downColor = sf::Color::Transparent;
    downColorBorder = sf::Color::Transparent;
    downColorTitle = sf::Color::Transparent;
    click = false;
}

OldButton::OldButton(sf::Vector2f _coords, sf::Vector2f _size,
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
    downColor = sf::Color::Transparent;
    downColorBorder = sf::Color::Transparent;
    downColorTitle = sf::Color::Transparent;
    click = false;
}
// Только отрисовать
void OldButton::Draw(sf::RenderWindow& rw)
{
    click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    Rectangle(rw, 0);
    PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);

    if (Aim(rw))
    {
        Rectangle(rw, 1);
        if (activeColorTitle != sf::Color::Transparent)
            PrintText(rw, message, coords + hitBox, fontSize, activeColorTitle, center);
        else
            PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);
        if (click)
        {
            Rectangle(rw, 2);
            if (downColorTitle != sf::Color::Transparent)
                PrintText(rw, message, coords + hitBox, fontSize, downColorTitle, center);
            else
                PrintText(rw, message, coords + hitBox, fontSize, colorTitle, center);

        }
    }



}
// Отрисовать и проверить на отжатие
bool OldButton::DrawCheckLeft(sf::RenderWindow& rw)
{
    Draw(rw);
    return CheckLeft(rw);
}
// Проверить на отжатие
bool OldButton::CheckLeft(sf::RenderWindow& rw)
{
    click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    if (Aim(rw))
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
bool OldButton::CheckRight(sf::RenderWindow& rw)
{
    click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    if (Aim(rw))
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

bool OldButton::CheckDown(sf::RenderWindow& rw)
{
    click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    if (Aim(rw) && click)
    {
        return true;
    }
    return false;
}

// Отрисовать и проверить на наведение
bool OldButton::DrawAim(sf::RenderWindow& rw)
{
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);

    Draw(rw);
    return Aim(rw);
}

bool OldButton::Aim(sf::RenderWindow& rw)
{
    mouseCoords = (sf::Vector2f)sf::Mouse::getPosition(rw);
    if (coords.x < mouseCoords.x && mouseCoords.x < coords.x + size.x && coords.y < mouseCoords.y && mouseCoords.y < coords.y + size.y)
        return true;
    return false;
}

void OldButton::PrintText(sf::RenderWindow& rw, sf::String mes, sf::Vector2f pos, int _size, sf::Color col, int center)
{
    text.setString(mes);
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

void OldButton::Rectangle(sf::RenderWindow& rw, int status)
{
    rect.setPosition(coords);
    rect.setSize(size);
    if (status == 0)
    {
        rect.setFillColor(color);
        rect.setOutlineColor(colorBorder);
        rect.setOutlineThickness(borderSize);
    }
    else if (status == 1)
    {
        rect.setFillColor(activeColor);
        rect.setOutlineColor(activeColorBorder);
        rect.setOutlineThickness(borderSize);
    }
    else if (status == 2)
    {
        rect.setFillColor(activeColor);
        rect.setOutlineColor(activeColorBorder);
        rect.setOutlineThickness(borderSize);
    }
    rw.draw(rect);
}
