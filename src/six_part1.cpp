#include <iostream>
#include "common.hpp"

using std::cout;

bool lights[1000][1000];

void toggle(int row, int col) {
	lights[row][col] = !lights[row][col];
}

void set(int row, int col, bool value) {
	lights[row][col] = value;
}

struct SantaLightingCommandment {
	enum {
		TURN_ON,
		TURN_OFF,
		TOGGLE
	} action;

	uint32_t fromX;
	uint32_t fromY;
   	uint32_t toX;
	uint32_t toY;	
}; 

SantaLightingCommandment* parseCommandment(string line) {
	auto slc = new SantaLightingCommandment();
	string pat = "^([a-z ]+) (\\d+),(\\d+) through (\\d+),(\\d+)$"; 

	auto matches = matchLine(pat, line);


	if (matches->size() != 6) {
		cout << "Could not parse line: " << line << endl;
		return NULL;
	} else {
		cout << "got:" << matches->str(2) << ":" << endl;

		/*
		slc->fromX = atoi(matches.str(2).c_str());
		slc->fromY = atoi(matches.str(3).c_str());
		slc->toX = atoi(matches.str(4).c_str());
		slc->toY = atoi(matches.str(5).c_str());
		*/
	}

	return slc;
}

int main() {
	for (int col = 0; col < 1000; col++) {
		for (int row = 0; row < 1000; row++) {
			set(row, col, false);
		}
	}

	auto input = readInputStream("six.txt");
	string line = "";

	while (getline(input, line)) {
		auto commandment = parseCommandment(line);
	}
}
