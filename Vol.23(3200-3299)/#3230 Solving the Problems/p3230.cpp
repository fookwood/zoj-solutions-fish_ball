// 2073579 2010-01-09 23:23:34 Accepted  3230 C++ 170 1992 呆滞的慢板 

// 做题，每道题要求能力 ai，做完后能力增长 bi。
// 共 n 道题，原始能力 p，问做 m 道题之后能够达到最大的能力是多少？
// 先按题目的 <ai, bi> 从小到大排序，然后进入循环：
// 维护一个堆，里面存放一个整数，也就是还没做的，可做的题目的 b 值。 
// 每次循环，从剩余题目中抽取所有能做的题目，删掉，并将其 b 值入堆，
// 直到剩余的最容易做的题也不够能力做了。
// 然后从堆中取出最大的 b 值(如果有)，叠加到 p 上，并令 m 减一。
// 直到 m 为 0 或者堆已经为空。
// 最后的 p 值即为所求。 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
    
int n, m, p;
pair<int, int> V[100000];

int main() {
    while(scanf("%d%d%d", &n, &m, &p) == 3) {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &V[i].first, &V[i].second);
        sort(V, V + n);
        int top = 0;
        priority_queue<int> PQ;
        do {
            while(top < n && p >= V[top].first)
                PQ.push(V[top++].second);
            if(PQ.empty()) break;
            p += PQ.top();
            PQ.pop();
        } while(--m);
        printf("%d\n", p);
    }
} 
