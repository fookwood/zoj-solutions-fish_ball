#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
vector<vector<pair<int, int> > G;

int DP[1000][1000], DIS[1000], CNT[1000];

int main() {
    while(cin >> V && V) {
        cin >> E;
        G.assign(V, vector<int>());
        while(E--) {
            int v, w, l;
            scanf("%d%d%d", &v, &v, &l);
            G[v - 1].push_back(make_pair(w - 1, l));
            memset(DP, -1, sizeof(DP));
            memset(DIS, -1, sizeof(DIS));
            DIS[0] = 
        }
    }
}