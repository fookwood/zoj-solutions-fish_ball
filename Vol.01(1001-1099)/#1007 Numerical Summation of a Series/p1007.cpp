#include <cmath>
#include <cstdio>

int main() {
    for( double x = 0; x < 2.0001; x += .001 ) {
        double  psix = 0,   sum,    k;
        for( k = 1; k < 16000; k++ )
            psix += 1 / ( k * ( k + 1. ) * ( k + x ) );
        psix = 1. + ( 1 - x ) * ( psix + 1. / 2. / k / k ); 
        printf("%5.3f %16.12f\n", x, psix );  
    } 
//    getchar(); 
} 
