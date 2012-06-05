// 3013883 2008-07-30 14:56:57 Accepted 1901 C++ 00:00.00 848K 呆滞的慢板 

// 从重心开始迭代搜点 

#include <iostream>
#include <cmath>
using namespace std;

int     N;

int     X[100], Y[100];

double dist( double XX, double YY ) {
    double  tot = 0;
    for( int i = 0; i < N; ++i )
        tot += hypot( XX - X[i], YY - Y[i] );
    return  tot;
}

int main() {
    
    while( cin >> N ) {
        
        int XX = 0, YY = 0;
        
        for( int i = 0; i < N; ++i ) {
            cin >> X[i] >> Y[i];
            XX += X[i];
            YY += Y[i];
        }
        
        XX /= N;
        YY /= N;
        
        double  mx = dist( XX, YY );
        
        while( 1 ) {
            if( XX + 1 <= 10000 ) {
                double  now = dist( XX + 1, YY );
                if( now < mx ) {
                    mx = now;
                    ++XX;
                    continue;
                }
            }
            if( XX - 1 >= 0 ) {
                double  now = dist( XX - 1, YY );
                if( now < mx ) {
                    mx = now;
                    --XX;
                    continue;
                }
            }
            if( YY + 1 <= 10000 ) {
                double  now = dist( XX, YY + 1 );
                if( now < mx ) {
                    mx = now;
                    ++YY;
                    continue;
                }
            }
            if( YY - 1 >= 0 ) {
                double  now = dist( XX, YY - 1 );
                if( now < mx ) {
                    mx = now;
                    --YY;
                    continue;
                }
            }
            break;
        }
        
        cout << round( mx ) << endl;
        
    }
    
}
