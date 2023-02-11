// ShoppingList.h
// Provides enums for categories of items.

#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H


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
	ListDescriptor(const char* name, int nameLength, const char* description, int descLength);

	// ----------
	// Destructor
	// ----------
	~ListDescriptor(void);

	// -------------------
	// Getters and Setters
	// -------------------
public:
	char* getName(void);
	char* setName(char* name);
	char* setName(const char* name, int length);
	char* setName(const char* name);

	char* getDescription(void);
	char* setDescription(char* description);
	char* setDescription(const char* description, int length);
	char* setDescription(const char* description);
};


class ListItem: public ListDescriptor
{
	// ----------------------
	// Constants (class vars)
	// ----------------------
private:
	static unsigned int kDefaultItemQuantity;

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
	ListItem(const char* name, int nameLength, const char* description, int descLength,
		unsigned int quantity, Category category);
	ListItem(const char* name, int nameLength, unsigned int quantity, Category category);
	ListItem(const char* name, int nameLength, unsigned int quantity);
	ListItem(const char* name, int nameLength);
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

#endif // SHOPPING_LIST_H
