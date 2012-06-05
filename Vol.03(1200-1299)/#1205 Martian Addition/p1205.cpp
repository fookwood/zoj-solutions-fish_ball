// 3009954 2008-07-28 10:39:21 Accepted 1205 C++ 00:00.00 864K ´ôÖÍµÄÂı°å 

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


class Mar_num {
    string  s;
public:
    static int to_val( char c );
    static char to_code( int x );
    static const char* code;
    friend istream& operator >> ( istream&, Mar_num& );
    friend ostream& operator << ( ostream&, Mar_num );
    friend void sparse( Mar_num&, Mar_num& );
    friend Mar_num operator + ( Mar_num, Mar_num );
};

const char* Mar_num::code = "0123456789abcdefghij";

int Mar_num::to_val( char c ) {
    if( isalpha( c ) )  return  c - 'a' + 10;
    if( isdigit( c ) )  return  c - '0';
}

char Mar_num::to_code( int x ) { return  code[x]; }
    
istream& operator >> ( istream& is, Mar_num& n1 ) {
    is >> n1.s;
    reverse( n1.s.begin(), n1.s.end() );
    return  is;
}

ostream& operator << ( ostream& os, Mar_num n1 ) {
    reverse( n1.s.begin(), n1.s.end() );
    if( n1.s.length() == 0 )
        return  os << "0";
    return  os << n1.s;
}

void sparse( Mar_num& n1, Mar_num& n2 ) {
    while( n1.s.length() < n2.s.length() )  n1.s += '0';
    while( n1.s.length() > n2.s.length() )  n2.s += '0';
    n1.s += '0'; n2.s += '0';
}

Mar_num operator + ( Mar_num n1, Mar_num n2 ) {
    sparse( n1, n2 );
    int L = n1.s.length(),    C = 0;
    for( int i = 0; i < L; ++i ) {
        int x = Mar_num::to_val( n1.s[i] ) +
                Mar_num::to_val( n2.s[i] ) + C;
        C = x / 20;
        x %= 20;
        n1.s[i] = Mar_num::to_code( x );
    }
    n1.s.erase( n1.s.find_last_not_of( '0' ) + 1 );
    return  n1;
}

int main() {
    
    Mar_num n1, n2;
    while( cin >> n1 >> n2 )
        cout << n1 + n2 << endl;
    
}
