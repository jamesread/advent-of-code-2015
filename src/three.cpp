#include "common.hpp"

#include <iostream>

using namespace std;

struct TravellingFatman {
	int x = 0;
	int y = 0;

	map<string, int>* mapOfTheWorld;

	TravellingFatman(map<string, int>* mapOfTheWorld) {
		this->mapOfTheWorld = mapOfTheWorld;	
	}

	void north() {
		this->y++;
		this->deliverPresent();
	}

	void south() {
		this->y--;
		this->deliverPresent();
	}

	void east() {
		this->x++;
		this->deliverPresent();
	}

	void west() {
		this->x--;
		this->deliverPresent();
	}

	void deliverPresent() {
		string pos = to_string(this->x) + ":" + to_string(this->y);

		if (this->mapOfTheWorld->find(pos) == this->mapOfTheWorld->end()) {
			(*this->mapOfTheWorld)[pos] = 0;
		}

		(*this->mapOfTheWorld)[pos]++;
	}
};

bool santasTurn = true;

void giveInstructionsToFatmen(string input, TravellingFatman* one, TravellingFatman* two) {
	TravellingFatman* punter;

	cout << input << endl;

	for (char command : input) {
		if (santasTurn) {
			punter = one;
		} else {
			punter = two;
		}

		switch (command) {
			case '^': 
				punter->north(); break;
			case 'v': 
				punter->south(); break;
			case '>': 
				punter->east(); break;
			case '<': 
				punter->west(); break;
			case ' ': 
			case '\n':
				break;
			default: 
				cout << "wtf are you trying to get poor Santa to do?!: " << command << endl;
		}
	
		santasTurn = !santasTurn;
	}
}

int main() {
	cout << "three" << endl;

	map<string, int> mapOfTheWorld;
	mapOfTheWorld["0:0"] = 1;

	TravellingFatman realSanta(&mapOfTheWorld);
	TravellingFatman roboSanta(&mapOfTheWorld);

	giveInstructionsToFatmen(readInput("three.txt"), &realSanta, &roboSanta);
	
	cout << "Santa (The real one) and Robo-Santa visted a combine total of: " << mapOfTheWorld.size() << " houses!" << endl;
}
