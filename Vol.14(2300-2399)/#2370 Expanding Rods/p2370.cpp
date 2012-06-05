// 3028560 2008-08-09 15:14:39 Accepted 2370 C++ 00:00.00 840K 呆滞的慢板 

// 画出几何图形可以得到如下公式

// 2 * R * sin( x ) = L
// 2 * R * x = L1
// 求 R * ( 1 - cos( x ) )

// 其中，x 是圆心角的一半，L 是弦长（受热前）
// L1 是弧长（受热后），R 是圆半径

// 其中，只给出了 L 和 L1
// 根据前两式，得到 sin( x ) * L1 = x * L
// 二份求得角度 x，余下的迎刃而解  

// 注意一些边界数据的情况，尤其是 L = 0 的时候 

#include <cmath>
#include <iostream>
using namespace std;

double  L,  L1, n,  C;

inline double fun( double x ) { return  sin( x ) - x * L; }

int main() {
    
    while( cin >> L >> n >> C && L >= 0.0 ) {
        
        if( L == 0.0 || n == 0.0 || C == 0.0 ) {
            puts( "0.000" );
            continue; 
        } 
        
        L1 = L * ( 1.0 + n * C );
        
        L /= L1; 
        
        double  mn = 0.0, mx = acos( -1.0 ) / 2.0;
        
        while( ( mx - mn ) / mx > 1e-12 ) {
            double  mid = ( mx + mn ) / 2.0;
            if( fun( mid ) > 0.0 )
                    mn = mid;
            else    mx = mid;
        }
        
        printf( "%.3lf\n", L1 / 2.0 / mx * ( 1.0 - cos( mx ) ) );
        
    }
    
}
