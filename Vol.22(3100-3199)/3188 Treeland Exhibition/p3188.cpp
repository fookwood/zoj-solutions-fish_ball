#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    int N, L;
    vector<vector<int> > G;
    while(cin >> N >> L) {
        G.assign(N, vector<int>());
        for(int i = 1, v, w; i < N; ++i) {
            scanf("%d%d", &v, &w);
            G[v].push_back(w);
            G[w].push_back(v);
        }
        vector<int> leaf;
        for(int i = 0; i < N; ++i)
            if(G[i].size() == 1)
                leaf.push_back();
        queue<pair<int> >
    }
}
 
