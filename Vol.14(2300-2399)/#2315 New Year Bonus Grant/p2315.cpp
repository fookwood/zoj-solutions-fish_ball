// 2060980 2009-12-18 13:33:30 Accepted  2315 C++ 380 8484 呆滞的慢板 

// 树状 DP，求最大树节点集，使得:
// 1. 根节点不在其内;
// 2. 父子节点不能同时选中; 
// 3. 兄弟节点不能同时选中; 
// 注意 Bill Hates 一定不能拿奖，不然就错了...

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define clr(x) memset(x, 0, sizeof(x))

int n, t;
int dp[2][500000];
int pre[500000];
int nxt[500000];
bool b[500000];

int main() {
    for(scanf("%d", &t); t--;) {
        scanf("%d", &n);
        clr(dp);
        clr(pre);
        clr(nxt);
        clr(b);
        for(int v = 1, w; v < n; ++v) {
            scanf("%d", &w);
            pre[v] = w - 1;
        }
        for(int v = n-1; v >= 0; --v) {
            dp[0][v] += dp[1][v];
            dp[1][v] += 1;
            if(v) {
                dp[1][pre[v]] += dp[0][v];
                if(dp[0][pre[v]] < dp[1][v] - dp[0][v]) {
                    dp[0][pre[v]] = dp[1][v] - dp[0][v];
                    nxt[pre[v]] = v;
                }
            }
        }
        
        printf("%d000\n", dp[0][0]);
        
        for(int i = 1, k = 0; i < n; ++i) {
            if(!b[pre[i]] && nxt[pre[i]] == i) {
                if(k++) putchar(' ');
                printf("%d", i + 1);
            }
        }
        puts("");
        
    }
}
