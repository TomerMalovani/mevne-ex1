#include "State.h"
#include <iostream>

void State::addRoad(int city1, int city2){
	// cities vector is a vector of linked lists
	this->cities[city1-1].insertNode(city2);
	this->cities[city2-1].insertNode(city1);
}

void State::sortState(){
	// sort each linked list in the vector
	for (int i = 0; i < this->size; i++){
		this->cities[i].sortList();
	}
}

void State::print(){
	// print each linked list in the vector
	for (int i =0; i < this->size; i++){
		std::cout << i+1 << ")" << "(" << this->cities[i].getSize() << ")";
		this->cities[i].printList();
	}
}
