// 1863815 2009-05-11 00:19:15 Accepted  3191 C++ 0 184 呆滞的慢板 

// 根据时针的角度判断时钟所指的时间段，简单的角度转换即可解决。 

#include <iostream>
using namespace std;

int main() {
    int N;
    while(cin >> N && N != -1) {
        N = (450 - N) % 360;
        if(N % 30 == 0)
            printf("Exactly %d o'clock\n", N / 30);
        else {
            printf("Between %d o'clock and %d o'clock\n", N / 30, (N / 30 + 1) % 12);
        }
    }
}
