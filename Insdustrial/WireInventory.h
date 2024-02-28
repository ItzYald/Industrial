#pragma once
#include "ObjectInventory.h"
#include "EnergyObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class WireInventory : public EnergyObjectInventory
{
public:
	// Список спрайтов
	sf::Sprite spriteOn;
	sf::Sprite spriteOff;

	sf::Sprite* thisSprite;

	WireInventory(){ }

	WireInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);

	// Отрисовка инвентаря
	void Draw() override;
	// Всегда
	void Next() override;
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	void Update(Inventory& playerInventory) override;

};

