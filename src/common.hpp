#pragma once 

#include <fstream>
#include <streambuf>
#include <string>
#include <regex>

using namespace std;

string readInput(string name) {
	ifstream in("input/" + name);
	string content;

	in.seekg(0, ios::end);
	content.reserve(in.tellg());
	in.seekg(0, ios::beg);

	content.assign(istreambuf_iterator<char>(in), istreambuf_iterator<char>());

	in.close();

	return content;
}

smatch matchLine(string expression, string subject) {
	regex re(expression);
	smatch match;

	regex_search(subject, match, re);

	return match;
}

