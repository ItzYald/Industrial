#include "EnergyHandGeneratorInventory.h"

EnergyHandGeneratorInventory::EnergyHandGeneratorInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, int _power, std::vector<sf::Texture>& _textures,
	std::map<std::string, sf::Texture>& _texturesInInventory)
	: EnergyStorageInventory(_rw, _colorsInventory, _maxEnergy, _power, _textures)
{
	iconGenerate = sf::Sprite();
	iconGenerate.setTexture(_texturesInInventory["HandGenerate"]);
	iconGenerate.setScale(
		128 / (float)iconGenerate.getTexture()->getSize().x,
		128 / (float)iconGenerate.getTexture()->getSize().y);
	iconGenerate.setPosition(550, 160);
}

void EnergyHandGeneratorInventory::Draw()
{
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	rw->draw(iconGenerate);
	buttons[0].Draw(*rw);
	if (maxEnergy != 0)
	{
		// ��������� ���������� �������
		functions.DrawRectangleGradient(
			sf::Vector2f(400, 350), sf::Vector2f(30, (energy / (float)maxEnergy) * -200),
			sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string((int)energy) + " / " + std::to_string(maxEnergy) + " en",
			sf::Vector2f(450, 330), 20, sf::Color(colorsInventory[0]));
	}
	
}

void EnergyHandGeneratorInventory::Update(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		buttons.push_back(Button(iconGenerate.getPosition(),
			sf::Vector2f(iconGenerate.getTexture()->getSize().x * iconGenerate.getScale().x,
				iconGenerate.getTexture()->getSize().y * iconGenerate.getScale().y),
			L"", sf::Color::Transparent, sf::Color::Transparent, sf::Color::Red,
			sf::Color(colorsInventory[2].r, colorsInventory[2].g, colorsInventory[2].b, 100),
			sf::Color::Transparent, sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Color::Transparent,
			sf::Vector2f(0, 0), 4, 25));
	}

	if (buttons[0].CheckDown(*rw))
	{
		energy += 0.2;
	}

	if (energy > maxEnergy)
		energy = maxEnergy;

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();

}

