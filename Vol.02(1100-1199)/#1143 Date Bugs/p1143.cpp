// 1652433 2008-09-30 22:15:28 Accepted  1143 C++ 0 460 呆滞的慢板 

// 读了好久才读明白了题目什么意思。
// 千年虫问题：旧式电脑在年份溢出之后会导致年份倒退一定数字;
// 第 i 类电脑(Ci)日期范围是 [ai, bi)，当前显示年份为 yi，落在此区间中;
// 每到第 bi 年自动跳回到 ai 年;
// 给出一组电脑，C[1..n]，给出 ai, bi, yi, 而他们实际日期是相同的;
// 求可能的最早的实际日期，如果没有，做相应输出，所有实际日期 <10000;

// 其实就是一个模线性方程组，但是由于数据范围很有限，可以用模拟 WS 过去。
// 就是每加入一台电脑，维护可能的真实年份，不断求交集筛选。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x, y;
int T = 1, N, a, b, c;

int main() {
    while(cin >> N && N) {
        x.clear();
        for(int i = 0; i < 10000; ++i)
            x.push_back(i);
        while(N--) {
            cin >> c >> a >> b;
            y.clear();
            while(c < 10000) {
                y.push_back(c);
                c += b - a;
            }
            x.resize(set_intersection(x.begin(), x.end(),
                y.begin(), y.end(), x.begin()) - x.begin());
        }
        printf("Case #%d:\n", T++);
        if(x.empty()) puts("Unknown bugs detected.\n");
        else printf("The actual year is %d.\n\n", x[0]);
    }
}

