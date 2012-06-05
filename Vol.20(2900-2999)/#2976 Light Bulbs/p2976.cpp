// 2923154 2008-05-19 18:35:14 Accepted 2976 C++ 00:00.01 848K 呆滞的慢板 

// Brute Force!!! 注意是求所有网格点的最大光强而不是原点的。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int     T,  N;
    
    double  x[100],  y[100],  z[100],  I[100];
    double  tot,    temp;
    double  X,  Y,  x1, x2, y1, y2, max_val;
    
    for( cin >> T; T--; ) {
        
        tot = 0.0;
        
        cin >> N;
        
        y1 = x1 = 1000.0;
        y2 = x2 = -1000.0;

        for( int i = 0; i < N; ++i ) {
            cin >> x[i] >> y[i] >> z[i] >> I[i];
            if( x1 > x[i] ) x1 = x[i];
            if( x2 < x[i] ) x2 = x[i];
            if( y1 > y[i] ) y1 = y[i];
            if( y2 < y[i] ) y2 = y[i];
        }
            
        max_val = 0.0;
        
        for( X = x1; X < x2 + 1e-5; X += 1.0 ) {
            
            for( Y = y1; Y < y2 + 1e-5; Y += 1.0 ) {
        
                tot = 0.0;
        
                for( int i = 0; i < N; ++i ) {
        
                    temp = ( x[i] - X ) * ( x[i] - X ) +
                           ( y[i] - Y ) * ( y[i] - Y ) + z[i]*z[i];
                       
                    tot += ( I[i] * z[i] * pow( temp, -1.5 ) );
                    
                }

                if( tot > max_val )
                    max_val = tot;
                    
            }
        
        }
        
        printf( "%.2lf\n", max_val );
        
    }
    
}
