// 2882906 2008-05-01 19:44:52 Accepted 2811 C++ 00:00.12 836K 呆滞的慢板 
// 求一组边(可以只取部分)能不能组成多边形
// 用 DP，一组边里面组合能形成等价为长度在区间 [low, high] 的边
// 加进去新的边，对区间只能扩大，不能缩小，直到 low <= 0 即可。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    double  low,    high;
    double  val[20];
    int     N;
    
    while( ( cin >> N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            cin >> val[i];
            
        sort( val, val + N );
        
        bool flag = false;
        low = high = *val;
        for( int i = 1; i < N; ++i ) {
            if( low - 1e-5 < val[i] &&
                val[i] < high + 1e-5 ) {
                flag = true;
                break;
            }
            low = min( low, val[i] - high );
            high = val[i] + high;
        }
        
        puts( flag ? "YES" : "NO" );
        
    }
    
}
