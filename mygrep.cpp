// Short C++ project for school's c++ advanced features-course
// Mygrep CLI-program heavily inspired from the linux CLI grep-program

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

int main() {

    // data string is the variable that will be searched from
    string data_string, 
    // search string is the search "term"
    search_string, 
    // output message
    output_string;
    // holds position number
    int position;

    // user inputs
    cout << "Give a string from which to search for: ";
    getline(cin, data_string);
    cout << "Give search string: ";
    getline(cin, search_string);

    // add the position to variable
    position = data_string.find(search_string);
    // append the output message
    output_string = "\"" + search_string + "\" found in \"" + data_string + "\" in position " + to_string(position);
    // format and output the message
    cout << "\n\n" << output_string << "\n\n";
    
    return 0;
}