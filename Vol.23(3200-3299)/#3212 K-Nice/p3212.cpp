// 1882485 2009-05-24 01:50:52 Accepted  3212 C++ 240 184 呆滞的慢板 

// 矩阵构造，使得恰好有 K 个内部单元的值等于其四周的值之和。
// 随便找 K 个内部单元格，将其本身及四周的单元格都涂成 0，其他的全涂成 1 即可。 

#include <iostream>
using namespace std;

bool B[15][15];
int N, M, K, T, C;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    for(cin >> T; T--;) {
        cin >> N >> M >> K;
        C = 0;
        memset(B, 0, sizeof(B));
        for(int i = 1; i + 1 < N && C < K; ++i) {
            for(int j = 1; j + 1 < M && C < K; ++j) {
                for(int d = 0; d < 4; ++d)
                    B[i+dx[d]][j+dy[d]] = true;
                B[i][j] = true;
                ++C;
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(j) putchar(' ');
                if(B[i][j]) putchar('0');
                else printf("1");
            }
            puts("");
        }                
    }
}
