// 1740568 2009-01-10 13:26:24 Accepted  3123 C++ 130 576 呆滞的慢板 
// 求和，枚举，二分 

#include <iostream>
#include <algorithm>
using namespace std;

int A[100001], N, S, T;

int main() {
    for(cin >> T; T--;) {
        cin >> N >> S;
        A[0] = 0;
        A[N + 1] = INT_MAX;
        for(int i = 0; i < N; ++i) {
            cin >> A[i + 1];
            A[i + 1] += A[i];
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int* pos = lower_bound(A + i, A + N + 2, A[i] + S);
            if(pos == A + N + 1) continue;
            int now = pos - (A + i);
            if(ans == 0 || ans > now)
                ans = now;
        }
        cout << ans << endl;
    }
    return EXIT_SUCCESS;
}
