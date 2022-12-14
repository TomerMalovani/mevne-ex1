#pragma once
#include "ItemType.h"
class MyCustomStack
{
	// custom stack class that works with ItemType
private:
Node<ItemType> *top;
public:
MyCustomStack() { top = nullptr; }

~MyCustomStack() {
	Node<ItemType> * temp = top;
	while (temp != nullptr) {
		Node<ItemType> *next = temp->next;
		delete temp;
		temp = next;
	}
}

void makeEmpty();
bool isEmpty();
void push(ItemType item);
ItemType pop();
ItemType Top();

	
};


