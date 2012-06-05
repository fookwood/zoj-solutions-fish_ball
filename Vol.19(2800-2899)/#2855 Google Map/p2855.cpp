// 2904886 2008-05-10 20:49:53 Accepted 2855 C++ 00:00.61 848K 呆滞的慢板 

// 先坐标转换，然后不断 ZOOM 下去就行了，没什么难的 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    const double PI = asin( 1.0 ) * 2.0;
    double  x,  y,  X1, X2, Y1, Y2;
    int     L;
    string  str;
    
    while( cin >> x >> y >> L ) {

        x = x * PI / 180.0;
        y = log( tan( PI / 4.0 + y * PI / 360.0 ) );

        X1 = -PI;
        X2 = PI;
        Y1 = -log( tan( PI / 4.0 + 85 * PI / 360.0 ) );
        Y2 = log( tan( PI / 4.0 + 85 * PI / 360.0 ) );

        str = "t";
        
        for( int i = 0; i < L; ++i ) {
            double  XM = ( X1 + X2 ) / 2.0;
            double  YM = ( Y1 + Y2 ) / 2.0;
            if( x < XM && y < YM ) {
                str += 't';
                X2 = XM;
                Y2 = YM;
            }
            else if( x < XM && y > YM ) {
                str += 'q';
                X2 = XM;
                Y1 = YM;                
            }
            else if( x > XM && y < YM ) {
                str += 's';
                X1 = XM;
                Y2 = YM;  
            }
            else if( x > XM && y > YM ) {
                str += 'r';
                X1 = XM;
                Y1 = YM;
            }
            
        }
        
        cout << str << endl;
        
    }
    
}
