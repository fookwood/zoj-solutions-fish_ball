// 1840131 2009-04-21 16:20:30 Accepted  2189 C++ 0 184 呆滞的慢板 

// 多重背包问题，与 2156 基本一样。但规模较少，直接用最原始的拆分即可。 

#include <iostream>
using namespace std;

int main() {
    int pre[501];
    double a;
    int A, B, C, D, E;
    while(cin >> a >> B >> C >> D >> E) {
        A = int(a * 100.0 + 0.0001);
        memset(pre, -1, sizeof(pre));
        pre[0] = 0;
        for(int i = 0; i < B; ++i)
            for(int j = A; j >= 0; --j)
                if(pre[j] != -1 && pre[j + 25] == -1)
                    pre[j + 25] = 25;
        for(int i = 0; i < C; ++i)
            for(int j = A; j >= 0; --j)
                if(pre[j] != -1 && pre[j + 10] == -1)
                    pre[j + 10] = 10;
        for(int i = 0; i < D; ++i)
            for(int j = A; j >= 0; --j)
                if(pre[j] != -1 && pre[j + 5] == -1)
                    pre[j + 5] = 5;
        for(int i = 0; i < E; ++i)
            for(int j = A; j >= 0; --j)
                if(pre[j] != -1 && pre[j + 1] == -1)
                    pre[j + 1] = 1;
        if(pre[A] == -1) {
            puts("NO EXACT CHANGE");
            continue;
        }
        B = C = D = E = 0;
        while(A != 0) {
            switch(pre[A]) {
                case 25: B++; break;
                case 10: C++; break;
                case 5: D++; break;
                case 1: E++; break;
            }
            A -= pre[A];
        }
        cout << B << " " << C << " " << D << " " << E << endl;
    }
}
