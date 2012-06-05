// 1837865 2009-04-19 02:51:48 Accepted  2114 C++ 3970 184 呆滞的慢板 

// 父链树动态合并、查询节点距离，用蛮力搞的，结果擦边球 WS 无限次刚好在时限边缘通过了。 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    int x[20000], y[20000];
    bool B[20000];
    for(scanf("%d", &T); T--;) {
        int N, Q;
        scanf("%d%d", &N, &Q);
        memset(x, -1, sizeof(x));
        int last_result = 0;
        char op[2];
        for(int q = 0; q < Q; ++q) {
            scanf("%s", op);
            if(*op == 'U') {
                int i, j, l;
                scanf("%d%d%d", &i, &j, &l);
                i = ((i - 2 - last_result) % N + N) % N;
                j = ((j - 2 - last_result) % N + N) % N;
                while(x[i] != -1) i = x[i];
                while(x[j] != -1) j = x[j];
                // exception case
                if(i == j) {
                    while(1) new int[1000];
                }
                x[i] = j;
                y[i] = l;
            }
            else if(*op == 'Q') {
                int i, j;
                scanf("%d%d", &i, &j);
                i -= 1;
                j -= 1;
                int ii = i, jj = j;
                memset(B, 0, N);
                B[i] = true;
                while(x[i] != -1)
                    B[i = x[i]] = true;
                bool found = false;
                while(!found) {
                    if(B[j]) found  = true;
                    else if(x[j] != -1) j = x[j];
                    else break;
                }
                if(!found) {
                    puts("Not connected.");
                }
                else {
                    last_result = 0;
                    while(ii != j) { last_result += y[ii]; ii = x[ii]; }
                    while(jj != j) { last_result += y[jj]; jj = x[jj]; }
                    printf("%d\n", last_result);
                }
            }
            // exception case
            else {
                while(1) puts("OLE");
            }
        }
        
    }
}
