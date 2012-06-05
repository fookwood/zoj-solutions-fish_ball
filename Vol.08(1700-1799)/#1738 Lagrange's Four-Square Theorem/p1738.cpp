// 1663264 2008-10-11 10:33:10 Accepted  1738 C++ 90 1464 呆滞的慢板 

// 比较简单的 DP, DP[k][x] 表示 x 在累加 k 次之后有多少种选择，然后类似背包加入即可。 

#include <iostream>
using namespace std;

const int SZ = 2<<15;
int DP[5][SZ+1] = {}, N;

int main() {
    DP[0][0] = 1;
    for(int n = 1, m; (m=n*n) <= SZ; ++n)
        for(int k = 0; k < 4; ++k)
            for(int i = 0; i + m <= SZ; ++i)
                if(DP[k][i]) DP[k+1][i+m] += DP[k][i];
    while(cin >> N && N)
        cout << DP[1][N] + DP[2][N] + DP[3][N] + DP[4][N] << endl;
}
