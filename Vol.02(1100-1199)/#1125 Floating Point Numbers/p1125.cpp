// 3008801 2008-07-27 14:56:02 Accepted 1125 C++ 00:00.00 848K 呆滞的慢板 

// printf( "%.6le" ); 会有问题！！要手动控制输出格式！！ 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    string  input;
    
    puts( "Program 6 by team X" );
    
    while( cin >> input ) {
        
        if( input.substr( 1 ) == "000000000000000" ) {
            puts( " 0.000000e+000" );
            continue;
        }
        
        int base = 0;
        for( int i = 1; i < 8; ++i ) {
            base <<= 1;
            if( input[i] == '1' )
                base += 1;
        }
        base -= 63;
        
        double  ans = 0.0;
        for( int i = 15; i >= 8; --i ) {
            if( input[i] == '1' )
                ans += 1.0;
            ans /= 2.0;
        }
        ans += 1.0;
        ans *= pow( 2.0, double( base ) );
        
        int exp = 0;
        while( ans < 1.0 ) { --exp; ans *= 10.0; }
        while( ans >= 10.0 ) { ++exp; ans /= 10.0; }

        putchar( input[0] == '1' ? '-' : ' ' );
        printf( "%.6lfe", ans );
        putchar( exp >= 0 ? '+' : '-' );
        printf( "%03d\n", abs( exp ) );

    }
    
    puts( "End of program 6 by team X" );
    
}
