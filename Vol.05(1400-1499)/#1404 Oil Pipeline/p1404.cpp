// 1831007 2009-04-12 14:31:17 Accepted  1404 C++ 10 184 呆滞的慢板 

// 油管最优布局，中级模拟题，对算法要求不高，直接蛮力即可。
// 注意一下布局框的计算、坐标的位置等即可，注意题目说最北的坐标必须顶格，
// 也就是说如果左侧坐标最大值 < 10 的话左侧坐标只需要留一个位置。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X, Y, T = 1;
    vector<pair<int, int> > V;
    while(cin >> X >> Y && X) {
        cout << "OIL FIELD " << T++ << endl;
        V.clear();
        while(X != -1) {
            V.push_back(make_pair(X, Y));
            cin >> X >> Y;
        }
        sort(V.begin(), V.end());
        vector<int> P(0);
        int x1 = 100, x2 = 0, y1 = 100, y2 = 0;
        for(int i = 0; i < V.size(); ++i) {
            if(P.empty() || V[i].first != P.back())
                P.push_back(V[i].first);
            x1 = min(x1, V[i].first);
            x2 = max(x2, V[i].first);
            y1 = min(y1, V[i].second);
            y2 = max(y2, V[i].second);
        }
        int best = y1, val = INT_MAX;
        for(int y = y1; y <= y2; ++y) {
            int sum = 0;
            for(int i = 0, j = 0; i < P.size(); ++i) {
                int mn = y, mx = y;
                for(; j < V.size() && V[j].first == P[i]; ++j) {
                    mn = min(mn, V[j].second);
                    mx = max(mx, V[j].second);
                }
                sum += mx - mn;
            }
            if(sum < val) {
                best = y;
                val = sum;
            }
        }
        int xb1 = (x1 - 1) / 5 * 5;
        int yb1 = (y1 - 1) / 5 * 5;
        int xb2 = (x2 / 5 + 1) * 5;
        int yb2 = (y2 / 5 + 1) * 5;
        if(xb2 - xb1 > 70 || yb2 - yb1 > 20) {
            cout << "Map is too big to draw for pipeline at " << best << endl;
            continue;
        }
        vector<string> G(yb2 - yb1 + 1, string(xb2 - xb1 + 1, '.'));
        for(int i = 0; i <= yb2 - yb1; ++i)
            G[i][0] = G[i][xb2 - xb1] = (i % 5 == 0) ? '+' : '|';
        for(int i = 0; i <= xb2 - xb1; ++i)
            G[0][i] = G[yb2 - yb1][i] = (i % 5 == 0) ? '+' : '-';
        for(int i = 0; i < V.size(); ++i)
            G[V[i].second - yb1][V[i].first - xb1] = '@';
        for(int i = 1; i < xb2 - xb1; ++i)
            G[best - yb1][i] = G[best - yb1][i] == '@' ? '@' : '*';
        for(int i = 0, j = 0; i < P.size(); ++i) {
            int mn = best, mx = best;
            for(; j < V.size() && V[j].first == P[i]; ++j) {
                mn = min(mn, V[j].second);
                mx = max(mx, V[j].second);
            }
            for(int y = mn; y <= mx; ++ y)
                G[y - yb1][P[i] - xb1] = G[y - yb1][P[i] - xb1] == '@' ? '@' : '*';
        }
        for(int i = 0; i < G.size(); ++i) {
            if(i % 5 != 0) G[i] = "  " + G[i];
            else {
                G[i] = string(1, '0' + (i + yb1) % 10) + G[i];
                G[i] = (((i + yb1) / 10) ? string(1, '0' + (i + yb1) / 10) : " ") + G[i];
            }
        }
        reverse(G.begin(), G.end());
        for(int i = 0; i < G.size(); ++i) {
            if(G[0][0] == ' ')
                cout << G[i].substr(1) << endl;
            else
                cout << G[i] << endl;
        }
        if(G[0][0] == ' ')
            cout << " ";
        else
            cout << "  ";
        for(int i = xb1; i <= xb2; i += 5) {
            cout << i;
            if(i == xb2) continue;
            if(i < 10) cout << ' ';
            cout << "   ";
        }
        cout << endl;
    }
    
}
