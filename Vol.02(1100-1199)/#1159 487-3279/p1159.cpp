#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype> 
using namespace std;

int main() {
    int    T,    N,    sum;
    vector<int>    X;
    char    strin[200];
    const int code[] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5,
                         6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9 };
    scanf( "%d", &T );
    while( T-- ) {
        X.resize( 0 ); 
        scanf( "%d", &N );
        while( N-- ) {
            scanf( "%s", strin );
            sum = 0;
            for( int i = 0; strin[i]; i++ ) {
                if( strin[i] == '-' ) continue;
                sum *= 10;
                if( isdigit( strin[i] ) )
                    sum += int( strin[i] - '0' );
                else if( isupper( strin[i] ) )
                    sum += code[strin[i] - 'A'];
                else if( islower( strin[i] ) )
                    sum += code[strin[i] - 'a'];
            }
            X.push_back( sum ); 
        }
        sort( X.begin(), X.end() ); 
        X.push_back( -1 ); 
        bool    none = 1;
        int    count = 1;
        for( int i = 1; i < X.size(); i++ ) {
            if( X[i] == X[i - 1] )
                count++; 
            else if( count >= 2 ) {
                printf( "%03d-%04d %d\n", X[i - 1] / 10000, X[i - 1] % 10000, count );
                count = 1;
                none = 0; 
            } 
        }
        if( none ) printf( "No duplicates.\n" );
        if( T ) putchar( '\n' ); 
    }
} 
