#include <regex>

#include "common.hpp"

using std::string;
using std::endl;
using namespace std;

void matchLine(smatch* match, string expression, string subject) {
	regex re(expression);

	regex_search(subject, *match, re);
}

const string readInput(string name) {
	ifstream in("input/" + name);
	string content;

	in.seekg(0, ios::end);
	content.reserve(in.tellg());
	in.seekg(0, ios::beg);

	content.assign(istreambuf_iterator<char>(in), istreambuf_iterator<char>());

	in.close();

	return content;
}

stringstream readInputStream(string name) {
	return stringstream(readInput(name));
}
