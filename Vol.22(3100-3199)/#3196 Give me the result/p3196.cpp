// 1862208 2009-05-10 03:23:48 Accepted  3196 C++ 630 184 呆滞的慢板 

// 算是一道比较水的搜索题，关键在于用 dfs 暴力找出所有可能的符号排列。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool contains(long long x, int y) {
    if(x == 0 && y == 0) return true;
    while(x) {
        if(x % 10 == y) return true;
        x /= 10;
    }
    return false;
}

long long dfs(int n, int k, const vector<int>& num, vector<char>& op) {
    long long ans = 0x8000000000000000LL;
    if(n == op.size()) {
        long long sum = num[0];
        for(int i = 0; i < op.size(); ++i) {
            switch(op[i]) {
                case '+':
                    sum += num[i+1];
                break;
                case '-':
                    sum -= num[i+1];
                    if(sum < 0) sum = -sum;
                break;
                case '*':
                    sum *= num[i+1];
                break;
                case '/':
                    if(num[i+1] == 0) return 0x8000000000000000LL;
                    sum /= num[i+1];
                break;
            }
        }
        if(!contains(sum, k))
            ans = max(sum, ans);
    }
    else {
        char* ops = "+-*/";
        for(int i = 0; i < 4; ++i) {
            op[n] = ops[i];
            ans = max(ans, dfs(n + 1, k, num, op));
        }
    }
    return ans;
}

int main() {
    int T;
    for(cin >> T; T--;) {
        int N, K;
        cin >> N >> K;
        vector<int> num(N);
        vector<char> op(N - 1);
        for(int i = 0; i < N; ++i)
            cin >> num[i];
        long long ans = dfs(0, K, num, op);
        if(ans == 0x8000000000000000LL)
            puts("No result");
        else
            cout << ans << endl;
    }
}
