#include "GenStack.h"


int countdelims(string fileName) {

    GenStack<char> delims(20); //this is starting size, will expand to meet file needs

    string line;
    char next_char;
    ifstream inFile;

    inFile.open(fileName.c_str());

    int lineLoc = 1;
    int line_length = 0 ;
    string error_str  ;

    if(inFile.is_open()) {
        while (getline(inFile, line)) {
            line_length = line.length();
            for (int i = 0; i < line_length; ++i) {
                next_char = line[i];
                switch(next_char) {
                    //adding opening delimiters to stack
                    case('('):
                        delims.push(next_char);
                        break;
                    case('{'):
                        delims.push(next_char);
                        break;
                    case('['):
                        delims.push(next_char);
                        break;
                    //popping matching delimiters off stack if not matching
                    //returns -1 if error with delimiters
                    case(')'):
                        if(delims.isEmpty()) {
                            cout << "Missing ( on or above line " << lineLoc << endl;
                            //throw error
                            return -1;
                        } else if(delims.peek() != '(') {
                            cout << "Wrong delimiter ) on line " << lineLoc << endl;
                            //throw error
                            return -1;
                        }
                        delims.pop();
                        break;
                    case('}'):
                        if(delims.isEmpty()) {
                            cout << "Missing { on or above line " << lineLoc << endl;
                            //throw error
                            return -1;
                        } else if(delims.peek() != '{') {
                            cout << "Wrong delimiter } on line " << lineLoc << endl;
                            //throw error
                            return -1;
                        }
                        delims.pop();
                        break;
                    case(']'):
                        if(delims.isEmpty()) {
                            cout << "Missing [ on or above line " << lineLoc << endl;
                            //throw error
                            return -1;
                        } else if(delims.peek() != '[') {
                            cout << "Wrong delimiter ] on line " << lineLoc << endl;
                            //throw error
                            return -1;
                        }
                        delims.pop();
                        break;
                    default:
                        break;
                }
            }
            ++lineLoc;
        }

        //end of file check for missing closing delimiters
        if(!delims.isEmpty()) {
            cout << "Reached end of file. Missing closing for " << delims.pop() << endl;
            //throw error
            return -1;
        }

        inFile.close();
        return 0;

    } else {
        cout << "Unable to open file. " << endl;
        return -1;
    }
}


int main(int argc, char** argv) {

    string file = argv[1];
    string in_option ;


    do {
         if(countdelims(file) == 0 ) {
            cout << endl << "Successfully processed the file " << file << endl;

            cout << "Would you like to provide another input file (y/n): ";
            cin >> in_option ;

            if (in_option[0] == 'y' ) {
              cout << "\nPlease provide a filename : " ;
              cin >> file ;

            }
            
        } else {
            return -1;
        }

    } while (in_option[0] == 'y');


     return 0 ;
}
