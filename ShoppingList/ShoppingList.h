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

	// -------------------
	// Getters and Setters
	// -------------------
public:
	virtual char* getName(void);
	virtual char* setName(char* name);
	virtual char* setName(const char* name, int length);
	virtual char* setName(const char* name);

	virtual char* getDescription(void);
	virtual char* setDescription(char* description);
	virtual char* setDescription(const char* description, int length);
	virtual char* setDescription(const char* description);
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

	// ----------
	// Destructor
	// ----------
	~ListItem(void);

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
