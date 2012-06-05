// 2812291 2008-03-30 20:47:28 Accepted 2947 C++ 00:00.00 840K ´ôÖÍµÄÂý°å 
#include <iostream>
#include <string>
using namespace std;

int main() {
    int     T,  N,  M;
    string  str,p1, p2;
    cin >> T;
    while( T-- ) {
        p1 = "";
        p2 = "";
        cin >> N;
        while( N-- ) {
            cin >> str;
            p1 += str[0];
        }
        cin >> M;
        while( M-- ) {
            cin >> str;
            p2 += str[0];
        }
        if( p1 == p2 )
            puts( "SAME" );
        else
            puts( "DIFFERENT" );
    }
}
