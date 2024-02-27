#include "Assets.h"

void Assets::LoadingItemTextures()
{
	// �������� ���������
	for (int i = 0; i < 32; i++)
	{
		itemTextures.push_back(sf::Texture());
	}

	// ������ ����
	itemTextures[0].loadFromFile("Images/Empty.png");
	// �������� ����
	itemTextures[1].loadFromFile("Images/Metals/IronOre.png");
	// �����
	itemTextures[2].loadFromFile("Images/Objects/Oven.png");
	// �����
	itemTextures[3].loadFromFile("Images/Coal.png");
	// �������� ������
	itemTextures[4].loadFromFile("Images/Metals/IronIngot.png");
	// ������
	itemTextures[5].loadFromFile("Images/Objects/Chest.png");
	// �������� ����
	itemTextures[6].loadFromFile("Images/IronBlock.png");
	// ���������
	itemTextures[7].loadFromFile("Images/Wood.png");
	// �������
	itemTextures[8].loadFromFile("Images/Objects/WorkBench.png");
	// �����
	itemTextures[9].loadFromFile("Images/Planks.png");
	// ������ ����������
	itemTextures[10].loadFromFile("Images/Accumulator.png");
	// ����������
	itemTextures[11].loadFromFile("Images/Objects/ElectricOven.png");
	// ������ ������
	itemTextures[12].loadFromFile("Images/Wires/CopperWireOn.png");
	// ���������������
	itemTextures[13].loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ������
	itemTextures[14].loadFromFile("Images/Metals/CopperIngot.png");
	// �������� ������
	itemTextures[15].loadFromFile("Images/Wires/IronWireOn.png");
	// ������ ���������������
	itemTextures[16].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	itemTextures[17].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// ������ ����������
	itemTextures[18].loadFromFile("Images/Objects/MechanismBody.png");
	// �������� ������
	itemTextures[19].loadFromFile("Images/Metals/TinIngot.png");
	// �������� ������
	itemTextures[20].loadFromFile("Images/Wires/TinWireOn.png");
	// �������� ������
	itemTextures[21].loadFromFile("Images/Metals/CopperOre.png");
	// �������� ������
	itemTextures[22].loadFromFile("Images/Metals/TinOre.png");
	// ������������ �������� ����
	itemTextures[23].loadFromFile("Images/Metals/CrushedIronOre.png");
	// ����������
	itemTextures[24].loadFromFile("Images/Objects/Crusher.png");
	// �������� ��������
	itemTextures[25].loadFromFile("Images/Metals/IronPlate.png");
	// ����������
	itemTextures[26].loadFromFile("Images/Metals/CopperPlate.png");
	// ����������
	itemTextures[27].loadFromFile("Images/Metals/TinPlate.png");
	// ����������
	itemTextures[28].loadFromFile("Images/Objects/Compressor.png");
	// ����������
	itemTextures[29].loadFromFile("Images/Chip.png");
	// �����
	itemTextures[30].loadFromFile("Images/Stick.png");
	// �����
	itemTextures[31].loadFromFile("Images/Hammer.png");
}

void Assets::LoadingPlay()
{
	/// ��������:
	textures["Player"] = sf::Texture();
	textures["Player"].loadFromFile("Images/Human.png");
	// �����
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// ������������
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
	// ���������
	textures["Crusher"] = sf::Texture();
	textures["Crusher"].loadFromFile("Images/Objects/Crusher.png");
	// ���������
	textures["Compressor"] = sf::Texture();
	textures["Compressor"].loadFromFile("Images/Objects/Compressor.png");
	// ������
	textures["Chest"] = sf::Texture();
	textures["Chest"].loadFromFile("Images/Objects/Chest.png");
	// �������
	textures["Workbench"] = sf::Texture();
	textures["Workbench"].loadFromFile("Images/Objects/Workbench.png");
	// �����
	textures["Grass"] = sf::Texture();
	textures["Grass"].loadFromFile("Images/Grass.png");
	// ��������� �������
	textures["EnergyStorage"] = sf::Texture();
	textures["EnergyStorage"].loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ���������������
	textures["EnergyHandGenerator"] = sf::Texture();
	textures["EnergyHandGenerator"].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	textures["EnergyCoalGenerator"] = sf::Texture();
	textures["EnergyCoalGenerator"].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// ��������� ��������
	// ������
	textures["CopperWireOn"] = sf::Texture();
	textures["CopperWireOn"].loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = sf::Texture();
	textures["CopperWireOff"].loadFromFile("Images/Wires/CopperWireOff.png");
	// ��������
	textures["IronWireOn"] = sf::Texture();
	textures["IronWireOn"].loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = sf::Texture();
	textures["IronWireOff"].loadFromFile("Images/Wires/IronWireOff.png");
	// ���������
	textures["TinWireOn"] = sf::Texture();
	textures["TinWireOn"].loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = sf::Texture();
	textures["TinWireOff"].loadFromFile("Images/Wires/TinWireOff.png");

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
