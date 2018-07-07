#include "common.hpp"

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int feetOfWrappingPaperNeeded(int l, int w, int h) {
	int sideSurfaceArea = l * w;
	int endSurfaceArea = w * h;
	int topSurfaceArea = h * l;

	int smallestSurface = min(sideSurfaceArea, min(endSurfaceArea, topSurfaceArea));

	return (2 * sideSurfaceArea) + (2 * endSurfaceArea) + (2 * topSurfaceArea) + smallestSurface;
}

int mid(int a, int b, int c) {
	return max(min(a,b), min(max(a,b),c));
}

int lengthOfRibbonNeeded(int l, int w, int h) {
	int smallest = min(l, min(w, h));
	int secondSmallest = mid(l, w, h);
	int perimiterLength = (smallest*2 +  secondSmallest*2 );

	int bowLength = l * w * h;

	return perimiterLength + bowLength;
}

int main() {
	cout << "two!" << endl;

	int totalFeetOfWrappingPaperNeeded = 0;
	int totalLengthOfRibbonNeeded = 0;

	string boxes = readInput("two.txt");
	stringstream boxStream(boxes);
	string line;

	int l, w, h; 

	while (getline(boxStream, line)) {
		auto m = matchLine("(\\d+)x(\\d+)x(\\d+)", line);

		if (m.size() != 4) {
			cout << "error with line: " << line;
		} else {
			l = atoi(m.str(1).c_str());
			w = atoi(m.str(2).c_str());
			h = atoi(m.str(3).c_str());

			totalFeetOfWrappingPaperNeeded += feetOfWrappingPaperNeeded(l, w, h);
			totalLengthOfRibbonNeeded += lengthOfRibbonNeeded(l, w, h);
		}
	}

	cout << "Total material needed: " << totalFeetOfWrappingPaperNeeded << " ft" << endl;
	cout << "Total ribbon needed: " << totalLengthOfRibbonNeeded << " ft" << endl;

	return 0;
}
