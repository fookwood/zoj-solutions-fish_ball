#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int SZ[10] = { 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000 };

void print( string s ) { puts( s.c_str() ); }

string rnd( string s ) {
    int x = rand() % 3;
    for( int i = 0; i < x; ++i ) {
        int y = rand() % 7;
        ++s[y];
        if( s[y] > 'z' )
            s[y] = 'a';
    }
    return s; 
}

int main() {
    
    freopen( "test.txt", "w", stdout );
    
    string  s( "aaaaaaa" );
    
    for( int i = 0; i < 10; ++i ) {
        
        printf( "%d\n", SZ[i] );
        
        set<string> S;
        while( S.size() < SZ[i] )
            S.insert( s = rnd( s ) );
        
        for_each( S.begin(), S.end(), print );
        
    }
    
    puts( "0" );
    
}
