// 2060419 2009-12-17 17:22:30 Accepted  3280 C++ 810 1748 呆滞的慢板 
/*
Choose The Best
题目大意：给定N维空间的一些点，求加权曼哈顿距离最近的两个点的距离。
分析： 权值可以乘到点坐标上去，就是说可以把每个点每一维都乘上对应的w[t]。
考虑2维的情况 |x1-x2|+|y1-y2| 最大值只有4种情况：(x1+y1)-(x2+y2) , (-x1+y1)-(-x2+y2), (-x1-y1)-(-x2-y2), (x1-y1)-(x2-y2)，最大值是4种之一，这里面取最大就可以了。尽一步看到4种形式，每种自身第一个点和第二个点坐标间加正负号的方法是一样的。推广到N维，我们枚举加符号的方式，一共（1<<M）种，然后对每种方式，每个点的坐标按枚举的加括号的方式N维运算求出一个值来，取最大和最小值的差，作为可能结果，最后取所有差值中最大的即可。（注意M很小，只有8）复杂度O(2M*n)
*/


#include <iostream>
#include <algorithm>
using namespace std;

int x[50000][8], w[8];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", x[i] + j);
            }
        }
        for(int j = 0; j < m; ++j) {
            scanf("%d", w + j);
        }
        int ans = 0;
        for(int b = 0; b < (1<<m); ++b) {
            int mx = INT_MIN, mn = INT_MAX;
            for(int i = 0; i < n; ++i) {
                int val = 0;
                for(int j = 0; j < m; ++j) {
                    if((1<<j)&b) {
                        val += w[j] * x[i][j];
                    }
                    else {
                        val -= w[j] * x[i][j];
                    }
                }
                mx = max(val, mx);
                mn = min(val, mn);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << endl;
    }
}
