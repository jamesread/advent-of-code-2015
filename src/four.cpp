#include <openssl/md5.h>
#include <iostream>

#include "common.hpp"

using namespace std;


int main() {
	string input = "iwrupvqb";

	char toHash[] = "happy";

	unsigned char result[MD5_DIGEST_LENGTH];

	MD5(&toHash, strlen(toHash), (unsigned char*)&result);

	cout << "four" << endl;

	cout << result << endl;

	return 0;
}
