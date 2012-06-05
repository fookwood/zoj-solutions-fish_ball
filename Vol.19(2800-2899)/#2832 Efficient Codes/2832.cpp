// 1686315 2008-11-02 15:15:05 Accepted  2832 C++ 0 224 呆滞的慢板 

// 对一个 DAG 求所有源点。 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> name;
map<string, int> mp;

int N, T = 0, K, M;
bool G[200][200];
vector<int> useful;
vector<string> ans;

int getIndex(const string& s) {
    if(mp.find(s) != mp.end())
        return mp[s];
    name.push_back(s);
    M = name.size();
    return mp[s] = M - 1;
}

int main() {
    while(cin >> N) {
        if(T++) puts("");
        memset(G, 0, sizeof(G));
        name.clear();
        mp.clear();
        useful.clear();
        for(int i = 0, v; i < N; ++i) {
            string s;
            cin >> s;
            useful.push_back(v = getIndex(s));
            for(cin >> K; K--;) {
                cin >> s;
                G[v][getIndex(s)] = true;
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    if(G[useful[j]][useful[i]] && G[useful[j]][useful[k]])
                        G[useful[j]][useful[k]] = true;
                }
            }
        }
        ans.clear();
        for(int i = 0; i < N; ++i) {
            bool yes = true;
            for(int j = 0; j < N; ++j) {
                if(j == i) continue;
                if(G[useful[j]][useful[i]]) {
                    yes = false;
                    break;
                }
            }
            if(yes) ans.push_back(name[useful[i]]);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    }
}
