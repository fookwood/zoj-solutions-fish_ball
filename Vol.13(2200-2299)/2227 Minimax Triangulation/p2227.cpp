#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
int DP[50][50];
int x[50], y[50];

int area(int i, int j, int k) {
    i %= N;    j %= N;    k %= N;
    return (x[i]-x[j]) * (y[i]-y[k]) - (x[i]-x[k]) * (y[i]-y[j]);
}

int main() {
    freopen("i.in", "r",stdin);
    freopen("s.txt", "w",stdout);
    
    for(cin >> T; T--;) {
        cin >> N;
        int tot = 0;
        for(int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
            if(i > 1) tot += area(0, i-1, i);
            DP[i][(i+1)%N] = 0;
        }
        for(int s = 2; s < N; ++s) {
            for(int j = 0; j < N; ++j) {
                DP[j][(j+s)%N] = INT_MAX;
                for(int k = 1; k < s; ++k) {
                    // 对于标程中此条件存在极大疑问！ 
                    if((tot<0) ^ (area(j, j + k, j + s)>=0)) {
                        DP[j][(j+s)%N] =
                            min(
                                DP[j][(j+s)%N],
                                max(
                                    abs(area(j, j + k, j + s)),
                                    max(
                                        DP[j][(j+k)%N],
                                        DP[(j+k)%N][(j+s)%N]
                                    )
                                )
                            );
                    }
                }
            }
        }
        printf("%.1lf\n", (double)DP[1][0] / 2);
    }
    
}
