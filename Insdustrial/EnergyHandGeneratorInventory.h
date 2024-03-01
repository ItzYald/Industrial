#pragma once
#include "EnergyStorageInventory.h"

class EnergyHandGeneratorInventory : public EnergyObjectInventory
{
public:
	// Иконка генерации энергии
	sf::Sprite iconGenerate;

	EnergyHandGeneratorInventory(){ }

	EnergyHandGeneratorInventory(
		std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures,
		std::map<std::string, sf::Texture>& _texturesInInventory);

	void Draw() override;
	void PlayUpdate() override;
	void WhileOpen(Inventory& playerInventory) override;

};

