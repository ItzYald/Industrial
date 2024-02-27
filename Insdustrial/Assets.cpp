#include "Assets.h"



void Assets::LoadingImagesPlay()
{
	/// Текстуры:
	textures["Player"] = sf::Texture();
	textures["Player"].loadFromFile("Images/Human.png");
	// Печка
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// Электропечка
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
	// Дробитель
	textures["Crusher"] = sf::Texture();
	textures["Crusher"].loadFromFile("Images/Objects/Crusher.png");
	// Дробитель
	textures["Compressor"] = sf::Texture();
	textures["Compressor"].loadFromFile("Images/Objects/Compressor.png");
	// Сундук
	textures["Chest"] = sf::Texture();
	textures["Chest"].loadFromFile("Images/Objects/Chest.png");
	// Верстак
	textures["Workbench"] = sf::Texture();
	textures["Workbench"].loadFromFile("Images/Objects/Workbench.png");
	// Трава
	textures["Grass"] = sf::Texture();
	textures["Grass"].loadFromFile("Images/Grass.png");
	// Хранилище энергии
	textures["EnergyStorage"] = sf::Texture();
	textures["EnergyStorage"].loadFromFile("Images/Objects/EnergyStorage.png");
	// Ручной энергогенератор
	textures["EnergyHandGenerator"] = sf::Texture();
	textures["EnergyHandGenerator"].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	textures["EnergyCoalGenerator"] = sf::Texture();
	textures["EnergyCoalGenerator"].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// Текстурки проводов
	// Медные
	textures["CopperWireOn"] = sf::Texture();
	textures["CopperWireOn"].loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = sf::Texture();
	textures["CopperWireOff"].loadFromFile("Images/Wires/CopperWireOff.png");
	// Железные
	textures["IronWireOn"] = sf::Texture();
	textures["IronWireOn"].loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = sf::Texture();
	textures["IronWireOff"].loadFromFile("Images/Wires/IronWireOff.png");
	// Оловяныеы
	textures["TinWireOn"] = sf::Texture();
	textures["TinWireOn"].loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = sf::Texture();
	textures["TinWireOff"].loadFromFile("Images/Wires/TinWireOff.png");
}
