// 1931703 2009-07-18 23:44:56 Accepted  1493 C++ 10 184 呆滞的慢板 

// 音频压缩，直接模拟，注意输入输出可以用格式化 %x 的方式实现省代码。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while(scanf("%d", &N) != EOF) {
        printf("%d\n", N>>1);
        int sum = 0;
        for(int i = 0; i < N; i += 2) {
            int a, b;
            scanf("%x", &a);
            b = a - sum;
            b = max(b, -8);
            b = min(b, 7);
            printf("%01x", b&0xF);
            sum += b;
            
            scanf("%x", &a);
            b = a - sum;
            b = max(b, -8);
            b = min(b, 7);
            printf("%01x", b&0xF);
            sum += b;
            
            if(i % 16 < 14 && i != N - 2) putchar(' ');
            else putchar('\n');
        }
    }
}
