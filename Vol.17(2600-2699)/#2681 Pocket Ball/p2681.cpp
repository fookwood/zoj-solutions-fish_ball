// 简单：先约分，然后求直线与网格的所有交点
// 根据交点所在的线段求出它的名字，然后排序输出
// 2822577 2008-04-04 14:10:32 Accepted 2681 C++ 00:01.28 856K 呆滞的慢板 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Intersect {
    double  x,  y;
    char    type;
public:
    Intersect() {}
    Intersect( double x, double y, char type ) :
        x(x), y(y), type(type) {}
    friend bool operator < ( const Intersect& i1, const Intersect& i2 )
        { return    i1.x < i2.x; }
    void disp() { cout << type << ' '; }
};

int main() {
    int     T,  x,  y;
    cin >> T;
    vector<Intersect>   V;
    while( T-- ) {
        cin >> x >> y;
        int m = ( x > y ) ? x : y;
        int n = ( x > y ) ? y : x;
        while( n ) {
            int r = m % n;
            m = n;
            n = r;
        }
        x /= m;
        y /= m;
        V.resize( 0 );
        for( int i = 1; i < x; i++ )
            V.push_back( Intersect( double( i * y ) / double( x ), double( i ),
                    ( i & 1 ) ? 'N' : 'S' ) );
        for( int j = 1; j < y; j++ )
            V.push_back( Intersect( double( j ), double( j * x ) / double( y ),
                    ( j & 1 ) ? 'E' : 'W' ) );
        sort( V.begin(), V.end() );
        cout << V.size() << endl;
        for( int i = 0; i < V.size(); i++ )
            V[i].disp();
        // 若 x 偶 y 偶，则入 1 号袋 
        if( !( x & 1 ) && !( y & 1 ) )
            cout << 1 << endl;
        // 若 x 偶 y 奇，则入 2 号袋 
        if( !( x & 1 ) &&  ( y & 1 ) )
            cout << 2 << endl;
        // 若 x 奇 y 奇，则入 3 号袋
        if(  ( x & 1 ) &&  ( y & 1 ) )
            cout << 3 << endl;
        // 若 x 奇 y 偶，则入 4 号袋
        if(  ( x & 1 ) && !( y & 1 ) )
            cout << 4 << endl;
    }
}
