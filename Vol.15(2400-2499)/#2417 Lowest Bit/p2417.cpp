#include <cstdio>
using namespace std;

int     main ()
{
        int     N;
        while( scanf( "%d", &N ) ) {
                if( !N ) break; 
                int     sum = 1; 
                do {
                        if( N % 2 ) {
                                printf( "%d\n", sum );
                                break; 
                        }
                        else
                                sum *= 2; 
                } while( N /= 2 );
        } 
} 
