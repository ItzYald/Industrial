#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"


class Button
{
public:
    sf::Vector2f coords;
    sf::Vector2f size;
    sf::String message;
    sf::Color color;
    sf::Color activeColor;
    sf::Color downColor;
    sf::Color colorBorder;
    sf::Color activeColorBorder;
    sf::Color downColorBorder;
    sf::Color colorTitle;
    sf::Color activeColorTitle;
    sf::Color downColorTitle;
    sf::Vector2f hitBox;
    int borderSize;
    int fontSize;
    sf::Font font;
    int center;
    bool click;

    sf::Vector2f mouseCoords;
    bool buttonLeftPressed;
    bool buttonRightPressed;
    sf::RectangleShape rect = sf::RectangleShape();
    sf::Text text;

    Button(){}

    Button(sf::Vector2f _coords, sf::Vector2f _size, sf::String _message,
        sf::Color _color, sf::Color _activeColor, sf::Color _downColor,
        sf::Color _colorBorder, sf::Color _activeColorBorder, sf::Color _downColorBorder,
        sf::Color _colorTitle, sf::Color _activeColorTitle, sf::Color _downColorTitle,
        sf::Vector2f _hitBox, int _borderSize, int _fontSize);

    Button(sf::Vector2f _coords, sf::Vector2f _size,
        sf::String _message, sf::Color _color, sf::Color _activeColor, sf::Color _colorBorder,
        sf::Color _activeColorBorder, sf::Color _colorTitle, sf::Color _activeColorTitle,
        sf::Vector2f _hitBox, int _borderSize, int _fontSize);

    Button(sf::Vector2f _coords, sf::Vector2f _size,
        sf::String _message, sf::Color _color, sf::Color _activeColor, sf::Color _colorBorder,
        sf::Color _activeColorBorder, sf::Color _colorTitle, sf::Color _activeColorTitle,
        int _center, int _borderSize, int _fontSize);

    void Draw(sf::RenderWindow& rw);
    // Срабатывание при отжатии
    bool DrawCheckLeft(sf::RenderWindow& rw);

    bool CheckLeft(sf::RenderWindow& rw);

    bool CheckRight(sf::RenderWindow& rw);

    bool CheckDown(sf::RenderWindow& rw);
    // Срабатывание при наведении и отрисовка
    bool DrawAim(sf::RenderWindow& rw);
    // Срабатывание при наведении без отрисовки
    bool Aim(sf::RenderWindow& rw);

    void PrintText(sf::RenderWindow& rw, sf::String mes, sf::Vector2f pos, int size, sf::Color col, int center);
    /// <summary>Отрисовка прямоугольника</summary>
    /// <param name="rw">Окно</param>
    /// <param name="status">Статус (0 - обычный, 1 - при наведении, 2 - при нажатии)</param>
    void Rectangle(sf::RenderWindow& rw, int status);

};

