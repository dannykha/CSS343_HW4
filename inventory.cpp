#include "inventory.h"
#include <iostream>

Inventory::Inventory()
{}

void Inventory::printInventory()
{
    cout << "Inventory; ";
}

void Inventory::executeInventory()
{
    Store::printInventory();
}