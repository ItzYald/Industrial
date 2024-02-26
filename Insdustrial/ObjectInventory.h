#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "StaticSprites.h"

#include "CellInInventory.h"

#include "Inventory.h"
#include "AllInventory.h"

class ObjectInventory : public AllInventory
{
public:
	// Отрисовка инвентаря
	virtual void Draw() = 0;
	// Всегда (даже когда инвентарь не открыт)
	virtual void Next() = 0;
	/// <summary>Пока инвентарь открыт</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	virtual void Update(Inventory& playerInventory) = 0;

};

