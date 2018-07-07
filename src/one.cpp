#include <iostream>

#include "common.hpp"

using namespace std;

int main() {
	int floor = 0;
	string instructions = readInput("one.txt");

	for (uint32_t i = 0; i < instructions.length(); i++) {
		const char c = instructions[i];
		switch (c) {
			case '(':
				floor++;
				break;
			case ')':
				floor--;
				break;
		}

		if (floor == -1) {
			cout << "Santa entered the basement on instruction number " << (i + 1) << endl;
		}
	}

	cout << "floor: " << floor << endl;

	return 0;
}
