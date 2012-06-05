#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int T, M, N, K, x;

int G[10][10];
bool B[10][10], L[10][10];

deque<int> P;

struct Oper{int t, d, c;};

vector<Oper> V;
vector<int> buf;

bool kill() {
    bool ans = false;
    memset(B, 0, sizeof(B));
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(j+2 < N && G[i][j]==G[i][j+1]
                && G[i][j]==G[i][j+2]) {
                ans = B[i][j] = B[i][j+1]
                    = B[i][j+2] = L[i][j]
                    = L[i][j+1] = L[i][j+2] = true;
            }
            if(i+2 < M && G[i][j]==G[i+1][j]
                && G[i][j]==G[i+2][j]) {
                ans = B[i][j] = B[i+1][j]
                    = B[i+2][j] = L[i][j]
                    = L[i+1][j] = L[i+2][j] = true;
            }
        }
    }
    for(int j = 0; j < N; ++j) {
        for(int i = M-1, n = M-1; i >= 0; --i) {
            if(!B[i][j]) {
                int p = G[i][j];
                G[i][j] = 0;
                G[n--][j] = p;
            }
            else G[i][j] = 0;
        }
    }
    return ans;
}

void recover() {
    for(int j = 0; j < N; ++j) {
        for(int i = M-1; i >= 0; --i) {
            if(G[i][j] == 0) {
                G[i][j] = P.front();
                P.pop_front();
            }
        }
    }
}

int mark_cnt() {
    int ans = 0;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            ans += L[i][j];
    return ans;
}

int main() {
    for(cin >> T; T--;) {
        cin >> M >> N;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                cin >> G[i][j];
        cin >> K;
        V.resize(K);
        for(int i = 0; i < K; ++i)
            cin >> V[i].t >> V[i].d >> V[i].c;
        P.clear();
        while(cin >> x && x)
            P.push_back(x);
        memset(L, 0, sizeof(L));
        for(int i = 0; i < K; ++i) {
            buf.clear();
            V[i].d -= 1;
            if(V[i].t == 1) {
                for(int j = V[i].c; j < N+V[i].c; ++j)
                    buf.push_back(G[V[i].d][j%N]);
                for(int j = 0; j < N; ++j)
                    G[V[i].d][j] = buf[j];
            }
            else {
                for(int j = V[i].c; j < M+V[i].c; ++j)
                    buf.push_back(G[j%M][V[i].d]);
                for(int j = 0; j < M; ++j)
                    G[j][V[i].d] = buf[j];
            }
            while(kill()) recover();
        }
        cout << mark_cnt() << endl;
    }
}
