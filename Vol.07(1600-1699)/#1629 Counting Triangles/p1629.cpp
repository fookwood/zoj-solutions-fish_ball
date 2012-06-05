// 2886615 2008-05-03 14:46:43 Accepted 1629 C++ 00:00.01 840K 呆滞的慢板 

// DP，从下方新增一条边，DP[n] = DP[n-1] + ...
// ... 包括了边长为 k = 1..n 的三角形，这些三角形都要有一部分在新加上去的边上
// 先算正放的，有 n - k + 1 个
// 然后算倒放的，有 n - k - k + 1 (当且仅当 > 0)个，否则为 0 个 

#include <iostream>
using namespace std;

int main() {

    int DP[501] = { 0 },    N;
    
    for( int i = 1; i < 501; ++i ) {
        
        DP[i] = DP[i - 1];
        
        for( int j = 1; j <= i; ++j ) {
            
            DP[i] += ( i - j + 1 );
            
            if( i - j - j + 1 > 0 )
                DP[i] += ( i - j - j + 1 );
            
        }
        
    }
    
    while( cin >> N )
        cout << DP[N] << endl;

}
