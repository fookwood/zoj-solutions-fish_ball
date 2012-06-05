// ×îÓÅ¶ş²æËÑË÷Ê÷ 

#include <iostream>
#include <algorithm>
using namespace std;

int N, DP[401][401], A[402] = {};

int main() {
    while(cin >> N) {
        N += N + 1;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &DP[i][i]);
            A[i+1] = A[i] + DP[i];
        }
        for(int d = 1; d < N; ++d) {
            for(int i = 0; i + d < N; ++i) {
                DP[i][i+d] = min(DP[]);
                for(int j = i; j <= i + d; ++j) {
                    
                }
                DP[i][i+d] += A[i+d+1] - A[i];
            }
        }
    }
}
