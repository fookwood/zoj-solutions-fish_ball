// 2865982 2008-04-24 14:07:00 Accepted 2229 C++ 00:00.00 396K 呆滞的慢板  
// 贪心，O(n) 
// 1. 开始时间 < 0 的，不予考虑，太快的赶不上，太慢的赶上也没用
// 2. 开始时间 > 0 的，Charley 和最早到达的车子一起到达 

#include <cstdio>
#include <cmath>

int main() {
    int T,  x,  y;
    double  min, temp;
    while( scanf( "%d", &T ) && T ) {
        min = 1e99;
        for( int i = 0; i < T; i++ ) {
            scanf( "%d%d", &x, &y );
            if( y >= 0 ) {
                temp = 4500.0 * 3.6 / x + y;
                if( temp < min )
                    min = temp;
            }
        }
        printf( "%.0lf\n", ceil( min ) );
    }
}
