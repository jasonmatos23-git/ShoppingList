// ListItem.cpp
// Defines the class for shopping list items.

#include <stdexcept>
#include <cstdlib>
#include "ShoppingList.h"

// ------------
// Constructors
// ------------
ListItem::ListItem(const char* name, const char* description, unsigned int quantity, Category category) :
	ListDescriptor(name, description)
{
	// Quantity
	this->m_quantity = quantity;

	// Category
	this->m_category = category;
}

// Name, quantity, category provided
ListItem::ListItem(const char* name, unsigned int quantity, Category category) :
	ListItem(name, static_cast<const char*>(nullptr), quantity, category) {}

// Name, quantity provided
ListItem::ListItem(const char* name, unsigned int quantity) :
	ListItem(name, static_cast<const char*>(nullptr), quantity, Category::NONE) {}

// Name provided
ListItem::ListItem(const char* name) :
	ListItem(name, static_cast<const char*>(nullptr), ListItem::kDefaultItemQuantity, Category::NONE) {}

ListItem::ListItem(void) :
	ListItem(static_cast<const char*>(nullptr), static_cast<const char*>(nullptr), ListItem::kDefaultItemQuantity, Category::NONE) {}

// -------------------
// Getters and Setters
// -------------------
unsigned int ListItem::getQuantity(void)
{
	return this->m_quantity;
}

unsigned int ListItem::setQuantity(unsigned int quantity)
{
	return this->m_quantity = quantity;
}


ListItem::Category ListItem::getCategory(void)
{
	return this->m_category;
}

ListItem::Category ListItem::setCategory(Category category)
{
	return this->m_category = category;
}

// -------
// Utility
// -------
const char* ListItem::categoryToString(Category category)
{
	switch (category)
	{
		case Category::AUTOMOTIVE:
			return "AUTOMOTIVE";
			break;
		case Category::BAKERY:
			return "BAKERY";
			break;
		case Category::CLEANING:
			return "CLEANING";
			break;
		case Category::DAIRY:
			return "DAIRY";
			break;
		case Category::DELI:
			return "DELI";
			break;
		case Category::ELECTRONIC:
			return "ELECTRONIC";
			break;
		case Category::MEAT:
			return "MEAT";
			break;
		case Category::NONE:
			return "NONE";
			break;
		case Category::OTHER:
			return "OTHER";
			break;
		case Category::PRODUCE:
			return "PRODUCE";
			break;
		case Category::TOILETRIES:
			return "TOILETRIES";
			break;
		default:
			return "WARNING: Category string not found.";
	}
}

const char* ListItem::getCategoryStr(void)
{
	return ListItem::categoryToString(this->m_category);
}
