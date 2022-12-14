
#include <iostream>
#include "Linkedlist.h"
#include "State.h"
#include "MyCustomStack.h"
using namespace std;

State initState()
{
	// get amount of cities and amount cities and roads
	int cities, roads;
	// ask for input
	cout << "enter amount of cities and roads " << endl;

	cin >> cities >> roads;
	// create a state  instance with the amount of cities
	State* state =  new State(cities);

	cout << "cities" << cities << " and roads " << roads << endl;
	// get new lines of numbers, split them into pairs of roads and add them to the state
	for (int i = 0; i < roads; i++)
	{
		int city1, city2;
		cin >> city1 >> city2;
		if (city1 > roads || city2 > roads || city1 < 1 || city2 < 1)
		{

			cout << "invaild road, try again" << endl;
			i--;
			continue;
		}
		else
		{

			if (state->operator[](city1 - 1).isNodeInList(city2))
			{
				cout << "road allready exist, try another one" << endl;
				i--;
				continue;
			}
			state->addRoad(city1, city2);
		}
	}

	// sort the state
	state->sortState();
	// print the state
	state->print();

	return * state;
}

// TownDistance function implementation with MyCustomStack insted of recursion with stack switch state	
int TownDistanceWithStack(State *state, int townX, int townW, vector<bool> visted){
	MyCustomStack stack;
	
	// create a new item type with the state, townX, townW and visted
	ItemType item(state, townX, townW, visted);
	// push the item to the stack
	stack.push(item);
	// while the stack is not empty
	while (!stack.isEmpty())
	{
		// pop the item from the stack
		ItemType item = stack.pop();


		cout << "got to city " << item.townX << endl;

		item.visted[item.townX - 1] = true;
		// if the item is the townW return the distance
		if (item.townX == item.townW)
		{
			return item.distance;
		}
		cout << " city " << item.townX << " have " << item.state->operator[](item.townX - 1).getSize() << " roads " << endl;

		// run on all the towns in townX to check if visted[i] is false
		for (int i = 0; i < item.state->operator[](item.townX - 1).getSize(); i++)
		{
			// if visted[i] is false
			if (!item.visted[item.state->operator[](item.townX - 1)[i] - 1])
			{
				cout << "going to road to city " << item.state->operator[](item.townX - 1)[i] << endl;
				// set visted[i] to true
				item.visted[item.state->operator[](item.townX - 1)[i] - 1] = true;
				// create a new item type with the state, townX, townW and visted
				ItemType newItem(item.state, item.state->operator[](item.townX - 1)[i], item.townW, item.visted);
				// set the distance of the new item to the distance of the old item + 1
				newItem.distance = item.distance + 1;
				// push the new item to the stack
				stack.push(newItem);
				item = newItem;
				i=0;
			}else{
				cout << "city " << item.state->operator[](item.townX - 1)[i] << " allready visted" << endl;
			}
		}

		
	}
}

	int TownDistance(State &state, int townX, int townW, vector<bool> visted)
{
	cout << "got to city " << townX << endl;

	int i = 0;
 	// if townX is townW return 0
	if (townX == townW)
	{
		return 0;
	}
	cout << "city " << townX << " have " << state[townX - 1].getSize() << " roads " << endl;


	// run on all the towns in townX to check if visted[i] is false
	for (i = 0; i < state[townX - 1].getSize(); i++)
	{
		visted[townX - 1] = true;

		// if visted[i] is false
		if (!visted[state[townX - 1][i] - 1])
		{

			cout << "going to road to city " << state[townX - 1][i] << endl;

			// set visted[i] to true
			visted[state[townX - 1][i] -1] = true;
			// run TownDistance on townX and townW
			int temp = TownDistance(state, state[townX-1][i], townW, visted);

			cout << "distance " << temp << endl;
			// if temp is not -1 return temp + 1
			if (temp != -1)
			{

				return temp + 1;
			

			}
			else {
				continue;
			}

		}
		else {
			cout << "city " << state[townX - 1][i]-1 << " is no good" << endl;
			continue;
		}

	}
	return -1;
}

int main()
{

	State state = initState();
	// create a vector of bools with size 5 and set all of them to false
	vector<bool> visted(5, false);
	cout << "recros" << TownDistance(state, 2, 5, visted) <<  endl;
	//vector<bool> visted2(5, false);
	//cout << "stack" << TownDistanceWithStack(&state, 2, 5, visted2) << endl;
}

