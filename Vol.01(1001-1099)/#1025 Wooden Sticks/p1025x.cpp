// 3022958 2008-08-05 16:13:53 Accepted 1025 C++ 00:00.16 880K 呆滞的慢板 

// 贪心，子序列删除算法的经典处理方式 

#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int>  P[5000];

int T,  N,  M,  C;

int main() {
    
    for( cin >> T; T--; ) {
        cin >> N;
        for( int i = 0; i < N; ++i )
            cin >> P[i].first >> P[i].second;
        sort( P, P + N );
        C = 0;
        while( N ) {
            for( int i = M = 0, now = P[0].second; i < N; ++i )
                if( P[i].second < now )
                        P[M++] = P[i];
                else    now = P[i].second;
            N = M;
            ++C;
        }
        cout << C << endl;
    }
    
}
