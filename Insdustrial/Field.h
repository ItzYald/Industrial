#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Object.h"
#include "Item.h"

#include "Player.h"

#include "Assets.h"
#include "IPlayUpdatable.h"

#include "NotTransferItemEnergyObject.h"
#include "NotTransferItemSimpleObject.h"
#include "TransferItemSimpleObject.h"
#include "TransferItemEnergyObject.h"
// Инвентари
#include "CoalOvenInventory.h"
#include "ChestInventory.h"
#include "WorkbenchInventory.h"
#include "MineInventory.h"

#include "TransferObjectInventory.h"

#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"
#include "WireInventory.h"

class Field : public sf::Drawable, public IPlayUpdatable, public GamePlayUpdatable
{
public:
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Размер поля (кол-во клеток)
	sf::Vector2i size;
	// Спрайт травы
	sf::Sprite sprite;
	// Размер одной клетки
	int sizeOne;
	// Размер окна
	sf::Vector2u sizeW;
	// Фнкции отрисовки (прямоугольник, круг, текст, спрайт...)
	Functions functions;

	Assets* assets;

	std::vector<std::vector<sf::Sprite>> sprites;

	Player* player;
	
	sf::Vector2f* cameraPosition;

	// Указатель на список всех объектов
	std::vector<Object*> objects;
	std::vector<std::vector<int>> newEnergyObjectsNumbers;
	std::vector<std::vector<int>> transferEnergyObjectsNumbers;
	std::vector<std::vector<int>> transferItemObjectsNumbers;

	// Все на отрисовку
	std::vector<sf::Drawable*>* drawables;

	// Все обычные объекты
	std::vector<INotTransferItemSimpleObject*> simpleObjects;
	// Все энергетические объекты
	std::vector<INotTransferItemEnergyObject*> energyObjects;
	// Все объекты передающие энергию
	std::vector<INotTransferItemEnergyObject*> transferEnergyObjects;

	std::vector<ITransferItemSimpleObject*> transferItemSimpleObjects;

	std::vector<IPlayUpdatable*> playUpdatables;

	Field(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_size">Размер поля (кол-во клеток)</param>
	/// <param name="_sizeOne">Размер одной клетки</param>
	/// <param name="_sizeW">Размер окна</param>
	/// <param name="texture">Текстурка травы</param>
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition,
		sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW,
		Assets& _assets, Player& _player, std::vector<sf::Drawable*>& _drawables);

	void LoadingForDev(std::vector<sf::Color>& colorsInventory);

	void LoadingForPlay(std::vector<sf::Color>& colorsInventory);

	void LoadingPlay();

	void UnloadingPlay();
	/// <summary>Отрисовка травы</summary>
	/// <param name="cameraPosition">Позиция камеры</param>
	void Draw();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void PutObject(sf::Vector2f position, int playerCell, std::vector<sf::Color>& colorsInventory);

	void GamePlayUpdate() override;

	void TransEnergy(float& originalEnergy, int power, float& nextEnergy, int nextMaxEnergy);

	void CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power);

	sf::Vector2i CheckTurnEnergy(int turn);

	void WhatObjectTransEnergy();

	void PlayUpdate() override;

	bool ObjectHere(sf::Vector2i mousePositionGrid, Item& chooseItem);
	// А я кстати не помню что это, так что возможно скоро удалю
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

