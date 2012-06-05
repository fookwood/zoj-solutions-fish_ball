// 2894043 2008-05-06 20:01:47 Accepted 2124 C++ 00:00.00 400K 呆滞的慢板 

// 很变态，开方即可，注意输入的数可以是负数！！ 

#include <cstdio>
#include <cmath>

int main() {
    
    double  x,  y;
    bool    positive;
    
    while( scanf( "%lf", &x ) && x ) {
        
        if( positive = x > 0.0 )
                y = x;
        else    x = y = -x;
            
        for( y = floor( log( y ) / log( 2.0 ) ); y > 0.0; y -= 1.0 ) {

            double  temp = pow( x, 1.0 / y );
            
            if( fabs( temp - round( temp ) ) < 1e-5 ) {
                if( positive )  break;
                else if( int( y + 1e-5 ) % 2 )  break;
            }
            
        }
        
        printf( "%.0lf\n", y );
        
    }
    
}
