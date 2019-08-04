#include "common.hpp"

#include <iostream>

using std::cout;
using std::endl;

bool checkBadLetterSequence(const char lastLetter, const char currentLetter) {
	if (
		(lastLetter == 'a' && currentLetter == 'b')
	||	(lastLetter == 'c' && currentLetter == 'd')
	||  (lastLetter == 'p' && currentLetter == 'q')
	|| 	(lastLetter == 'x' && currentLetter == 'y')
		) 
	{
		return true;
	}

	return false;
}

bool isNiceString(const int countVowels, const bool hasRepeatingLetters, const bool hasBadLetterSequence) {
	if (countVowels < 3) {
		return false;
	}

	if (!hasRepeatingLetters) {
		return false;
	}

	if (hasBadLetterSequence) {
		return false;
	}

	return true;
}

uint32_t countNiceStrings(const string instructions) {
	uint32_t countNiceStrings = 0;

	uint32_t countVowels = 0;
	char lastLetter = ' ';
	bool hasRepeatingLetters = false;
	bool hasBadLetterSequence = false;

	for (const char currentLetter : instructions) {
		if (currentLetter == lastLetter) {
			hasRepeatingLetters = true;
		}

		hasBadLetterSequence = checkBadLetterSequence(lastLetter, currentLetter);

		switch (currentLetter) {
			case '\n':
				if (isNiceString(countVowels, hasRepeatingLetters, hasBadLetterSequence)) {
					countNiceStrings++;
				}

				countVowels = 0;
				hasRepeatingLetters = false;
				hasBadLetterSequence = false;
				break;
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				countVowels++;
		}
	}

	return countNiceStrings;
}

int main() {
	const string instructions = readInput("five.txt");

	cout << "Nice strings: " << countNiceStrings(instructions) << endl;

	return 0;
}
