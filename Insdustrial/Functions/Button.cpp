#include "Button.h"

void Button::Init(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size)
{
    mousePosition = &_mousePosition;
    rectangle = sf::RectangleShape(_size);
    rectangle.setPosition(_position);
    leftClick = false;
}

bool Button::Aim()
{
    if (mousePosition->x > rectangle.getPosition().x &&
        mousePosition->y > rectangle.getPosition().y &&
        mousePosition->x < rectangle.getPosition().x + rectangle.getSize().x &&
        mousePosition->y < rectangle.getPosition().y + rectangle.getSize().y)
        return true;
    return false;
}

bool Button::LeftDown()
{
    return (Aim() && leftClick);
}

bool Button::RightDown()
{
    return (Aim() && rightClick);
}

bool Button::CheckLeft()
{
    if (Aim())
    {
        if (leftClick)
        {
            if (!leftPreviousClick)
                leftPreviousClick = true;
        }
        else
        {
            if (leftPreviousClick)
            {
                leftPreviousClick = false;
                return true;
            }
        }
    }
    else
        leftPreviousClick = false;
    return false;
}

bool Button::CheckRight()
{
    if (Aim())
    {
        if (rightClick)
        {
            if (!rightPreviousClick)
                rightPreviousClick = true;
        }
        else
        {
            if (rightPreviousClick)
            {
                rightPreviousClick = false;
                return true;
            }
        }
    }
    else
        rightPreviousClick = false;
    return false;
}

