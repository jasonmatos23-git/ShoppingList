// List.cpp
// Defines the class for list.

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "ShoppingList.h"

// ------------
// Constructors
// ------------
List::List(const char* name, const char* description) :
	ListDescriptor(name, description)
{
	this->m_listItems = {};
}

List::List(const char* name) :
	ListDescriptor(name, static_cast<const char*>(nullptr)) {}

// ---------
// Modifiers
// ---------
void List::addListItem(ListItem* item)
{
	this->m_listItems.emplace_back(item);
}

void List::removeListItem(int index)
{
	this->m_listItems.erase(this->m_listItems.begin() + index);
}

void List::printListItem(unsigned int index, unsigned int filter)
{
	ListItem* li = this->m_listItems.at(index);
	std::cout << index << ": " << "\n";
	if (filter & ListItem::Filter::NAME)
	{
		std::cout << "Name:\t";
		if (li->getName() != nullptr)
		{
			std::cout << li->getName();
		}
		std::cout << "\n";
	}
	if (filter & ListItem::Filter::DESCRIPTION)
	{
		std::cout << "Desc:\t";
		if (li->getDescription() != nullptr)
		{
			std::cout << li->getDescription();
		}
		std::cout << "\n";
	}
	if (filter & ListItem::Filter::QUANTITY)
	{
		std::cout << "Quantity:\t";
		std::cout << li->getQuantity() << "\n";
	}
	if (filter & ListItem::Filter::CATEGORY)
	{
		std::cout << "Category:\t";
		std::cout << li->getCategoryStr() << "\n";
	}
}

void List::printListItems(unsigned int filter)
{
	for (unsigned int i = 0; i < this->m_listItems.size(); i++)
	{
		printListItem(i, filter);
	}
}

void List::printListItems(void)
{
	this->printListItems(ListItem::Filter::ALL);
}
