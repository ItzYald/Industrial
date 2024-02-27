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
	// Список текстур
	std::map<std::string, sf::Texture> textures;
	// Список текстур предметов (в инвентаре)
	std::vector<sf::Texture> itemTextures;
	// Список текстур иконок в инвентаре
	std::map<std::string, sf::Texture> texturesInInventory;

	Assets(){ }


	void LoadingPlay();

	void UnloadingPlay();
};

