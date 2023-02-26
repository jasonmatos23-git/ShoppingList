// ShoppingList.cpp
// Main file. Contains primary app logic.

#include <iostream>
#include "ShoppingList.h"

int main(void)
{
	ListItem* li = new ListItem();
	li->setName("Avocado");
	std::cout << li->getName() << '\n';
	li->setName("Hass Avocado");
	std::cout << li->getName() << '\n';
	li->setDescription("For the guacamole on Saturday");
	std::cout << li->getDescription() << '\n';
	li->setCategory(ListItem::Category::PRODUCE);
	std::cout << li->getCategoryStr() << '\n';
	li->setQuantity(3);
	std::cout << li->getQuantity() << '\n';
	return 0;
}
