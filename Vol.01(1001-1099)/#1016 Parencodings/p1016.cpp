// PERFORMER: ELF
// DATE: Dec. 11th, 2007
// TITLE: Parencodings

// 2900709 2008-05-09 12:11:19 Accepted 1016 C++ 00:00.00 836K ´ôÖÍµÄÂý°å 

// Refactored in May, 9th, 2008

#include <iostream>
#include <string>
using namespace std;

void p2str(int p[], int len, string &str) {
    
    str = "";
    
    for( int i = 0; i < len; i++ ) {
    
        for( int j = 0; j < p[i] - ( i ? p[i-1] : 0 ); j++ )
    
            str += '(';
    
        str+=')';
    
    }

}
void str2w( int w[], int len, string str ) {


    for( int i = 0, p = 0; i < len * 2; i++ ) {

        if( str[i] == ')' ) {

            for( int j = i - 1, sum = 1, n = 1; j >= 0; j--) {

                if( str[j] == ')' ) { sum++; n++; }

                if( str[j] == '(' ) sum--;

                if( !sum) { w[p++] = n; break; }

            }
        
        }

    }

}

int main() {
    
    int     num;
    int     p[20],  w[20],  len;
    
    cin >> num;
    
    string  str;
    
    while( num-- ) {
        
        cin >> len;
        
        for( int j = 0; j < len; j++ )
            cin >> p[j];
    
        p2str( p, len, str );
        str2w( w, len, str );
        
        for( int j = 0; j < len; j++ ) {
            cout << w[j];
            if( j < len - 1 ) 
                cout << " ";
        }
        cout << endl;
        
    }

}
