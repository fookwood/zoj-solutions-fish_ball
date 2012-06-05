// 1842078 2009-04-23 15:58:19 Accepted  3101 C++ 10 184 呆滞的慢板 

// 先保存所有登入登出记录，然后对每一条查询，遍历一次这些记录， 
// 得到，所有有效区间存起来，然后再求静态区间并，这样就不用线段树了。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec {
    int T, X, Y, S;
};

int main() {
    int M, N, r, q;
    while(cin >> M >> N && M) {
        cin >> r;
        vector<Rec> V(r);
        for(int i = 0; i < r; ++i)
            scanf("%d%d%d%d", &V[i].T, &V[i].Y, &V[i].X, &V[i].S);
        for(cin >> q; q--;) {
            int t1, t2, x;
            scanf("%d%d%d", &t1, &t2, &x);
            vector<int> R(M, -1);
            vector<pair<int, int> > seg(0);
            for(int i = 0; i < r; ++i) {
                if(V[i].X != x) continue;
                if(V[i].S == 1) {
                    if(V[i].T >= t2) continue;
                    R[V[i].Y - 1] = max(V[i].T, t1);
                }
                else {
                    if(R[V[i].Y - 1] == -1) continue;
                    if(V[i].T <= t1) {
                        R[V[i].Y - 1] = -1;
                        continue;
                    }
                    seg.push_back(make_pair(R[V[i].Y - 1], min(V[i].T, t2)));
                    R[V[i].Y - 1] = -1;
                }
            }
            sort(seg.begin(), seg.end());
            int ans = 0;
            for(int i = 0; i < seg.size(); ++i) {
                if(i == seg.size() - 1 || 
                    seg[i + 1].first > seg[i].second) {
                    ans += seg[i].second - seg[i].first;
                }
                else {
                    seg[i + 1].first = min(seg[i + 1].first, seg[i].first);
                    seg[i + 1].second = max(seg[i + 1].second, seg[i].second);
                }
            }
            printf("%d\n", ans);
        }
    }
}
