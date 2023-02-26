// ListDescriptor.cpp
// Defines the abstract class for list item descriptions.

#include <stdexcept>
#include <cstdlib>
#include "ShoppingList.h"

// -------
// Helpers
// -------
char* ListDescriptor::setString(char** m_str, const char* i_str, int length)
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
			throw new std::invalid_argument("ListDescriptor->string length should not be less than 1.");
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

char* ListDescriptor::setString(char** m_str, const char* i_str)
{
	int length{ 0 };
	if (m_str == nullptr)
	{
		throw new std::invalid_argument("setString char** m_str cannot be nullptr.");
	}
	if (i_str != nullptr)
	{
		while (i_str[length++] != '\0');
		length++;
	}
	return setString(m_str, i_str, length);
}

// -----------
// Constructor
// -----------
ListDescriptor::ListDescriptor(const char* name, const char* description)
{
	this->m_name = nullptr;
	this->m_description = nullptr;
	try
	{
		this->setName(name);
		this->setDescription(description);
	}
	catch (std::exception setNameException)
	{
		free(this->m_description);
		free(this->m_name);
		this->m_description = nullptr;
		this->m_name = nullptr;
		throw setNameException;
	}
}

// ----------
// Destructor
// ----------
ListDescriptor::~ListDescriptor(void)
{
	free(this->m_name);
	free(this->m_description);
}

// ----------------
// Copy Constructor
// ----------------
ListDescriptor::ListDescriptor(const ListDescriptor& listDescriptor)
{
	this->setName(static_cast<const char*>(listDescriptor.m_name));
	this->setDescription(static_cast<const char*>(listDescriptor.m_description));
}

// ------------------------
// Copy Assignment Operator
// ------------------------
ListDescriptor& ListDescriptor::operator=(const ListDescriptor& listDescriptor)
{
	this->setName(static_cast<const char*>(listDescriptor.m_name));
	this->setDescription(static_cast<const char*>(listDescriptor.m_description));
	return *this;
}

// -------------------
// Getters and Setters
// -------------------
char* ListDescriptor::getName(void)
{
	return this->m_name;
}

char* ListDescriptor::setName(char* name)
{
	char* temp{ this->m_name };
	this->m_name = name;
	return temp;
}

char* ListDescriptor::setName(const char* name)
{
	return setString(&this->m_name, name);
}



char* ListDescriptor::getDescription(void)
{
	return this->m_description;
}

char* ListDescriptor::setDescription(char* description)
{
	char* temp{ this->m_description };
	this->m_description = description;
	return temp;
}

char* ListDescriptor::setDescription(const char* description)
{
	return setString(&this->m_description, description);
}
