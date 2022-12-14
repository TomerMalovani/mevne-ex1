#pragma once
#include "Node.h"
class Linkedlist {
private:
	Node<int> *head;
	int size = 1;
public:

    ~Linkedlist() {
		Node<int> * temp = head;
		while (temp != nullptr) {
			Node<int> *next = temp->next;
			delete temp;
            temp = next;
        }

    }
    // Default constructor
    Linkedlist() { head = nullptr; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    int getSize();

    // Function to print the
    // linked list.
    void printList();

void sortList();

	// Function to delete the
	// node at given position
	void deleteNode(int);

bool isNodeInList(int);

int operator[](int index)
{
		Node<int> *temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
	}
	return temp->data;
}
};

