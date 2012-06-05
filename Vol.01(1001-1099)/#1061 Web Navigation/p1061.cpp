// NEW EDITION
// ELF
// 2008-1-4

#include <iostream>
#include <vector>
#include <string> 
using namespace std; 

int main() {
    vector<string> backward, forward;
    string input, current( "http://www.acm.org/" );
    int     n;
    cin >> n;
    while( n-- ) { 
        while( cin >> input ) {
            if( input == "QUIT" ) {
                if( n > 1 ) cout << endl;
                break;
            }
            else if( input == "VISIT" ) {
                forward.clear();
                backward.push_back( current );
                cin >> current;
                cout << current << endl; 
            }
            else if( input == "BACK" ) {
                if( !backward.size() )
                    cout << "Ignored" << endl;
                else {
                    forward.push_back( current );
                    current = backward.back();
                    backward.pop_back();
                    cout << current << endl; 
                }
            }
            else if( input == "FORWARD" ) {
                if( !forward.size() )
                    cout << "Ignored" << endl;
                else {
                    backward.push_back( current );
                    current = forward.back();
                    forward.pop_back(); 
                    cout << current << endl; 
                }
            }
        }
        forward.clear();
        backward.clear();
        current = "http://www.acm.org/";
    }
} 
