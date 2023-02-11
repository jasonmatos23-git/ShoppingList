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
	// Filter bit flags - TODO: Not hard code them
	// 0<<0: All content
	// 1<<0: Disable name
	// 1<<1: Disable description
	// 1<<2: Disable quantity
	// 1<<3: Disable category
	ListItem* li = this->m_listItems.at(index);
	std::cout << index << ": ";
	if ((filter & (1 << 0)) != (1 << 0))
	{
		if (li->getName() != nullptr)
		{
			std::cout << li->getName();
		}
		std::cout << "\n";
	}
	if ((filter & (1 << 1)) != (1 << 1))
	{
		if (li->getDescription() != nullptr)
		{
			std::cout << li->getDescription();
		}
		std::cout << "\n";
	}
	if ((filter & (1 << 2)) != (1 << 2))
	{
		std::cout << li->getQuantity() << "\n";
	}
	if ((filter & (1 << 3)) != (1 << 3))
	{
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
