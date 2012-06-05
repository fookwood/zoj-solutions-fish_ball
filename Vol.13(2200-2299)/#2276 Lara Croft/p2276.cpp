// 2002994 2009-09-26 17:19:57 Accepted  2276 C++ 0 184 呆滞的慢板 

// 古墓丽影，很简单的环形线性广搜。只需要单独搜出两个方块到某个位置的最短路即可。 

#include <iostream>
#include <queue>
using namespace std;

int N, A[100];
    
void Search(int V[100], int pos) {
    queue<int> Q;
    V[pos] = 0;
    Q.push(pos);
    while(!Q.empty()) {
        int p = Q.front();
        Q.pop();
        int t = ((p - A[p]) % N + N) % N;
        if(V[t] == -1) {
            V[t] = V[p] + 1;
            Q.push(t);
        }
        t = (p + A[p]) % N;
        if(V[t] == -1) {
            V[t] = V[p] + 1;
            Q.push(t);
        }
    }
}

int main() {
    int X[100], Y[100], x, y;
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cin >> x >> y;
        memset(X, -1, sizeof(X));
        memset(Y, -1, sizeof(Y));
        Search(X, x);
        Search(Y, y);
        int pos = -1, val = INT_MAX;
        for(int f = 0; f < N; ++f) {
            if(X[f] != -1 && Y[f] != -1 && val > X[f] + Y[f]) {
                val = X[f] + Y[f];
                pos = f;
            }
        }
        if(pos == -1) {
            puts("Lara is traped!");
        }
        else {
            printf("open it on the %dth move!\n", val);
        }
    }
}
