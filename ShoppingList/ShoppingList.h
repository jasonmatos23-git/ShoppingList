// ShoppingList.h
// Provides enums for categories of items.

#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <vector>


class ListDescriptor
{
	// -----------
	// Member vars
	// -----------
protected:
	char* m_name;
	char* m_description;

	// -------
	// Helpers
	// -------
protected:
	static char* setString(char** m_str, const char* i_str, int length);
	static char* setString(char** m_str, const char* i_str);

	// -----------
	// Constructor
	// -----------
	ListDescriptor(const char* name, const char* description);

	// ----------
	// Destructor
	// ----------
	~ListDescriptor(void);

	// ----------------
	// Copy Constructor
	// ----------------
	ListDescriptor(const ListDescriptor& listDescriptor);

	// ------------------------
	// Copy Assignment Operator
	// ------------------------
	ListDescriptor& operator=(const ListDescriptor& listDescriptor);

	// -------------------
	// Getters and Setters
	// -------------------
public:
	char* getName(void);
	char* setName(char* name);
	char* setName(const char* name);

	char* getDescription(void);
	char* setDescription(char* description);
	char* setDescription(const char* description);
};


class ListItem: public ListDescriptor
{
	// ----------------------
	// Constants (class vars)
	// ----------------------
private:
	const static unsigned int kDefaultItemQuantity = 1;

public:
	enum class Category
	{
		PRODUCE,
		BAKERY,
		DELI,
		DAIRY,
		MEAT,
		AUTOMOTIVE,
		TOILETRIES,
		CLEANING,
		ELECTRONIC,
		OTHER,
		NONE
	};

	enum Filter : unsigned int
	{
		NAME = 1<<0,
		DESCRIPTION = 1<<1,
		QUANTITY = 1<<2,
		CATEGORY = 1<<3,
		ALL = NAME | DESCRIPTION | QUANTITY | CATEGORY
	};

	// -----------
	// Member vars
	// -----------
private:
	unsigned int m_quantity;
	Category m_category;

	// ------------
	// Constructors
	// ------------
public:
	ListItem(const char* name, const char* description, unsigned int quantity, Category category);
	ListItem(const char* name, const char* description, unsigned int quantity);
	ListItem(const char* name, const char* description, Category category);
	ListItem(const char* name, const char* description);
	ListItem(const char* name, unsigned int quantity, Category category);
	ListItem(const char* name, unsigned int quantity);
	ListItem(const char* name, Category category);
	ListItem(const char* name);
	ListItem(void);

	// -------------------
	// Getters and Setters
	// -------------------
public:
	unsigned int getQuantity(void);
	unsigned int setQuantity(unsigned int quantity);

	Category getCategory(void);
	Category setCategory(Category category);

	// -------
	// Utility
	// -------
	// Note: May define a map instead
	static const char* categoryToString(Category category);
	const char* getCategoryStr(void);
};


class List: public ListDescriptor
{
	// -----------
	// Member vars
	// -----------
private:
	std::vector<ListItem*> m_listItems;
	
	// -----------
	// Constructor
	// -----------
public:
	List(const char* name, const char* description);
	List(const char* name);

	// ---------
	// Modifiers
	// ---------
	void addListItem(ListItem* item);
	void removeListItem(int index);
	void printListItem(unsigned int index, unsigned int filter);
	void printListItems(unsigned int filter);
	void printListItems(void);
};

#endif // SHOPPING_LIST_H
