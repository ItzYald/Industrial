#pragma once
#include <iostream>
#include <vector>

#include "CellInInventory.h"

class ProgressInventory
{
private:
	Functions functions;

public:
	int whatProgress;
	int previousItemProgress;


	ProgressInventory(){ }
	ProgressInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Texture*>& _textures, std::vector<CellInInventory>& cells);
	/// <summary>
	/// Процесс работы (плавка, сжатие, перемолка...)
	/// </summary>
	/// <param name="energy">Ссылка на энергию</param>
	/// <param name="cells">Ячейки</param>
	/// <param name="whatNext">Во что переделается</param>
	/// <param name="quantity">Колличество того, во что переделается</param>
	/// <returns></returns>
	bool Progress(float& energy, std::vector<CellInInventory>& cells, int whatNext, int quantity);

	void Draw();
};

