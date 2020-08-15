#include <openssl/md5.h>
#include <iostream>

#include "common.hpp"

using std::string;
using std::cout;
using std::endl;
using std::to_string;

const string md5hash(const string toHash) {
	unsigned char result[MD5_DIGEST_LENGTH];

	MD5((const unsigned char*) toHash.c_str(), toHash.length(), (unsigned char*)&result);

	char mdString[33];

	for (int i = 0; i < 16; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)result[i]);
	}

	return mdString;
}

int main() {
	const int zeroLength = 6;
	const string zeros = string(zeroLength, '0');
	const string input = "iwrupvqb";
	string digest, toHash; 

	for (int i = 0; ; i++) {
		toHash = input + to_string(i);

		digest = md5hash(toHash);

		if (digest.substr(0, zeroLength) == zeros) {
			cout << toHash << " = " << digest << endl;
			break;
		}
	}

	return 0;
}
