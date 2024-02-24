#include "WireInventory.h"

void WireInventory::Update(Inventory& playerInventory)
{
	AllUpdate(playerInventory);
}

void WireInventory::Next()
{
	AllNext();
}

void WireInventory::Draw()
{
	AllDraw();
}

