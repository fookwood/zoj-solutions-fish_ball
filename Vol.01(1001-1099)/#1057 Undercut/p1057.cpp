// PERFORMER: ELF
// DATE: Dec. 10th, 2007
// TITLE: Undercut
#include <iostream>
using namespace std;

int main() {
    int     num, line = 0;
    int     A,  B,  a[20], b[20];
    while( ( cin >> num ) && num ) {
        if( line++ ) putchar( '\n' );
        A = B = 0;
        for( int i = 0; i < num; i++ ) cin >> a[i];
        for( int i = 0; i < num; i++ ) cin >> b[i];
        for( int i = 0; i < num; i++ ) {
            if( a[i] == b[i] + 1 )      B += ( a[i] + b[i] );
            else if( a[i] == b[i] - 1 ) A += ( a[i] + b[i] );
            else if( a[i] == b[i] + 1 ) B += ( a[i] + b[i] );
            else if( a[i] > b[i] )      A += a[i];
            else if( a[i] < b[i] )      B += b[i];
        }
        cout << "A has " << A << " points. "
             << "B has " << B << " points.\n"; 
    } 
}
