// 1896202 2009-06-13 11:46:29 Accepted  2339 C++ 600 6336 呆滞的慢板 

// 求 huffman 编码的最短编码后文本长度。
// 思路是模拟 huffman 树的构造，但是并不需要完全构造。
// 用一个优先队列，放进去个字符频数。
// 每次取出最小的两个，总结果累加它们的长度之和。
// 然后将它们之和放入优先队列，直到队列中只剩一个。
// 总复杂度 O(NlogN)。 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long i64;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        priority_queue<i64> Q;
        for(int i = 0, p; i < N; ++i) {
            scanf("%d", &p);
            Q.push(-p);
        }
        i64 ans = 0;
        while(Q.size() > 1) {
            i64 p1 = Q.top(); Q.pop();
            i64 p2 = Q.top(); Q.pop();
            ans -= p1 + p2;
            Q.push(p1 + p2);
        }
        cout << ans << endl;
        Q.pop();
        if(T) puts("");
    }
}
