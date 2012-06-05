// 2907102 2008-05-11 19:33:07 Accepted 1325 C++ 00:00.00 848K ´ôÖÍµÄÂı°å 

// ¼òµ¥Ä£Äâ£¬Ãë 

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, char>  M;

int main() {
    
    M['A'] = 'A';   M['E'] = '3';   M['H'] = 'H';   M['I'] = 'I';
    M['J'] = 'L';   M['L'] = 'J';   M['M'] = 'M';   M['O'] = 'O';
    M['S'] = '2';   M['T'] = 'T';   M['U'] = 'U';   M['V'] = 'V';
    M['W'] = 'W';   M['X'] = 'X';   M['Y'] = 'Y';   M['Z'] = '5';
    M['1'] = '1';   M['2'] = 'S';   M['3'] = 'E';   M['5'] = 'Z';
    M['8'] = '8';
    
    string  input;
    bool    palindrome, mirror;
    
    while( cin >> input ) {
        
        palindrome = mirror = true;
        
        for( int i = 0; i < input.size() / 2; ++i ) {
            if( input[i] != input[input.size() - 1 - i] ) {
                palindrome = false;
                break;
            }
        }
        
        for( int i = 0; i <= input.size() / 2; ++i ) {
            if( M[input[i]] != input[input.size() - 1 - i] ) {
                mirror = false;
                break;
            }
        }
        
        if( mirror && palindrome )
            cout << input << " -- is a mirrored palindrome.\n\n";
        else if( mirror && !palindrome )
            cout << input << " -- is a mirrored string.\n\n";
        else if( !mirror && palindrome )
            cout << input << " -- is a regular palindrome.\n\n";
        else
            cout << input << " -- is not a palindrome.\n\n";
        
        
    }
    
    
}
