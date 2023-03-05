// Short C++ project for school's c++ advanced features-course
// Mygrep CLI-program heavily inspired from the linux CLI grep-program

#include<iostream>
#include<string>
#include<fstream>
// headerfile
#include<C:\Users\Tito\Documents\GitHub\cpp-mygrep-project-2\mygrep.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ifstream;


int main(int argc, char **argv) {
    // string for option arguments
    string options;
    
    // conditions for number of arguments
    switch (argc) {
    // 1 argument as in only main is called
    case 1:
        // call function
        grepFromString();
        break;
    // 3 arguments as in main + 2
    case 3:
        // call function to search given string from specified file
        grepFromFile(argv[1], argv[2]);
        break;
    // 4 arguments
    case 4:
        // assign options from argument vector to string variable
        options = argv[1];
        // check what switches were given
        // if only o
        if (options == "-o")
        {
            // give error message
            cout << "No options were given...\n";
        }
        // if o and additional known options
        else if (options == "-ol" || options == "-oo" || options == "-olo")
        {
            // call function with options
            grepFromFile(options, argv[2], argv[3]);
        }
        // if options given were aren't known
        else
        {
            // give error message
            cout << "Unknown option(s)...\n";
        }
        break;
    // if given argument amount is "wrong"
    default:
        cout << "Unknown amount of arguments...\n";
        break;
    }
    return 0;
}
