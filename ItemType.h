#pragma once
#include "State.h"
class ItemType
{
	public:
		ItemType(State *s, int x, int w, std::vector<bool> v) : state(s), townX(x), townW(w), visted(v){

		};

		// empty constructor
		ItemType() : state(new State()), townX(0), townW(0), visted(std::vector<bool>()){

		};

		// copy constructor
		ItemType(const ItemType &other) : state(other.state), townX(other.townX), townW(other.townW), visted(other.visted){

		};
		~ItemType(){

		};
		State * state;
		int townX; 
		int townW;
		int line;
		int distance=0;
		std::vector<bool> visted;
	
};

