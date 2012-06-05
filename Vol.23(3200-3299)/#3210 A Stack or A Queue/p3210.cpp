// 1882483 2009-05-24 01:46:16 Accepted  3210 C++ 0 184 呆滞的慢板 

// 判断序列经过栈的处理还是经过队列的处理。
// 如果系列相同，则为队列，如互为回文，则为栈。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    for(cin >> T; T--;) {
        int N;
        cin >> N;
        vector<int> A(N), B(N), C(N);
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        for(int i = 0; i < N; ++i) {
            cin >> B[i];
            C[N-i-1] = B[i];
        }
        if(A == B) {
            if(A == C) puts("both");
            else puts("queue");
        }
        else if(A == C) puts("stack");
        else puts("neither");
    }
}
