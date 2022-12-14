#pragma once
// daynmic type node
template <class T>
class Node
{

public:
	T data;
	Node<T> *next= nullptr;;


	Node(T data) {
		this->data = data;

	}
	~Node() {
		
	}





	
};
