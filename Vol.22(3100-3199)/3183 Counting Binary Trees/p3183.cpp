#include <iostream>
using namespace std;

int DP[100001];
long long M;

long long eval(int N) {
    if(DP[N] != 0) return DP[N];
    long long ans = 0;
    for(int i = 0; i < N; ++i) {
        ans += (eval(i) * eval(N - 1 - i)) % M;
        ans %= M;
    }
    return DP[N] = ans;
}

int main() {
    int N;
    while(cin >> N >> M && N) {
        memset(DP, 0, sizeof(DP));
        DP[0] = DP[1] = 1;
        cout << eval(N) << endl;
    }
}
