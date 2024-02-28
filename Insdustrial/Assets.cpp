#include "Assets.h"

void Assets::LoadingItemTextures()
{
	// Текстуры предметов
	for (int i = 0; i < 32; i++)
	{
		itemTextures.push_back(new sf::Texture());
	}

	// Пустой слот
	itemTextures[0]->loadFromFile("Images/Empty.png");
	// Железная руда
	itemTextures[1]->loadFromFile("Images/Metals/IronOre.png");
	// Печка
	itemTextures[2]->loadFromFile("Images/Objects/Oven.png");
	// Уголь
	itemTextures[3]->loadFromFile("Images/Coal.png");
	// Железный слиток
	itemTextures[4]->loadFromFile("Images/Metals/IronIngot.png");
	// Сундук
	itemTextures[5]->loadFromFile("Images/Objects/Chest.png");
	// Железный блок
	itemTextures[6]->loadFromFile("Images/IronBlock.png");
	// Древесина
	itemTextures[7]->loadFromFile("Images/Wood.png");
	// Верстак
	itemTextures[8]->loadFromFile("Images/Objects/WorkBench.png");
	// Доски
	itemTextures[9]->loadFromFile("Images/Planks.png");
	// Корпус механнизма
	itemTextures[10]->loadFromFile("Images/Accumulator.png");
	// Электропеч
	itemTextures[11]->loadFromFile("Images/Objects/ElectricOven.png");
	// Медный провод
	itemTextures[12]->loadFromFile("Images/Wires/CopperWireOn.png");
	// Энергохранилище
	itemTextures[13]->loadFromFile("Images/Objects/EnergyStorage.png");
	// Медный слиток
	itemTextures[14]->loadFromFile("Images/Metals/CopperIngot.png");
	// Железный провод
	itemTextures[15]->loadFromFile("Images/Wires/IronWireOn.png");
	// Ручной энергогенератор
	itemTextures[16]->loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	itemTextures[17]->loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// Корпус механнизма
	itemTextures[18]->loadFromFile("Images/Objects/MechanismBody.png");
	// Оловяный слиток
	itemTextures[19]->loadFromFile("Images/Metals/TinIngot.png");
	// Оловяный провод
	itemTextures[20]->loadFromFile("Images/Wires/TinWireOn.png");
	// Оловяный провод
	itemTextures[21]->loadFromFile("Images/Metals/CopperOre.png");
	// Оловяный провод
	itemTextures[22]->loadFromFile("Images/Metals/TinOre.png");
	// Измельченная железная руда
	itemTextures[23]->loadFromFile("Images/Metals/CrushedIronOre.png");
	// Дрорбитель
	itemTextures[24]->loadFromFile("Images/Objects/Crusher.png");
	// Железная пластина
	itemTextures[25]->loadFromFile("Images/Metals/IronPlate.png");
	// Компрессор
	itemTextures[26]->loadFromFile("Images/Metals/CopperPlate.png");
	// Компрессор
	itemTextures[27]->loadFromFile("Images/Metals/TinPlate.png");
	// Компрессор
	itemTextures[28]->loadFromFile("Images/Objects/Compressor.png");
	// Микросхема
	itemTextures[29]->loadFromFile("Images/Chip.png");
	// Палка
	itemTextures[30]->loadFromFile("Images/Stick.png");
	// Молот
	itemTextures[31]->loadFromFile("Images/Hammer.png");
}

void Assets::LoadingPlay()
{
	/// Текстуры:
	textures["Player"] = new sf::Texture();
	textures["Player"]->loadFromFile("Images/Human.png");
	// Печка
	textures["Oven"] = new sf::Texture();
	textures["Oven"]->loadFromFile("Images/Objects/Oven.png");
	// Электропечка
	textures["ElectricOven"] = new sf::Texture();
	textures["ElectricOven"]->loadFromFile("Images/Objects/ElectricOven.png");
	// Дробитель
	textures["Crusher"] = new sf::Texture();
	textures["Crusher"]->loadFromFile("Images/Objects/Crusher.png");
	// Сжиматель
	textures["Compressor"] = new sf::Texture();
	textures["Compressor"]->loadFromFile("Images/Objects/Compressor.png");
	// Сжиматель
	textures["Mine"] = new sf::Texture();
	textures["Mine"]->loadFromFile("Images/Objects/Mine.png");
	// Сундук
	textures["Chest"] = new sf::Texture();
	textures["Chest"]->loadFromFile("Images/Objects/Chest.png");
	// Верстак
	textures["Workbench"] = new sf::Texture();
	textures["Workbench"]->loadFromFile("Images/Objects/Workbench.png");
	// Трава
	textures["Grass"] = new sf::Texture();
	textures["Grass"]->loadFromFile("Images/Grass.png");
	// Хранилище энергии
	textures["EnergyStorage"] = new sf::Texture();
	textures["EnergyStorage"]->loadFromFile("Images/Objects/EnergyStorage.png");
	// Ручной энергогенератор
	textures["EnergyHandGenerator"] = new sf::Texture();
	textures["EnergyHandGenerator"]->loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	textures["EnergyCoalGenerator"] = new sf::Texture();
	textures["EnergyCoalGenerator"]->loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// Текстурки проводов
	// Медные
	textures["CopperWireOn"] = new sf::Texture();
	textures["CopperWireOn"]->loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = new sf::Texture();
	textures["CopperWireOff"]->loadFromFile("Images/Wires/CopperWireOff.png");
	// Железные
	textures["IronWireOn"] = new sf::Texture();
	textures["IronWireOn"]->loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = new sf::Texture();
	textures["IronWireOff"]->loadFromFile("Images/Wires/IronWireOff.png");
	// Оловяныеы
	textures["TinWireOn"] = new sf::Texture();
	textures["TinWireOn"]->loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = new sf::Texture();
	textures["TinWireOff"]->loadFromFile("Images/Wires/TinWireOff.png");

	LoadingItemTextures();

	/// Иконки в инвентаре
	// Иконка ручной генерации энергии
	texturesInInventory["HandGenerate"] = sf::Texture();
	texturesInInventory["HandGenerate"].loadFromFile(
		"Images/IconsInInventory/IconEnergyHandGenerator.png");
}

void Assets::UnloadingPlay()
{
	textures.clear();
	itemTextures.clear();
	texturesInInventory.clear();
}
