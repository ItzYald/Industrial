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
	/// ������� ������ (������, ������, ���������...)
	/// </summary>
	/// <param name="energy">������ �� �������</param>
	/// <param name="cells">������</param>
	/// <param name="whatNext">�� ��� ������������</param>
	/// <param name="quantity">����������� ����, �� ��� ������������</param>
	/// <returns></returns>
	bool Progress(float& energy, std::vector<CellInInventory>& cells, int whatNext, int quantity);

	void Draw();
};

