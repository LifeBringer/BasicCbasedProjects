#include <string>
#include <iostream>
#include <fstream>// include this directive for all file input/output processing

using namespace std;

int main() 
{
    string filename, word, wordInDict;
    ifstream dictionary, bonk;
    bool found;
    int c;

    cout << "Enter the name of the file to spell check: ";
      cin >> filename; // prompt the user for a filename

    // open files for reading
     dictionary.open("dictionary.txt");
    if (dictionary.fail()) 
	{
        cout << "Error opening dictionary file"; // check to see if there are any failures when attempting to open the file (fail() returns boolean True or False)
        exit(1); // terminate the program
    }
    bonk.open(filename.c_str()); 
    if (bonk.fail())
	{
        cout << "Error opening the file"; // check to see if there are any failures when attempting to open the file (fail() returns boolean True or False)
        exit(1); // terminate the program
    }

   
    while (!bonk.eof()) // spell check until end of file
	{
      
        bonk >> word;  // read a word

       
        c = word.find("(");  // remove all punctuation
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find(")");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find(",");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find(".");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find(":");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find("?");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find(";");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find("!");
        if (c >= 0)
            word.replace(c, 1, "");
        c = word.find("\"");
        while (c >= 0) {
            word.replace(c, 1, "");
            c = word.find("\"");
        }

        // ignore numbers
        if (word.find_first_not_of("0123456789") > 0)
            continue;
        else {
            // search in dictionary
            found = false;
            while (!dictionary.eof() && !found) {
                dictionary >> wordInDict;
                if (stricmp(word.c_str(), wordInDict.c_str()) == 0) {
                    found = true;
                }
            }
            // rewind dictionary file
            dictionary.clear();
            dictionary.seekg(0, dictionary.beg);
            if (!found)
                cout << word << endl;
        }
    }

    // close files
    dictionary.close();
    bonk.close();

	system("pause");
    return 0;
}

