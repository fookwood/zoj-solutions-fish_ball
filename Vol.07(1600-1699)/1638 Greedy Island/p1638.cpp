#include <iostream>
using namespace std;

int G[100][3], M, A, B, C;

int main() {
    int T, M, N, A, B, C;
    for(cin >> T; T--;) {
        cin >> M >> A >> B >> C;
        N = A + B + C;
        for(int j = 0; j < M; ++j) {
            int a, b, c, i = 0;
            scanf("%d%d%d", &a, &b, &c);
            for(; i < A; ++i)
                MAT[i][j] = a;
            for(; i < A + B; ++i)
                MAT[i][j] = b;
            for(; i < A + B + C; ++i)
                MAT[i][j] = c;
        }
        cout << kuhn_munkras(N,M,MAT,m1,m2) << ' ';
        int ans = 0;
        for(int i = 0; i < M; ++i) {
            if(m2[i] != -1)
                ans += MAT[0][i] + MAT[A][i] + MAT[A+B][i];
        }
        cout << ans << endl;
    }
}
