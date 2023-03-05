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

ListItem::ListItem(const char* name, const char* description, unsigned int quantity) :
	ListItem(name, description, quantity, Category::NONE) {}

ListItem::ListItem(const char* name, const char* description, Category category) :
	ListItem(name, description, kDefaultItemQuantity, category) {}

ListItem::ListItem(const char* name, const char* description) :
	ListItem(name, description, kDefaultItemQuantity, Category::NONE) {}

ListItem::ListItem(const char* name, unsigned int quantity, Category category) :
	ListItem(name, static_cast<const char*>(nullptr), quantity, category) {}

ListItem::ListItem(const char* name, unsigned int quantity) :
	ListItem(name, static_cast<const char*>(nullptr), quantity, Category::NONE) {}

ListItem::ListItem(const char* name, Category category) :
	ListItem(name, static_cast<const char*>(nullptr), kDefaultItemQuantity, category) {}

ListItem::ListItem(const char* name) :
	ListItem(name, static_cast<const char*>(nullptr), kDefaultItemQuantity, Category::NONE) {}

ListItem::ListItem(void) :
	ListItem(static_cast<const char*>(nullptr), static_cast<const char*>(nullptr), kDefaultItemQuantity, Category::NONE) {}

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
const char* ListItem::getCategoryStr(void)
{
	return ListItem::categoryStr(this->m_category);
}
