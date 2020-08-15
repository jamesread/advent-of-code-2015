#pragma once 

#include <fstream>
#include <streambuf>
#include <string>
#include <regex>

using std::string;

const string readInput(string name);

std::stringstream readInputStream(string name);

void matchLine(std::smatch* match, string expression, string subject);

