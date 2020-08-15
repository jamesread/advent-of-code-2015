#include <iostream>
#include <regex>
#include "common.hpp"
#include "six.hpp"

using std::cout;
using std::endl;

bool lights[1000][1000];

void toggle(int row, int col) {
	lights[row][col] = !lights[row][col];
}

void set(int row, int col, bool value) {
	lights[row][col] = value;
}

Action actionStringToEnum(string action) {
	if (action == "turn on") {
		return Action::TURN_ON;
	} else if (action == "turn off") {
		return Action::TURN_OFF;
	} else if (action == "toggle") {
		return Action::TOGGLE;
	} else {
		throw "Unexpected action:" + action;
	}
}


SantaLightingCommandment* parseCommandment(string line) {
	auto slc = new SantaLightingCommandment();
	string pat = "^([a-z ]+) (\\d+),(\\d+) through (\\d+),(\\d+)$"; 

	std::regex re(pat);
	std::smatch matches;
	std::regex_search(line, matches, re);

	if (matches.size() != 6) {
		cout << "Could not parse line: " << line << endl;
		return NULL;
	} else {
		slc->action = actionStringToEnum(matches[1]);
		slc->fromCol = atoi(matches.str(2).c_str());
		slc->fromRow = atoi(matches.str(3).c_str());
		slc->toCol = atoi(matches.str(4).c_str());
		slc->toRow = atoi(matches.str(5).c_str());
		
	}

	return slc;
}

void processCommandment(SantaLightingCommandment* slc) {
	for (uint32_t col = slc->fromCol; col < slc->toCol; col++) {
		for (uint32_t row = slc->fromRow; row < slc->toRow; row++) {
			switch (slc->action) {
				case TURN_ON:
					set(row, col, true);
					break;
				case TURN_OFF:
					set(row, col, false);
					break;
				case TOGGLE:
					if (lights[row][col]) {
						set(row, col, false);
					} else {
						set(row, col, true);
					}
					break;
			}
		}
	}
}

int countLights() {
	int count = 0;

	for (int col = 0; col < 1000; col++) {
		for (int row = 0; row < 1000; row++) {
			if (lights[row][col]) {
				count++;
			}
		}
	}

	return count;
}


