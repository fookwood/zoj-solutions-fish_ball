// 2955157 2008-06-23 10:31:11 Accepted 2488 C++ 00:00.01 848K 呆滞的慢板 

// 排序之后贪心，假设前 i - 1 根都断了，那么剩下重量取决于第 i 根
// 并且，加入剩下 ( n - i ) 根，那么当前的承重为 A[i] * ( n - i )
// 扫描一遍求出这个最大值即可

// 排序 O(nlogn)，贪心 O(n) 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int T,  N,  A[1000];
    
    for( cin >> T; T--; ) {
        cin >> N;
        for( int i = 0; i < N; ++i )
            cin >> A[i];
        sort( A, A + N );
        int mx = 0;
        for( int i = 0; i < N; ++i ) {
            int now = ( N - i ) * A[i];
            mx = max( mx, now );
        }
        cout << mx << endl;
    }
    
}
