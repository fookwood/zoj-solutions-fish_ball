// 1666132 2008-10-14 19:22:47 Accepted  1118 C++ 0 184 呆滞的慢板 

// 广义图搜索，直接硬来就是这样搞的。 

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<int> Pos;

map<Pos, vector<Pos> > M;
set<Pos> S;
int D;

Pos v, w, s, t;

bool get() {
    v.resize(D);
    w.resize(D);
    cin >> ws;
    if(cin.peek() == '-') {
        cin >> v[0];
        return false;
    }
    for(int i = 0; i < D; ++i) cin >> v[i];
    for(int i = 0; i < D; ++i) cin >> w[i];
}

bool dfs(Pos p) {
    if(p == t) return true;
    S.insert(p);
    vector<Pos>& V = M[p];
    for(int i = 0; i < V.size(); ++i)
        if(S.find(V[i]) == S.end() && dfs(V[i]))
            return true;
    return false;
}

int main() {
    int T = 1;
    while(cin >> D && D) {    
        get();
        s = v, t = w;
        M.clear();
        while(get()) {
            M[v].push_back(w);
            M[w].push_back(v);
        }
        S.clear();
        printf("Maze #%d ", T++);
        puts(dfs(s) ?
            "can be travelled" :
            "cannot be travelled");
    }
}
