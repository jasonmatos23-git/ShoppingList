// List.cpp
// Defines the class for list.

#include <stdexcept>
#include <cstdlib>
#include "ShoppingList.h"

List::List(const char* name, int nameLength, const char* description, int descLength) :
	ListDescriptor(name, nameLength, description, descLength)
{
	this->m_listItems = {};
}
