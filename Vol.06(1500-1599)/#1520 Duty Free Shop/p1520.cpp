// 1692615 2008-11-07 23:30:33 Accepted  1520 C++ 0 196 呆滞的慢板 

// 经典背包，记录路径，放得下就行。 

#include <iostream>
using namespace std;

int pre[1001], id[1001], cnt[1001], M, N, S, K, X;

void disp(int pos) {
    if(pos == 0) return;
    disp(pre[pos]);
    cout << ' ' << id[pos];
}

int main() {
    while(cin >> M >> N && (M || N)) {
        memset(pre, -1, sizeof(pre));
        pre[0] = S = cnt[0] = 0;
        cin >> K;
        for(int i = 1; i <= K; ++i) {
            cin >> X;
            S += X;
            for(int j = M - X; j >= 0; --j) {
                if(pre[j] != -1 && pre[j + X] == -1) {
                    pre[j + X] = j;
                    id[j + X] = i;
                    cnt[j + X] = cnt[j] + 1;
                }
            }
        }
        int pos = M;
        while(pre[pos] == -1) pos--;
        if(S - pos > N) {
            puts("Impossible to distribute");
            continue;
        }
        cout << cnt[pos];
        disp(pos);
        puts("");
    }
}
