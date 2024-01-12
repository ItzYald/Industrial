#include "OvenInventory.h"

void OvenInventory::AllBurn()
{
	if (previousItemBurn2 != cells[0].item.number)
	{
		whatBurn = 120;
	}
	previousItemBurn2 = cells[0].item.number;
	if (cells[2].item.number == 0 || cells[2].item.number == itemsSprites.IsBurn(cells[0].item.number))
	{
		if (fuel > 0)
		{
			fuel -= 1;
			if (itemsSprites.IsBurn(cells[0].item.number))
			{
				whatBurn -= 1;
				if (whatBurn == 0)
				{
					whatBurn = 120;
					if (cells[2].item.number == itemsSprites.IsBurn(cells[0].item.number) && cells[2].item.number != 0)
					{
						cells[2].item.quantity += 1;
					}
					else
					{
						cells[2].item.number = itemsSprites.IsBurn(cells[0].item.number);
						cells[2].item.quantity = 1;
					}

					cells[0].item.quantity -= 1;
					if (cells[0].item.quantity == 0)
					{
						cells[0].item.number = 0;
					}
				}
			}
			else
			{
				whatBurn = 120;
			}
		}
		else
		{
			if (whatBurn < 120)
			{
				whatBurn += 1;
			}
		}
	}
	else
	{
		fuel -= 1;
	}

	if (fuel < 0)
	{
		fuel = 0;
	}
}
