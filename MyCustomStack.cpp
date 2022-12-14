#include "MyCustomStack.h"
#include <iostream>

using namespace std;

void MyCustomStack::makeEmpty()
{
	Node<ItemType> *temp = top;
	while (temp != nullptr)
	{
		Node<ItemType> *next = temp->next;
		delete temp;
		temp = next;
	}
	top = nullptr;
}

bool MyCustomStack::isEmpty()
{
	return top == nullptr;
}

void MyCustomStack::push(ItemType item)
{
	Node<ItemType> *newNode = new Node<ItemType>(item);
	newNode->next = top;
	top = newNode;
}

ItemType MyCustomStack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
		return ItemType();
	}
	else
	{
		Node<ItemType> *temp = top;
		ItemType item = top->data;
		top = top->next;
		delete temp;
		return item;
	}
}

ItemType MyCustomStack::Top()
{
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
		return ItemType();
	}
	else
	{
		return top->data;
	}
}

