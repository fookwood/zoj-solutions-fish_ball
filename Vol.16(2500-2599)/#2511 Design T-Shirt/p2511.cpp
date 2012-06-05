// 1781657 2009-03-08 00:55:59 Accepted  2511 C++ 250 184 呆滞的慢板 

// 很水很直白，直接加起来，然后贪心取最大就行了。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    while(cin >> N >> M >> K) {
        vector<pair<double, int> > V(M);
        for(int i = 0; i < M; ++i) {
            V[i].first = 0;
            V[i].second = i;
        }
        for(int i = 0; i < N; ++i) {
            double p;
            for(int j = 0; j < M; ++j) {
                scanf("%lf", &p);
                V[j].first -= p;
            }
        }
        sort(V.begin(), V.end());
        vector<int> ans(0);
        for(int i = 0; i < K; ++i)
            ans.push_back(V[i].second);
        sort(ans.begin(), ans.end());
        for(int i = ans.size() - 1; i >= 0; --i)
            printf("%d%c", ans[i] + 1, i == 0 ? '\n' : ' ');
    }
}
