#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned long long xlong;

xlong A[20];
                    
xlong num[201];

void DFS( xlong m, int n ) {
    for( int i = 1; i <= 200; i++ ) {
        if( num[i] == 0ull && m % ( xlong )( i ) == 0ull )
            num[i] = m;
    }
    if( n < 20 ) {
        DFS( m, n + 1 );
        DFS( m + A[n], n + 1 );
    }
}

int main() {
    A[0] = 1ull;
    for( int i = 1; i < 20; i++ ) {
        A[i] = A[i - 1] * 10ull;
        cout << A[i] << endl;
    }
    ofstream    out( "out.txt" );
    for( int i = 0; i <= 200; i++ )
        num[i] = 0ull;
    DFS( 0ull, 0 );
    for( int i = 1; i <= 200; i++ )
        out << "    num[" << i << "] = \"" << num[i] << "\";" << endl;
    out.close();
}
