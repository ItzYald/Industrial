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

#include "Item.h"

class Assets
{
private:
	void LoadingItemTextures();

public:
	Assets()
	{
		textures = std::map<std::string, sf::Texture*>();
	}

	// Список текстур
	std::map<std::string, sf::Texture*> textures;
	// Список текстур предметов (в инвентаре)
	std::vector<sf::Texture*> itemTextures;
	// Список текстур иконок в инвентаре
	std::map<std::string, sf::Texture> texturesInInventory;


	void LoadingPlay();

	void UnloadingPlay();
};

