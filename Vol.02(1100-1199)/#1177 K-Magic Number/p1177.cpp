// 2150829 2010-04-10 11:12:00 Accepted  1177 C++ 10 184 呆滞的慢板 

// 很强的一道高精数论题，给 K，求最小的整数 X 使得十进制循环左移之后，
// 得到的 Y = X / K。
// 方法是枚举 Y 的个位，逐位(第k位)乘以 K 后得到 X 的第k位，于是得到
// Y 的第 k+1 位，以此类推可得整个数，枚举一次个位即可。 

#include <iostream>
using namespace std;

int main() {
    int T;
    char C[10][20000], D[10][20000];
    int K[10];
    for(cin >>T; T--;) {
        int N;
        cin >> N;
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));
        memset(K, 0, sizeof(K));
        for(int d = 1; d < 10; ++d) {
            C[d][0] = d;
            for(int i = 0; ; ++i) {
                int v = N * C[d][i];
                for(int j = 0; v; ++j) {
                    D[d][i+j] += v % 10;
                    v = v / 10 + D[d][i+j] / 10;
                    D[d][i+j] %= 10;
                    if(K[d] < i + j) {
                        K[d] = i + j;
                    }
                }
                if(K[d] == i && D[d][K[d]] == d) break;
                C[d][i+1] = D[d][i];
                if(i == 19999) {
                    K[d] = -1;
                    break;
                }
            }
        }
        int mv = INT_MAX, mp = 0;
        for(int d = 1; d < 10; ++d) {
            if(K[d] != -1 && K[d] < mv) {
                mv = K[d];
                mp = d;
            }
        }
        for(int i = K[mp]; i >= 0; --i) {
            putchar('0' + D[mp][i]);
        }
        puts("");
        if(T) puts("");
    }
}
