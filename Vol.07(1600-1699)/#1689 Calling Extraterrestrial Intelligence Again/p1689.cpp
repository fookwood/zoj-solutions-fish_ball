// 3042877 2008-08-20 13:58:37 Accepted 1689 C++ 00:00.19 976K ´ôÖÍµÄÂý°å 

// ±©Á¦Ã¶¾Ù 

#include <iostream>
#include <algorithm>
using namespace std;

bool    isPrime[100001] = {};

int     Prime[9592],    top = 0;

int main() {
    
    for( int i = 2; i <= 100000; ++i ) {
        if( !isPrime[i] ) {
            if( i < 1000 )
                for( int j = i * i; j <= 100000; j += i )
                    isPrime[j] = true;
            Prime[top++] = i;
        }
    }
    
    int x,  y,  z;
    
    while( scanf( "%d%d%d", &x, &y, &z ) && x ) {
        
        int m,  n,  r = 1,  t = 1;
        
        for( m = 0; Prime[m] * Prime[m] <= x; ++m ) {
            for( n = m; Prime[m] * Prime[n] <= x; ++n ) {
                if( Prime[m] * z >= Prime[n] * y  &&
                    Prime[m] * Prime[n] > t * r ) {
                    r = Prime[m];
                    t = Prime[n];
                }
            }
        }
        
        printf( "%d %d\n", r, t );
        
    }
                
}
