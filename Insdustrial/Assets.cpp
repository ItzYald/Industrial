#include "Assets.h"

void Assets::LoadingItemTextures()
{
	// �������� ���������
	for (int i = 0; i < 35; i++)
	{
		itemTextures.push_back(new sf::Texture());
	}

	// ������ ����
	itemTextures[ItemEnum::empty]->loadFromFile("Images/Empty.png");
	// �������� ����
	itemTextures[ItemEnum::ironOre]->loadFromFile("Images/Metals/IronOre.png");
	// �����
	itemTextures[ItemEnum::oven]->loadFromFile("Images/Objects/Oven.png");
	// �����
	itemTextures[ItemEnum::coal]->loadFromFile("Images/Coal.png");
	// �������� ������
	itemTextures[ItemEnum::ironIngot]->loadFromFile("Images/Metals/IronIngot.png");
	// ������
	itemTextures[ItemEnum::chest]->loadFromFile("Images/Objects/Chest.png");
	// �������� ����
	itemTextures[ItemEnum::ironBlock]->loadFromFile("Images/IronBlock.png");
	// ���������
	itemTextures[ItemEnum::wood]->loadFromFile("Images/Wood.png");
	// �������
	itemTextures[ItemEnum::workbench]->loadFromFile("Images/Objects/WorkBench.png");
	// �����
	itemTextures[ItemEnum::planks]->loadFromFile("Images/Planks.png");
	// �����������
	itemTextures[ItemEnum::accumulator]->loadFromFile("Images/Accumulator.png");
	// ����������
	itemTextures[ItemEnum::energyOven]->loadFromFile("Images/Objects/ElectricOven.png");
	// ������ ������
	itemTextures[ItemEnum::copperWire]->loadFromFile("Images/Wires/CopperWireOn.png");
	// ���������������
	itemTextures[ItemEnum::energyStorage]->loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ������
	itemTextures[ItemEnum::copperIngot]->loadFromFile("Images/Metals/CopperIngot.png");
	// �������� ������
	itemTextures[ItemEnum::ironWire]->loadFromFile("Images/Wires/IronWireOn.png");
	// ������ ���������������
	itemTextures[ItemEnum::handEnergyGenerator]->loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	itemTextures[ItemEnum::coalEnergyGenerator]->loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// ������ ����������
	itemTextures[ItemEnum::mechanismBody]->loadFromFile("Images/Objects/MechanismBody.png");
	// �������� ������
	itemTextures[ItemEnum::tinIngot]->loadFromFile("Images/Metals/TinIngot.png");
	// �������� ������
	itemTextures[ItemEnum::tinWire]->loadFromFile("Images/Wires/TinWireOn.png");
	// ������ ����
	itemTextures[ItemEnum::copperOre]->loadFromFile("Images/Metals/CopperOre.png");
	// �������� ����
	itemTextures[ItemEnum::tinOre]->loadFromFile("Images/Metals/TinOre.png");
	// ������������ �������� ����
	itemTextures[ItemEnum::crushedIronOre]->loadFromFile("Images/Metals/CrushedIronOre.png");
	// ����������
	itemTextures[ItemEnum::crusher]->loadFromFile("Images/Objects/Crusher.png");
	// �������� ��������
	itemTextures[ItemEnum::ironPlate]->loadFromFile("Images/Metals/IronPlate.png");
	// ������ ��������
	itemTextures[ItemEnum::copperPlate]->loadFromFile("Images/Metals/CopperPlate.png");
	// �������� ��������
	itemTextures[ItemEnum::tinPlate]->loadFromFile("Images/Metals/TinPlate.png");
	// ����������
	itemTextures[ItemEnum::compressor]->loadFromFile("Images/Objects/Compressor.png");
	// ����������
	itemTextures[ItemEnum::chip]->loadFromFile("Images/Chip.png");
	// �����
	itemTextures[ItemEnum::stick]->loadFromFile("Images/Stick.png");
	// �����
	itemTextures[ItemEnum::hammer]->loadFromFile("Images/Hammer.png");
	// �����
	itemTextures[ItemEnum::mine]->loadFromFile("Images/Objects/Mine.png");
	// ������
	itemTextures[ItemEnum::stone]->loadFromFile("Images/Stone.png");
	// �������
	itemTextures[ItemEnum::flint]->loadFromFile("Images/Error.png");
}

void Assets::LoadingPlay()
{
	/// ��������:
	textures["Player"] = new sf::Texture();
	textures["Player"]->loadFromFile("Images/Human.png");
	// �����
	textures["Oven"] = new sf::Texture();
	textures["Oven"]->loadFromFile("Images/Objects/Oven.png");
	// ������������
	textures["ElectricOven"] = new sf::Texture();
	textures["ElectricOven"]->loadFromFile("Images/Objects/ElectricOven.png");
	// ���������
	textures["Crusher"] = new sf::Texture();
	textures["Crusher"]->loadFromFile("Images/Objects/Crusher.png");
	// ���������
	textures["Compressor"] = new sf::Texture();
	textures["Compressor"]->loadFromFile("Images/Objects/Compressor.png");
	// ���������
	textures["Mine"] = new sf::Texture();
	textures["Mine"]->loadFromFile("Images/Objects/Mine.png");
	// ������
	textures["Chest"] = new sf::Texture();
	textures["Chest"]->loadFromFile("Images/Objects/Chest.png");
	// �������
	textures["Workbench"] = new sf::Texture();
	textures["Workbench"]->loadFromFile("Images/Objects/Workbench.png");
	// �����
	textures["Grass"] = new sf::Texture();
	textures["Grass"]->loadFromFile("Images/Grass.png");
	// ��������� �������
	textures["EnergyStorage"] = new sf::Texture();
	textures["EnergyStorage"]->loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ���������������
	textures["EnergyHandGenerator"] = new sf::Texture();
	textures["EnergyHandGenerator"]->loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	textures["EnergyCoalGenerator"] = new sf::Texture();
	textures["EnergyCoalGenerator"]->loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// ��������� ��������
	// ������
	textures["CopperWireOn"] = new sf::Texture();
	textures["CopperWireOn"]->loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = new sf::Texture();
	textures["CopperWireOff"]->loadFromFile("Images/Wires/CopperWireOff.png");
	// ��������
	textures["IronWireOn"] = new sf::Texture();
	textures["IronWireOn"]->loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = new sf::Texture();
	textures["IronWireOff"]->loadFromFile("Images/Wires/IronWireOff.png");
	// ���������
	textures["TinWireOn"] = new sf::Texture();
	textures["TinWireOn"]->loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = new sf::Texture();
	textures["TinWireOff"]->loadFromFile("Images/Wires/TinWireOff.png");

	LoadingItemTextures();

	/// ������ � ���������
	// ������ ������ ��������� �������
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
