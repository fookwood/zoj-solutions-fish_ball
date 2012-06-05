// LIS 最长上升子序列，数据量很小，这是 O(n^2) 的算法 
// 2822894 2008-04-04 16:27:50 Accepted 2136 C++ 00:00.02 840K 呆滞的慢板 

#include <iostream>
using namespace std;

int main() {
    int     T,  N,  A[1001],    B[1001],    max;
    cin >> T;
    while( T-- ) {
        cin >> N;
        for( int i = 0; i < N; i++ )
            cin >> A[i];
        max = 0;
        for( int i = 0; i < N; i++ ) {
            int     m = 0;
            for( int j = 0; j < i; j++ )
                if( A[i] > A[j] && B[j] > m )  m = B[j];
            B[i] = m + 1;
            if( B[i] > max )
                max = B[i];
        }
        cout << max << endl;
        if( T ) cout << endl;
    }
}
