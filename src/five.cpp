#include "common.hpp"

#include <iostream>

using std::cout;
using std::getline;
using std::endl;
using std::istringstream;

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

bool isNiceString(const string test) {
	uint32_t countVowels = 0;
	char lastLetter = ' ';
	bool hasRepeatingLetters = false;
	bool hasBadLetterSequence = false;

	for (const char currentLetter : test) {
		if (currentLetter == lastLetter) {
			hasRepeatingLetters = true;
		}

		if (checkBadLetterSequence(lastLetter, currentLetter)) {
			hasBadLetterSequence = true;
		}

		switch (currentLetter) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				countVowels++;
		}

		lastLetter = currentLetter;
	}

	return isNiceString(countVowels, hasRepeatingLetters, hasBadLetterSequence);
}

uint32_t countNiceStrings(const string instructions) {
	uint32_t countNiceStrings = 0;

	auto instructionStream = istringstream(instructions); 
	string line = "";

	while (getline(instructionStream, line)) {
		if (isNiceString(line)) {
			countNiceStrings++;
		}
	}

	return countNiceStrings;
}

void main_five() {
	const string instructions = readInput("five.txt");

	cout << "Nice strings: " << countNiceStrings(instructions) << endl;
}
