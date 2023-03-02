// Short C++ project for school's c++ advanced features-course
// Mygrep CLI-program heavily inspired from the linux CLI grep-program

#include<iostream>
#include<string>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ifstream;

// function searches user input from user input
void grepFromString() {
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
    
    // if position is -1
    if (position == -1) {
        // then compose error message
        output_string = "\"" + search_string + "\" NOT found in \"" + data_string + "\"";
    } else {
        // compose the position message
        output_string = "\"" + search_string + "\" found in \"" + data_string + "\" in position " + to_string(position);
    }
    
    // format and output the message
    cout << "\n\n" << output_string << "\n\n";
}


// function searches user input from file
void grepFromFile(string search_string, string filename) {
    // search string is the search "term"
    // string for output message
    string output_string, line;
    int count = 0;

    // initialize input file variable
    ifstream data_file(filename, ifstream::in);

    // if file opened successfully
    if (data_file.is_open())
    {   
        // read first line from file
        getline(data_file, line);
        // loop to go through whole file
        while (data_file)
        {   
            // if read line contains user input
            if (line.find(search_string) != -1)
            {
                // print out the line
                cout << line << endl;
                count++;
            }
            // read the next line
            getline(data_file, line);
        }
    // if file opening failed
    } else
    {   
        // print out error message
        cout << "\nError opening the file...\n";
    }
    cout << "\n\n############################################################" << endl;
    cout << "\t\t\"" + search_string + "\" found in " << count << " lines" << endl;
    cout << "############################################################" << endl;
}


int main(int argc, char **argv) {

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
    default:
        break;
    }
    return 0;
}