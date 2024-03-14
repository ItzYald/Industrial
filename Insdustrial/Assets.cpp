#include "Assets.h"

void Assets::LoadingItemTextures()
{
	// Текстуры предметов
	for (int i = 0; i < 35; i++)
	{
		itemTextures.push_back(new sf::Texture());
	}

	// Пустой слот
	itemTextures[ItemEnum::empty]->loadFromFile("Images/Empty.png");
	// Железная руда
	itemTextures[ItemEnum::ironOre]->loadFromFile("Images/Metals/IronOre.png");
	// Печка
	itemTextures[ItemEnum::oven]->loadFromFile("Images/Objects/Oven.png");
	// Уголь
	itemTextures[ItemEnum::coal]->loadFromFile("Images/Coal.png");
	// Железный слиток
	itemTextures[ItemEnum::ironIngot]->loadFromFile("Images/Metals/IronIngot.png");
	// Сундук
	itemTextures[ItemEnum::chest]->loadFromFile("Images/Objects/Chest.png");
	// Железный блок
	itemTextures[ItemEnum::ironBlock]->loadFromFile("Images/IronBlock.png");
	// Древесина
	itemTextures[ItemEnum::wood]->loadFromFile("Images/Wood.png");
	// Верстак
	itemTextures[ItemEnum::workbench]->loadFromFile("Images/Objects/WorkBench.png");
	// Доски
	itemTextures[ItemEnum::planks]->loadFromFile("Images/Planks.png");
	// Аккумулятоп
	itemTextures[ItemEnum::accumulator]->loadFromFile("Images/Accumulator.png");
	// Электропеч
	itemTextures[ItemEnum::energyOven]->loadFromFile("Images/Objects/ElectricOven.png");
	// Медный провод
	itemTextures[ItemEnum::copperWire]->loadFromFile("Images/Wires/CopperWireOn.png");
	// Энергохранилище
	itemTextures[ItemEnum::energyStorage]->loadFromFile("Images/Objects/EnergyStorage.png");
	// Медный слиток
	itemTextures[ItemEnum::copperIngot]->loadFromFile("Images/Metals/CopperIngot.png");
	// Железный провод
	itemTextures[ItemEnum::ironWire]->loadFromFile("Images/Wires/IronWireOn.png");
	// Ручной энергогенератор
	itemTextures[ItemEnum::handEnergyGenerator]->loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	itemTextures[ItemEnum::coalEnergyGenerator]->loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// Корпус механнизма
	itemTextures[ItemEnum::mechanismBody]->loadFromFile("Images/Objects/MechanismBody.png");
	// Оловяный слиток
	itemTextures[ItemEnum::tinIngot]->loadFromFile("Images/Metals/TinIngot.png");
	// Оловяный провод
	itemTextures[ItemEnum::tinWire]->loadFromFile("Images/Wires/TinWireOn.png");
	// Медная руда
	itemTextures[ItemEnum::copperOre]->loadFromFile("Images/Metals/CopperOre.png");
	// Оловяная руда
	itemTextures[ItemEnum::tinOre]->loadFromFile("Images/Metals/TinOre.png");
	// Измельченная железная руда
	itemTextures[ItemEnum::crushedIronOre]->loadFromFile("Images/Metals/CrushedIronOre.png");
	// Дрорбитель
	itemTextures[ItemEnum::crusher]->loadFromFile("Images/Objects/Crusher.png");
	// Железная пластина
	itemTextures[ItemEnum::ironPlate]->loadFromFile("Images/Metals/IronPlate.png");
	// Медная пластина
	itemTextures[ItemEnum::copperPlate]->loadFromFile("Images/Metals/CopperPlate.png");
	// Оловяная пластина
	itemTextures[ItemEnum::tinPlate]->loadFromFile("Images/Metals/TinPlate.png");
	// Компрессор
	itemTextures[ItemEnum::compressor]->loadFromFile("Images/Objects/Compressor.png");
	// Микросхема
	itemTextures[ItemEnum::chip]->loadFromFile("Images/Chip.png");
	// Палка
	itemTextures[ItemEnum::stick]->loadFromFile("Images/Stick.png");
	// Молот
	itemTextures[ItemEnum::hammer]->loadFromFile("Images/Hammer.png");
	// Шахта
	itemTextures[ItemEnum::mine]->loadFromFile("Images/Objects/Mine.png");
	// Камень
	itemTextures[ItemEnum::stone]->loadFromFile("Images/Stone.png");
	// Кремень
	itemTextures[ItemEnum::flint]->loadFromFile("Images/Error.png");
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
