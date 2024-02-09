#pragma once
#include "ObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"


class EnergyStorageInventory : public ObjectInventory
{
protected:
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	std::vector<Checks> ch;

public:
	// Максимальная энергия, которую вмещает
	int maxEnergy;
	// Количество энергии
	int energy;
	// То, сколько энегии может передать
	int power;
	// Базовый конструктор
	EnergyStorageInventory(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int type, std::vector<sf::Texture>& _textures);
	
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture>& _textures);
	// Отрисовка инвентаря
	void Draw();
	// Всегда
	void Next();
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	void Update(Inventory& playerInventory);

};

