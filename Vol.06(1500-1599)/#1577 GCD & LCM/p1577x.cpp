// 1653354 2008-10-01 21:40:54 Accepted  1577 C++ 0 260 呆滞的慢板 

// 知道 p，q 的最大公倍数和最小公约数，求 p 和 q 可能有多少种取值。
// 问题可转化：x = lcm/gcd，再求 x = m * n，m, n 互质的取值有多少种
// 假设 x 有 k 个不同的质因子，结果就是 2^k，注意，有可能 lcm 不能被 gcd 整除。

#include <cstdio>

int x, y;

int main() {
    while(scanf("%d%d", &x, &y) != EOF) {
        if(y % x != 0) {puts("0"); continue;}
        y /= x;
        x = 0;
        for(int i = 2; i * i <= y; ++i) {
            if(y % i == 0) {
                ++x;
                while(y % i == 0)
                    y /= i;
            }
        }
        if(y != 1) ++x;
        printf("%d\n", 1<<x);
    }
}
