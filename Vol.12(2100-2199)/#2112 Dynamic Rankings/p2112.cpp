// 1706823 2008-11-22 17:32:12 Accepted  2112 C++ 8120 576 ´ôÖÍµÄÂı°å 

// ÂùÁ¦ 

#include <iostream>
#include <algorithm>
using namespace std;

int A[50000], B[50000], N, Q, T;
char C[2];

int main() {
    for(scanf("%d", &T); T--;) {
        scanf("%d%d", &N, &Q);
        for(int i = 0; i < N; ++i)
            scanf("%d", A + i);
        int x, y, k, v;
        while(Q--) {
            scanf("%s", C);
            if(*C == 'Q') {
                scanf("%d%d%d", &x, &y, &k);
                copy(A + x - 1, A + y, B);
                y -= x - 1;
                nth_element(B, B + k - 1, B + y);
                printf("%d\n", B[k-1]);
            }
            else {
                scanf("%d%d", &k, &v);
                A[k-1] = v;
            }
        }
    }
}
