#pragma once
#include "ObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class EnergyStorageInventory : public ObjectInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	// Максимальная энергия, которую вмещает
	int maxEnergy;
	std::vector<Checks> ch;

public:
	int energy;
	// Базовый конструктор
	EnergyStorageInventory(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, int type, std::vector<sf::Texture>& _textures);
	// Отрисовка инвентаря
	void Draw();
	// Всегда
	void Next();
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	void Update(Inventory& playerInventory);

};

