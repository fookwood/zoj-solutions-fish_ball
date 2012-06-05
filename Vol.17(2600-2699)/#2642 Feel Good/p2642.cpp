// 1795834 2009-03-21 01:28:45 Accepted  2642 C++ 510 4076 呆滞的慢板 

// 堆栈贪心法，给一个数组 A[N]，对于区间 i, j 之间，
// 函数 f(i, j) = SUM(A[i..j]) * MIN(A[i..j])，
// 求 MAX(f(i, j)), 0 <= i <= j < N。
// 首先，对数组求和预处理，于是可以 O(1) 得到区间的求和。
// 然后，用堆栈贪心法：
// 求出第 i 个元素左边第一个比它小的下标 L[i]，
// 和右边第一个逼它大的下标 R[i]。
// 预处理 O(N)，现在可以求出最小值是 A[i] 时的最宽区间即为 L[i]+1..R[i]-1
// 然后枚举 i，求最大的 A[i] * SUM(A[L[i]+1..R[i]-1])，O(N) 可以处理完毕。 

#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;

int N;

vector<int> A, L, R;

vector<i64> S;

vector<pair<int, int> > stk;

int main() {
    
    while(cin >> N) {
        A.resize(N);
        S.assign(N + 1, 0);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
            S[i + 1] = S[i] + A[i];
        }
        
        R.assign(N, N);
        stk.clear();
        for(int i = 0; i < N; ++i) {
            while(!stk.empty() && stk.back().first > A[i]) {
                R[stk.back().second] = i;
                stk.pop_back();
            }
            stk.push_back(make_pair(A[i], i));
        }
        L.assign(N, -1);
        stk.clear();
        for(int i = N - 1; i >= 0; --i) {
            while(!stk.empty() && stk.back().first > A[i]) {
                L[stk.back().second] = i;
                stk.pop_back();
            }
            stk.push_back(make_pair(A[i], i));
        }
        
        
        i64 ans = 0, left, right;
        for(int i = 0; i < N; ++i) {
            i64 now = S[R[i]] - S[L[i] + 1];
            now *= A[i];
            if(now > ans) {
                ans = now;
                left = L[i] + 2;
                right = R[i];
            }
        }
        cout << ans << endl << left << ' ' << right << endl;
    }
    
}
