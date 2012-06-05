// PERFORMER: ELF
// DATE: Dec. 20th, 2007
// TITLE: The Circumference of the Circle

// 2928049 2008-05-21 22:01:26 Accepted 1090 C++ 00:00.00 840K ´ôÖÍµÄÂý°å 

// Rrefactored on 2008-5-21

#include <iostream>
#include <cmath>
using namespace std;

const double PI = asin( 1.0 ) * 2.0;

inline double dis( const double& x1, const double& y1,
                   const double& x2, const double& y2 ) {
    return hypot( x1 - x2, y1 - y2 );
}

int main() {
    
    double  x1, x2, x3,
            y1, y2, y3,
            x,  y,  r;

    double  a1, b1, c1,
            a2, b2, c2;

    while( cin >> x1 >> y1
               >> x2 >> y2
               >> x3 >> y3 ) {
        // Eq.1: a1 * X + b1 * Y = c1
        a1 = x2 - x1;
        b1 = y2 - y1;
        c1 = ( y2 * y2 + x2 * x2 -
               y1 * y1 - x1 * x1 ) / 2.0;
    
        // Eq.2: a2 * X + b2 * Y = c2
        a2 = x3 - x1;
        b2 = y3 - y1;
        c2= ( y3 * y3 + x3 * x3 -
              y1 * y1 - x1 * x1 ) / 2.0;
    
        // Solve
        if( a1 == 0 ) {
            y = c1 / b1;
            x = ( c2 - b2 * y ) /a2;
        }
        
        else if( b1 == 0 ) {
            x = c1 / a1;
            y = ( c2 - a2 * x ) / b2;
        }
    
        else if( a2 == 0 ) {
            y = c2 / b2;
            x = ( c1 - b1 * y ) / a1;
        }
        
        else if( b2 == 0 ) {
            x = c2 / a2;
            y = ( c1 - a1 * x ) / b1;
        }
    
        else {
            y = ( c1 / a1 - c2 / a2 ) /
                ( b1 / a1 - b2 / a2 ); 
            x = c1 / a1 - b1 * y / a1;
        }
        
        cout.setf( ios::fixed );
        cout.precision( 2 );
        cout << 2.0 * PI * dis( x, y, x1, y1 ) << endl;
    }

}
