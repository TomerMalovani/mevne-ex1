#pragma once
#include "Linkedlist.h"
#include <vector>
class State
{
//   vector of a given size with  linked lists in each cell

	private:
		int size;
		std::vector<Linkedlist> cities;

	public:
		State(int size){
			this->size = size;
			cities.resize(size);
		};
		State(){
			this->size = 0;
	
		};
		~State(){
		//	cities.clear();
		};
		void print();
		void addRoad(int city1, int city2);
		void sortState();

		Linkedlist& operator[](int index) {
			return cities[index];
		}

	
};

