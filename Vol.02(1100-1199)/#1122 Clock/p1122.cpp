// 1659127 2008-10-06 22:37:06 Accepted  1122 C++ 0 184 呆滞的慢板 

// 模拟，角度的单位是 1，每一个分钟格子有 12 个单位，一个圆周有 60*12 个单位 
// 也就是每分钟分针走 12 个单位，时针走 1 个单位，相对速度分针追赶 11 个单位
// 计算出 t2-t1 有多少分钟 t，以及开始时分针超前的角度 a(初始位移)
// 追赶速度 11，结束时相对位移 t*11+a，因此追赶了 (t*11+a)/(12*60) 次 

#include <iostream>
using namespace std;

int main() {
    puts("Program 3 by team X");
    puts("Initial time  Final time  Passes");
    int h1, m1, h2, m2, t1, t2, a, t;
    while(cin >> h1 >> m1 >> h2 >> m2) {
        t1 = m1 + h1 * 60;
        t2 = m2 + h2 * 60;
        t = t2 - t1;
        if(t < 0) t += 12 * 60;
        a = m1 * 12 - h1 * 5 * 12 - m1;
        if(a < 0) a += 12 * 60;
        printf("       %02d:%02d", h1, m1);
        printf("       %02d:%02d", h2, m2);
        printf("%8d\n", (t * 11 + a) / (12 * 60));
    }
    puts("End of program 3 by team X");
}
