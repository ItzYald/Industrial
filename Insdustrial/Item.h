#pragma once
#include "SFML/System.hpp"


class Item
{
public:
	// Название предмета
	sf::String name;
	// Номер (id) предмета
	int number;
	// Количество
	int quantity;
	// Горит ли и в какой предмет сгорает (в какой переплавляется)
	int isBurn;
	// Может ли быть топливом и сколько даст топлива
	int isFuel;
	
	Item(int _number, int _quantity);

	/// <summary>Обновление id предмета</summary>
	/// <param name="_number">ID предмета</param>
	void NumberUpdate(int _number);

};

