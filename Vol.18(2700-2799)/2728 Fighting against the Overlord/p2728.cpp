#include <deque>
#include <cstdio>
#include <cstring>
using std::deque;

typedef unsigned char Byte;

Byte* DP = new Byte[];

bool& dp( Byte S[15] ) {
}

inline Byte toValue( char* card ) {
    if( card[1] )   return  10;
    switch( *card ) {
        case 'F':;
        case 'L': return  0;
        case '2': return  1;
        case '3': return  2;
        case '4': return  3;
        case '5': return  4;
        case '6': return  5;
        case '7': return  6;
        case '8': return  7;
        case '9': return  8;
        case 'J': return  9;
        case 'Q': return  10;
        case 'K': return  11;
        case 'A': return  12;
    }
}

int main() {
}
