// 1682409 2008-10-29 23:26:42 Accepted  1877 C++ 20 196 呆滞的慢板 

// 最优方案只有两种策略，递推即可，用 DP 和贪心都是 O(N)，详见解题报告 

#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1000];

int DP[1001], PR[1001];

int main() {
    
    while(cin >> N) {
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        sort(A, A+N);
        DP[0] = 0;
        DP[1] = A[0];
        DP[2] = A[1];
        DP[3] = A[0] + A[1] + A[2];
        for(int k = 4; k <= N; ++k) {
            DP[k] = DP[k-1] + A[0] + A[k-1];
            PR[k] = 1;
            if(DP[k] > DP[k-2] + A[0] + 2*A[1] + A[k-1]) {
                DP[k] = DP[k-2] + A[0] + 2*A[1] + A[k-1];
                PR[k] = 2;
            }
        }
        cout << DP[N] << endl;
        while(N > 3) {
            if(PR[N] == 1) {
                cout << A[0] << ' ' << A[N-1] << endl;
                cout << A[0] << endl;
            }
            else {
                cout << A[0] << ' ' << A[1] << endl;
                cout << A[1] << endl;
                cout << A[N-2] << ' ' << A[N-1] << endl;
                cout << A[0] << endl;
            }
            N -= PR[N];
        }
        if(N == 3) {
            cout << A[0] << ' ' << A[2] << endl;
            cout << A[0] << endl;
            cout << A[0] << ' ' << A[1] << endl;
        }
        else if(N == 2) {
            cout << A[0] << ' ' << A[1] << endl;
        }
        else {
            cout << A[0] << endl;
        }
    }
    
}
