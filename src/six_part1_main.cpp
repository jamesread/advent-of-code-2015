#include <iostream>

#include "common.hpp"
#include "six.hpp"

using std::cout, std::endl;

int main() {
	for (int col = 0; col < 1000; col++) {
		for (int row = 0; row < 1000; row++) {
			set(row, col, false);
		}
	}

	auto input = readInputStream("six.txt");
	string line = "";

	while (getline(input, line)) {
		processCommandment(parseCommandment(line));
	}

	cout << "Number of lit lights: " << countLights() << endl;
}
