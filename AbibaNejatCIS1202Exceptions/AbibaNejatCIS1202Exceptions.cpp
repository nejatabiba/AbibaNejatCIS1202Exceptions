// Nejat Abiba
// CIS 1202 800
// April 22, 2024


#include <iostream>

using namespace std;

char character(char start, int offset);

//Exception class declaration
class invalidCharacterException : exception {
    public:
        invalidCharacterException(char val) {
            value = val;
        }
        string getValue() {
            return "invalidCharacterException '" + string(1, value) +"'";
        }
    private:
        char value;
};

class invalidRangeException : exception {
    public:
        
        invalidRangeException(char start, char end) {
            fromValue = start;
            toValue = end;
        }
        string getValue() {
            return "invalidRangeException. Cannot convert '" + string(1, fromValue) + "' to '" + string(1,toValue) + "'";
        }
    private:
        char toValue;
        char fromValue;
};

int main()
{
    //Test character('a', 1);
    cout << "TEST #1" << endl;
    try {
        cout << character('a', 1) << endl;
    }
    catch (invalidCharacterException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    catch (invalidRangeException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    cout << endl;

    //Test character('a',-1)
    cout << "TEST #2" << endl;
    try {
        cout << character('a', -1) << endl;
    }
    catch (invalidCharacterException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    catch (invalidRangeException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    cout << endl;

    //Test character('Z',-1)
    cout << "TEST #3" << endl;
    try {
        cout << character('Z', -1) << endl;
    }
    catch (invalidCharacterException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    catch (invalidRangeException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    cout << endl;

    //Test character('?',5)
    cout << "TEST #4" << endl;
    try{
        cout << character('?', 5) << endl;
    }
    catch (invalidCharacterException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    catch (invalidRangeException e) {
        cout << "ERROR: " << e.getValue() << endl;
    }
    cout << endl;
    
}

char character(char start, int offset) {
    if(isalpha(start) == 0){
        throw invalidCharacterException(start);
    }
    if ( (islower(start) && isupper(start + offset)) || (isupper(start) && islower(start + offset)) || !isalpha(start + offset) ) {
        throw invalidRangeException(start ,start + offset);
    }
    return start + offset;
}

