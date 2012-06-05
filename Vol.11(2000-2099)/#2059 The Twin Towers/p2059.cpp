// 1832055 2009-04-13 13:19:41 Accepted  2059 C++ 120 184 呆滞的慢板 

// 双塔，超经典 DP，每加入一个高度，更新双塔高度差为 i 时较低塔高度的最大值 DP[i]。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int DP[2001], TMP[2001];
    int N;
    while(cin >> N && N != -1) {
        memset(DP, -1, sizeof(DP));
        DP[0] = 0;
        while(N--) {
            int x;
            cin >> x;
            memcpy(TMP, DP, sizeof(DP));
            for(int i = 2000; i >= 0; --i) {
                if(DP[i] != -1) {
                    TMP[i + x] = max(DP[i], TMP[i + x]);
                    if(x < i)
                        TMP[i - x] = max(DP[i] + x, TMP[i - x]);
                    else if(x >= i)
                        TMP[x - i] = max(i + DP[i], TMP[x - i]);
                }
            }
            memcpy(DP, TMP, sizeof(DP));
        }
        if(DP[0] != 0) cout << DP[0] << endl;
        else puts("Sorry");
    }
}
