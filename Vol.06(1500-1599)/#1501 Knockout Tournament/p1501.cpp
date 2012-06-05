// 1665635 2008-10-13 22:15:47 Accepted  1501 C++ 0 248 呆滞的慢板 

// 擂台赛，传递闭包。首先转化为一个无权有向图： 
// 读取树，如果 i 赢了 j，增加一条边 G[i][j]； 
// 然后求传递闭包，那么顶点 i 的出度表示它必赢几个人
// 他的入度表示他必输几个人。然后最高排名为入度 +1，最低排名为总人数减出度。

#include <iostream>
using namespace std;

int N, NN, M, X;

int A[2<<8];
bool G[1<<8][1<<8];

int main() {
    int T = 0;
    while(cin >> N && N) {
        if(T++) puts("");
        NN = 1<<N;
        for(int i = NN-1; i > 0; --i)
            scanf("%d", A + i);
        for(int i = 0; i < NN; ++i)
            A[NN+i] = NN-i;
        memset(G, 0, sizeof(G));
        for(int i = 1; i < NN; ++i) {
            if(A[i<<1] == A[i])
                G[A[i<<1]-1][A[(i<<1)+1]-1] = true;
            else G[A[(i<<1)+1]-1][A[i<<1]-1] = true;
        }
        for(int i = 0; i < NN; ++i)
            for(int j = 0; j < NN; ++j)
                if(G[j][i])
                    for(int k = 0; k < NN; ++k)
                        G[j][k] |= G[i][k];        
        for(cin >> M; M--;) {
            cin >> X; X--;
            int win = 0, lose = 0;
            for(int i = 0; i < NN; ++i) {
                if(G[X][i]) ++win;
                if(G[i][X]) ++lose;
            }
            printf("Player %d can be ranked "
                "as high as %d or as low as %d.\n",
                X+1, 1+lose, NN-win);
        }
    }
    
}
