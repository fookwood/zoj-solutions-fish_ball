// 2924573 2008-05-20 15:27:56 Accepted 2956 C++ 00:00.11 876K 呆滞的慢板 

// 比较暴力的填格方法可以过，x 坐标没用，见 cpg 的报告:

// 比较水 建立一个 ymin - ymax 的数组
// 读入一个区间在 y1 - y2 间所有的点都加 1
// 最后找到最大的次数就可以了

#include <iostream>
using namespace std;

int cnt[10001], x, y, tot;

int main() {
    
    int     T,  N;
    for( cin >> T; T--; ) {
        memset( cnt, 0, sizeof( cnt ) );
        for( cin >> N; N--; ) {
            cin >> x >> x >> y;
            for( int i = x; i <= y; ++i )
                ++cnt[i];
        }
        tot = 0;
        for( int i = 0; i <= 10000; ++i )
            tot = tot > cnt[i] ? tot : cnt[i];
        cout << tot << endl;
    }
    
}
