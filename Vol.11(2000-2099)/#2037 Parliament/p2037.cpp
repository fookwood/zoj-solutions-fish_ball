// 问题是求一个整数的最优拆分，使其拆分后的乘积最大 
// 贪心：若 N <= 4，直接输出
// 否则，先从 2 开始填，例如 31 = 2 + 3 + 4 + 5 + 6 + 7 ... 4
// 然后将剩余的逐一添到靠后面的数字里面去
// 31 = 2 + 3 + 5 + 6 + 7 + 8
// 但是有这种情况：
// 34 = 2 + 3 + 4 + 5 + 6 + 7 ... 7，填充 
// 34 = 3 + 4 + 5 + 6 + 7 + 8 ... 1，还剩余 1 
// 这种情况不能漏掉，加到最后一个数上去
// 34 = 3 + 4 + 5 + 6 + 7 + 9
// 2830932 2008-04-08 14:47:59 Accepted 2037 C++ 00:00.00 840K 呆滞的慢板 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int     N,  T;
    cin >> T;
    while( T-- ) {
        cin >> N;
        if( N < 5 ) {
            cout << N << endl;
            continue;
        }
        vector<int> V( 1, 2 );
        N -= 2;
        while( N > V.back() ) {
            V.push_back( V.back() + 1 );
            N -= V.back();
        }
        int     pos = V.size() - 1;
        while( N ) {
            N--;
            V[pos--]++;
            if( pos < 0 )
                break;
        }
        if( N ) V.back()++;
        cout << V[0];
        for( int i = 1; i < V.size(); i++ )
            cout << ' ' << V[i];
        cout << endl;
        if( T )   cout << endl;
    }
}
