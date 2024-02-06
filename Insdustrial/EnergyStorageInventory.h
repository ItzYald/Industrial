#pragma once
#include "ObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class EnergyStorageInventory : public ObjectInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	int maxEnergy;
	std::vector<Checks> ch;

public:
	int energy;
	// Базовый конструктор
	EnergyStorageInventory(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory);
	// Отрисовка инвентаря
	void Draw();
	// Всегда
	void Next();
	// Работа инвентаря
	void Update(Inventory& playerInventory);

};

