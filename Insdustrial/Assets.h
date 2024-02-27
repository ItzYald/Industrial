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
public:
	// Список всех текстур
	std::map<std::string, sf::Texture> textures;

	Assets(){ }

	void LoadingImagesPlay();
};

