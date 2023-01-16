// ListItem.cpp
// Defines the class for shopping list items.

#include <stdexcept>
#include <cstdlib>
#include "ShoppingList.h"

// ---------
// Constants
// ---------
unsigned int ListItem::kDefaultItemQuantity = 1;

// ------------
// Constructors
// ------------
ListItem::ListItem(const char* name, int nameLength, const char* description, int descLength, unsigned int quantity, Category category)
{
	this->m_name = nullptr;
	this->m_description = nullptr;

	// Name
	this->setName(name, nameLength);

	// Description
	try
	{
		this->setDescription(description, descLength);
	}
	catch (std::exception setNameException)
	{
		free(this->m_name);
		this->m_name = nullptr;
		throw setNameException;
	}

	// Quantity
	this->m_quantity = quantity;

	// Category
	this->m_category = category;
}

// Name, quantity, category provided
ListItem::ListItem(const char* name, int nameLength, unsigned int quantity, Category category) :
	ListItem(name, nameLength, static_cast<const char*>(nullptr), 0, quantity, category){}

// Name, quantity provided
ListItem::ListItem(const char* name, int nameLength, unsigned int quantity) :
	ListItem(name, nameLength, static_cast<const char*>(nullptr), 0, quantity, Category::NONE) {}

// Name provided
ListItem::ListItem(const char* name, int nameLength) :
	ListItem(name, nameLength, static_cast<const char*>(nullptr), 0, ListItem::kDefaultItemQuantity, Category::NONE) {}

ListItem::ListItem(void) :
	ListItem(static_cast<const char*>(nullptr), 0, static_cast<const char*>(nullptr), 0, ListItem::kDefaultItemQuantity, Category::NONE) {}

// ----------
// Destructor
// ----------
ListItem::~ListItem(void)
{
	free(this->m_name);
	free(this->m_description);
}

// -------
// Helpers
// -------
char* ListItem::setString(char** m_str, const char* i_str, int length)
{
	if (i_str == nullptr)
	{
		free(*m_str);
		*m_str = nullptr;
		return nullptr;
	}
	else
	{
		if (length < 1)
		{
			throw new std::invalid_argument("ListItem->string length should not be less than 1.");
		}
		else
		{
			*m_str = static_cast<char*>(malloc(length * sizeof(char)));
			if (*m_str == nullptr)
			{
				throw new std::bad_alloc;
			}
			else
			{
				memcpy(*m_str, i_str, length);
				return *m_str;
			}
		}
	}
}

char* ListItem::setString(char** m_str, const char* i_str)
{
	int length{ 0 };
	if (i_str != nullptr)
	{
		while (i_str[length++] != '\0') {}
	}
	return setString(m_str, i_str, length);
}

// -------------------
// Getters and Setters
// -------------------
char* ListItem::getName(void)
{
	return this->m_name;
}

char* ListItem::setName(char* name)
{
	char* temp {this->m_name};
	this->m_name = name;
	return temp;
}

char* ListItem::setName(const char* name, int length)
{
	return setString(&this->m_name, name, length);
}

char* ListItem::setName(const char* name)
{
	return setString(&this->m_name, name);
}



char* ListItem::getDescription(void)
{
	return this->m_description;
}

char* ListItem::setDescription(char* description)
{
	char* temp {this->m_description};
	this->m_description = description;
	return temp;
}

char* ListItem::setDescription(const char* description, int length)
{
	return setString(&this->m_description, description, length);
}

char* ListItem::setDescription(const char* description)
{
	return setString(&this->m_description, description);
}


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
