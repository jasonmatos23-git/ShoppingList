// List.cpp
// Defines the class for list.

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>
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
	int kDefaultIndentWidth = 15;
	std::cout << index << ": " << "\n";
	if (filter & ListItem::Filter::NAME)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(kDefaultIndentWidth) << "Name:\t";
		if (li->getName() != nullptr)
		{
			std::cout << li->getName();
		}
		std::cout << "\n";
	}
	if (filter & ListItem::Filter::DESCRIPTION)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(kDefaultIndentWidth) << "Description:\t";
		if (li->getDescription() != nullptr)
		{
			std::cout << li->getDescription();
		}
		std::cout << "\n";
	}
	if (filter & ListItem::Filter::QUANTITY)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(kDefaultIndentWidth) << "Quantity:\t";
		std::cout << li->getQuantity() << "\n";
	}
	if (filter & ListItem::Filter::CATEGORY)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(kDefaultIndentWidth) << "Category:\t";
		std::cout << li->getCategoryStr() << "\n";
	}
}

void List::printListItems(unsigned int filter)
{
	std::cout << this->getName() << '\n';
	if (this->getDescription() != nullptr)
	{
		std::cout << this->getDescription() << '\n';
	}
	for (unsigned int i = 0; i < this->m_listItems.size(); i++)
	{
		printListItem(i, filter);
	}
}

void List::printListItems(void)
{
	this->printListItems(ListItem::Filter::ALL);
}
