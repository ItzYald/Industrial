#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Assets
{
private:
	void LoadingItemTextures();

public:
	// ������ �������
	std::map<std::string, sf::Texture> textures;
	// ������ ������� ��������� (� ���������)
	std::vector<sf::Texture> itemTextures;
	// ������ ������� ������ � ���������
	std::map<std::string, sf::Texture> texturesInInventory;

	Assets(){ }


	void LoadingPlay();

	void UnloadingPlay();
};

