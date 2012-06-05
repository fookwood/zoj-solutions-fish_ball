// 1781651 2009-03-08 00:39:52 Accepted  2520 C++ 1040 184 呆滞的慢板 

// 定义一种数对(A, B)，其中 A 的因子(包括 1, 不包括它本身)之和等于 B，
// B 的因子之和等于 A。给出 K，求第 K 对这样的数对是什么。 
// 他 K 没给范围，其实很小，直接蛮力即可。 

#include <iostream>
using namespace std;

int isAmicable(int v) {
    int w = 1;
    for(int i = 2; i * i <= v; ++i) {
        if(v % i == 0) {
            w += i;
            if(i * i != v)
                w += v / i;
        }
    }
    if(w <= v) return -1;
    int u = 1;
    for(int i = 2; i * i <= w; ++i) {
        if(w % i == 0) {
            u += i;
            if(i * i != w)
                u += w / i;
        }
    }
    if(u == v) return w;
    else return -1;
}

int P[100], Q[100], N = 1, K;

int main() {
    P[0] = 220;
    Q[0] = 284;
    while(cin >> K) {
        for(int i = P[N - 1] + 1; K > N; ++i) {
            int j = isAmicable(i);
            if(j != -1) {
                P[N] = i;
                Q[N] = j;
                ++N;
            }
        }
        cout << P[K - 1] << ' ' << Q[K - 1] << endl;
    }
}
