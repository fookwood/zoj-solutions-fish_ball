// 1655837 2008-10-04 10:47:24 Accepted  2536 C++ 910 29480 ´ôÖÍµÄÂý°å 

// ±³°ü + Ì°ÐÄ 

#include <iostream>
#include <algorithm>
using namespace std;

bool B[30000000];
int M, N, K, T;

int main() {
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        if(t > 1) puts("");
        printf("Case %d:\n", t);
        cin >> N >> K;
        memset(B, 0, sizeof(B));
        B[M = 0] = true;
        while(N--) {
            int x; cin >> x;
            for(int i = M; i >= 0; --i) {
                if(B[i]) {
                    B[i+x] = true;
                    M = max(M, i+x);
                }
            }
        }
        while(K--) {
            int x = 0;
            while(B[x]) ++x;
            for(int i = M; i >= 0; --i) {
                if(B[i]) {
                    B[i+x] = true;
                    M = max(M, i+x);
                }
            }
        }
        int x = 0;
        while(B[x]) ++x;
        cout << x << endl;
    }
}
