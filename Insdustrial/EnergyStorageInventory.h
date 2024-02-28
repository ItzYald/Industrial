#pragma once
#include "ObjectInventory.h"
#include "EnergyObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"


class EnergyStorageInventory : public EnergyObjectInventory
{
protected:

public:
	// Базовый конструктор
	EnergyStorageInventory(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_colorsInventory">Базовые цвета интерфейса</param>
	/// <param name="_maxEnergy">Максимально вместимая энергия</param>
	/// <param name="_power">Максимально выдаваемая энегия</param>
	/// <param name="_textures">Список текстур</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);
	// Отрисовка инвентаря
	void Draw() override;
	// Всегда
	void Next() override;
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	void Update(Inventory& playerInventory) override;

};

