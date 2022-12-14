#include "Linkedlist.h"
#include <iostream>

using namespace std;




	// Function to insert a
	// node at the end of the
	// linked list.
	void Linkedlist::insertNode(int data)
	{
		Node<int> *newNode = new Node<int>(data);

		// Assign to head
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		// Traverse till end of list
		Node<int> *temp = head;
		while (temp->next != nullptr)
		{

			// Update temp
			temp = temp->next;
		}

		// Insert at the last.
		temp->next = newNode;
		this->size++;
	}

	// Function to print the
	// linked list.
	void Linkedlist::printList()
	{
		Node<int> *temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void Linkedlist::sortList()
	{
		Node<int> *temp = head;
		Node<int> *temp2 = head;
		int tempData;
		while (temp != nullptr)
		{
			temp2 = temp->next;
			while (temp2 != nullptr)
			{
				if (temp->data > temp2->data)
				{
					tempData = temp->data;
					temp->data = temp2->data;
					temp2->data = tempData;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}

	int Linkedlist::getSize() {
		return this->size;
	}

	// Function to delete the
	// node at given position
	void Linkedlist::deleteNode(int toDelete)
	{
		Node<int> *temp = head;
		Node<int> *prev = nullptr;

		// If head node itself
		// holds the key to be deleted
		if (temp != nullptr && temp->data == toDelete)
		{
			head = temp->next; // Changed head
			delete temp; // free old head
			return;
		}

		// Search for the key to be deleted,
		// keep track of the previous node as we
		// need to change 'prev->next'
		while (temp != nullptr && temp->data != toDelete)
		{
			prev = temp;
			temp = temp->next;
		}

		// If key was not present in linked list
		if (temp == nullptr)
			return;

		// Unlink the node from linked list
		prev->next = temp->next;

		this->size--;
		// Free memory
		delete temp;
	};

	bool Linkedlist::isNodeInList(int toFind)
	{
		Node<int> *temp = head;
		while (temp != nullptr)
		{
			if (temp->data == toFind)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}



