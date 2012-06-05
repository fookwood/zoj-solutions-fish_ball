// 下面这个算法是按照枚举断开一条边，
// 然后变成一条运算链，然后用类似于矩阵连乘的方法来求解。
// 但是后来发现原来题目说有负节点的情况，于是 WA 了，正解不明 

#include <iostream>
#include <algorithm>
using namespace std;

int N;
char oper[50];
int num[50];

int chain[50];
char op[50];

int val[50][50];

inline int calc(int v, int w, char o) {
    return o == '+' ? v + w : v * w;
}

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i)
            cin >> oper[i] >> num[i];
        int ans = 0;
        for(int x = 0; x < N; ++x) {
            for(int y = 0; y < N; ++y) {
                chain[y] = num[(x + y) % N];
                op[y] = oper[(x + y) % N];
                val[0][y] = num[(x + y) % N];
            }
            for(int i = 1; i < N; ++i) {
                for(int j = 0; j + i < N; ++j) {
                    val[i][j] = 0;
                    for(int k = 0; k <= i; ++k) {
                        val[i][j] = max(
                            val[i][j],
                            calc(
                                val[k][j], 
                                val[i - k - 1][j + k + 1], 
                                op[j + k + 1]
                            )
                        );
                    }
                    ans = max(ans, val[i][j]);
                }
            }
        }
        cout << ans << endl;
        
    }
}
