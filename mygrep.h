// mygrep.h header-file
#pragma once
#include <string>

// function prototypes

void grepFromString();
void grepFromFile(std::string search_string, std::string filename);
void grepFromFile(std::string options, std::string search_string, std::string filename);
