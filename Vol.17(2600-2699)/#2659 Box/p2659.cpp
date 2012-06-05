// 简单题，啥也不说了
// 2822738 2008-04-04 15:32:20 Accepted 2659 C++ 00:00.00 836K 呆滞的慢板  

#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle {
public:
    int x,  y;
    bool Set( const int& xx, const int& yy ) {
        x = ( xx < yy ) ? xx : yy;
        y = ( xx < yy ) ? yy : xx;
    }
    friend bool operator < ( const Rectangle& shape1,
                             const Rectangle& shape2 ) {
        return shape1.x < shape2.x ||
               shape1.x == shape2.x &&
               shape1.y < shape2.y;
    }
    bool operator != ( const Rectangle& shape )
        { return x != shape.x || y != shape.y; }
};

int main() {
    Rectangle   R[6];
    int     x,  y;
    while( cin >> x >> y ) {
        R[0].Set( x, y );
        for( int i = 1; i < 6; i++ ) {
            cin >> x >> y;
            R[i].Set( x, y );
        }
        sort( R, R + 6 );
        if( R[0] != R[1] || R[2] != R[3] || R[4] != R[5] ||
            R[0].x != R[2].x || R[0].y != R[4].x || R[2].y != R[4].y )
            cout << "IMPOSSIBLE" << endl;
        else
            cout << "POSSIBLE" << endl;
    }
}
