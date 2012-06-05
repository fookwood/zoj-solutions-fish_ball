// 2035268 2009-11-13 22:31:05 Accepted  3258 C++ 280 368 呆滞的慢板 

// 新型的背包变种，固体物品加流体物品。
// 采用 背包DP + 贪心 的办法来求得最优解。
// 先对固体物品做背包，然后枚举所有重量为 w 时的最大价值 p。
// 然后还有 W-w 的容量，求取 W-w 的容量用最优的流体组合(直接贪心)能有的价值 q。
// 最后用 p + q 来更新最优值。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double mv(vector<pair<int, int> > wt, int cnt) {
    double ans = 0;
    int amt = 0;
    for(int i = wt.size() - 1; i >= 0; --i) {
        if(wt[i].first + amt > cnt) {
            return ans + (double)wt[i].second / wt[i].first * (cnt - amt);
        }
        else {
            ans += wt[i].second;
            amt += wt[i].first;
        }
    }
    return ans;
}

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second * rhs.first < lhs.first * rhs.second;
}

int main() {
    int N, W;
    while(cin >> N >> W) {
        vector<pair<int, int> > st(0), wt(0);
        for(int i = 0, x, y, z; i < N; ++i) {
            cin >> x >> y >> z;
            if(z) {
                wt.push_back(make_pair(x, y)); 
            }
            else {
                st.push_back(make_pair(x, y)); 
            }
        }
        sort(wt.begin(), wt.end(), cmp);
        vector<int> DP(W + 1, -1);
        DP[0] = 0;
        for(int i = 0; i < st.size(); ++i) {
            for(int j = W - st[i].first; j >= 0; --j) {
                if(DP[j] != -1 && DP[j + st[i].first] < DP[j] + st[i].second) {
                    DP[j + st[i].first] = DP[j] + st[i].second;
                }
            }
        }
        double ans = 0;
        for(int i = W; i >= 0; --i) {
            if(DP[i] != -1 && ans < DP[i] + mv(wt, W - i)) {
                ans = DP[i] + mv(wt, W - i);
            }
        }
        printf("%.2lf\n", ans);
    }
}
