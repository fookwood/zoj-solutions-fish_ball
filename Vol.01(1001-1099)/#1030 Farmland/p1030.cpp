#include <iostream>
#include <vector>
using namespace std;

class Farmland {

    static int quadrant(int x, int y) {
        if(y > 0) return x > 0 ? 0 : 1;
        else      return x > 0 ? 3 : 2;
    }

    vector<int> X, Y;
    int N, L;
    vector<vector<int> > G;
    vector<vector<bool> > ADJ;
    
    vector<bool> B, LP;
    vector<int> path;
    int cnt;
    
    bool valid() {

        for(int i = 0; i < L; ++i) {
            for(int j = i + 2; j < L; ++j) {
                if(i == 0 && j == L - 1) continue;
                if(ADJ[path[i]][path[j]]) return false;
            }
        }

        LP.assign(N, false);

        for(int i = 0; i < L; ++i)
            LP[path[i]] = true;

        for(int v = 0; v < N; ++v) {
            if(LP[v]) continue;
            int phase = 0;
            for(int i = 0; i < L; ++i) {
                int xa = X[path[i]] - X[v],
                    ya = Y[path[i]] - Y[v],
                    qa = quadrant(xa, ya),
                    xb = X[path[(i+1)%L]] - X[v],
                    yb = Y[path[(i+1)%L]] - Y[v],
                    qb = quadrant(xb, yb);
                if(qa == qb) ;
                else if((qb - qa + 4) % 4 == 1) phase += 1;
                else if((qb - qa + 4) % 4 == 3) phase -= 1;
                else if(xa * yb - xb * ya > 0) phase += 2;
                else phase -= 2;
            }
/*
            cout << "v = " << v+1 << "  ";
            cout << "phase = " << phase << endl;
//*/
            if(phase != 0) return false;
        }
        return true;

    }
    
    void dfs(int v, int l) {
        B[v] = true;
        path.push_back(v);
        
        // 环结尾 
        if(l == L) {
            if(ADJ[path.front()][v]) {
/*
                for(int i = 0; i < L; ++i)
                    cout << path[i]+1 << ' ';
                cout << (valid()?" yes":" no");
                cout << endl;
//*/
                cnt += valid();
            }
        }
        // 继续扩展路径 
        else {
            for(int i = 0, w; i < G[v].size(); ++i) {
                w = G[v][i];
                if(!B[w]) dfs(w, l + 1);
            } 
        }
        
        path.pop_back();
        B[v] = false;
    }
    
public:

    void read() {
        cin >> N;
        X.resize(N);
        Y.resize(N);
        G.assign(N, vector<int>(0));
        ADJ.assign(N, vector<bool>(N, false));
        for(int i = 0, buf, k; i < N; ++i) {
            cin >> buf;
            cin >> X[buf - 1] >> Y[buf - 1];
            cin >> k;
            while(k--) {
                G[buf - 1].push_back(0);
                cin >> G[buf - 1].back();
                G[buf - 1].back() -= 1;
                ADJ[buf - 1][G[buf - 1].back()] = true;
            }
        }
        cin >> L;
    }
    
    int count() {
        cnt = 0;
        for(int i = 0; i < N; ++i) {
            B.assign(N, false);
            path.clear();
            dfs(i, 1);
        }
//        cout << "cnt = " << cnt << endl;
        return cnt / 2 / L;
    }
    
};

int main() {
//    freopen("farmland.in", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    for(cin >> T; T--;) {
        Farmland obj;
        obj.read();
        cout << obj.count() << endl;
    }
//    system("pause");
}
