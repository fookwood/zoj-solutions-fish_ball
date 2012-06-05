// 1693069 2008-11-08 12:46:59 Accepted  2921 C++ 340 2900 呆滞的慢板 

// 股票买卖：经典的贪心，先记录所有档案，然后从尾到头遍历；
// 遍历之前创建一个优先队列 
// 存放当天之后剩余的价格 p 和剩余可卖出数为优先级的所有档案。
// 每遍历一天，加入当天价格和可卖出数到优先队列，然后将当天买入的股票卖完：
// 一直从优先队列中取档案，先取出来的肯定是最贵的，一直卖， 
// 直到队列为空或者当天买入的股票已经卖完。 

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int T, N, x[MAXN], p[MAXN], m[MAXN], ans, tmp;

int main() {
    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d%d%d", x+i, p+i, m+i);
        priority_queue<pair<int, int> > Q;
        pair<int, int> P;
        ans = 0;
        for(int i = N-1; i >= 0; --i) {
            Q.push(make_pair(p[i], m[i]));
            while(!Q.empty()) {
                P = Q.top();
                Q.pop();
                tmp = min(x[i], P.second);
                ans += P.first * tmp;
                P.second -= tmp;
                x[i] -= tmp;
                if(P.second > 0) Q.push(P);
                if(x[i] == 0) break;
            }
        }
        printf("%d\n", ans);
    }
}
