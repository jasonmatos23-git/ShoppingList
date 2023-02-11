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
	List list = List("My new list", 50, "This list is a new list", 50);
	ListItem li2 = ListItem("Avocado", 50, 12);
	list.addListItem(li2);
	list.addListItem(ListItem("Motor Oil", 50, 2, ListItem::Category::AUTOMOTIVE));
	list.printListItems(0);
	return 0;
}
