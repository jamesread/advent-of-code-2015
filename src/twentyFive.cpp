#include <iostream>

using namespace std;

int next(uint64_t previous) {
	return (previous * 252533) % 33554393;
}

int main() {
	cout << "twenty five" << endl;

	uint64_t col = 1; 
	uint64_t row = 1;
	uint64_t current = 20151125;
	uint64_t linePosition = 1;
	uint64_t lineLength = 1;
	uint64_t rowstart = 1;
	
	while (true) {	
		if (linePosition == lineLength) {
			col = 1;
			rowstart++;
			row = rowstart;	

			linePosition = 0;
			lineLength += 1;
		} else {
			col++;
			row--;
		}

		linePosition++;

		current = next(current);

		if (row == 2981 && col == 3075) {
			break;
		}
	}

	cout << "row:" << row << ", col:" << col << ", (line position " << linePosition << " out of " << lineLength << ") = " << current << endl;
}
