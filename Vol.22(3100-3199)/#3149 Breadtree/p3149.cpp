// 1748355 2009-01-25 00:14:32 Accepted  3149 C++ 40 184 呆滞的慢板

// 面包树，经典题，用稍为巧妙的暴力变相模拟，设数组A[i]表示当前有i个儿子的节点数，
// 然后直接用这个模拟，刚开始的时候A[]={1,0,....}数组不长于K，
// 根据转移的性质，用一个双端队列来维护这个数组可以达到一个很好的效率。

#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, P, M, T;
    deque<int> Q;
    while(cin >> N >> K && N) {
        if(K == 0) {
            cout << min(N - 1, 1234567891) << endl;
            continue;
        }
        Q.assign(1, 1);
        P = 0;
        M = 1;
        for(int i = 1; i < N && P <= 1234567890; i++) {
            P += M;
            if(Q.size() <= K) {
                Q.push_front(M);
                M += M;
            }
            else {
                int t = Q.back();
                Q.pop_back();
                Q.back() += t;
                Q.push_front(M - t);
                M += M - t;
            }
        }
        cout << P << endl;
    }
}
