//********************************************************************************
// Main.cpp
//
// (C) 2019 TerseWorks. All rights reserved.
// TerseWorks Public Code License (https://www.terseworks.com/licensing).
//
// Written by: John Meschke
// Description: Main program entry point.
//********************************************************************************

#include "Pointers.h"
#include <iostream>

//********************************************************************************
// Item
//********************************************************************************

class Item
{
	public:
		Item();
		Item(int id);
		~Item();
		int getId() const;

	private:
		int id;
};

/*
Item constructor.
*/
Item::Item() : id(0)
{
	std::cout << "Constructing item " << id << "." << std::endl;
}

/*
Item constructor.
*/
Item::Item(int id) : id(id)
{
	std::cout << "Constructing item " << id << "." << std::endl;
}

/*
Item destructor.
*/
Item::~Item()
{
	std::cout << "Destructing item " << id << "." << std::endl;
}

/*
Get the item's ID.
*/
int Item::getId() const
{
	return id;
}

//********************************************************************************
// Main
//********************************************************************************

/*
Main entry function.
*/
int main()
{
	// Scoped pointer test 1.
	{
		ScopedPointer<Item> singleItem = new Item(100);
		ScopedArray<Item> multiItem = new Item[3];
	}
	std::cout << std::endl;

	// Scoped pointer test 2.
	{
		ScopedPointer<Item> resetItem = new Item(200);
		resetItem.reset(new Item(300));
	}
	std::cout << std::endl;

	// Scoped pointer test 3.
	{
		ScopedPointer<Item> swapItem1 = new Item(400);
		ScopedPointer<Item> swapItem2 = new Item(500);
		std::cout << "swapItem1: " << swapItem1->getId() << std::endl;
		std::cout << "swapItem2: " << swapItem2->getId() << std::endl;
		swapItem1.swap(swapItem2);
		std::cout << "Items swapped." << std::endl;
		std::cout << "swapItem1: " << swapItem1->getId() << std::endl;
		std::cout << "swapItem2: " << swapItem2->getId() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Press <enter> to quit.";
	std::cin.get();

	return 0;
}