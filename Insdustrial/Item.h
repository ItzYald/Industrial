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
	int whatBurn;
	// Может ли быть топливом и сколько даст топлива
	int whatFuel;
	// Может ли быть сжатым и во что сожмется
	int whatCompress;
	// Может ли дробиться и во что дробится (x - во что дробится, y - сколько получится)
	sf::Vector2i whatCrush;
	
	Item(){}
	Item(int _number, int _quantity);

	/// <summary>Обновление id предмета</summary>
	/// <param name="_number">ID предмета</param>
	void NumberUpdate(int _number);

};

