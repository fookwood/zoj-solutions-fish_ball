// 1784645 2009-03-10 23:39:55 Accepted  3088 C++ 60 8004 呆滞的慢板 

// 全源最短 / 最长路，不能够 Floyd 的，只能作为 N 个单源来做。 
// 这里就可以选 dijkstra 或者 SPFA 来实现，我这里用 SPFA 之后蛮搞就过了。 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int P[1000][1000], Q[1000][1000];

int UP[1000], DN[1000];
        
void output(int PRE[], int v, int w) {
    if(v == w) return;
    output(PRE, v, PRE[w]);
    printf(" %d", w + 1);
}

int main() {
    
    int T;
    for(cin >> T; T--;) {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        vector<vector<pair<int, int> > > S(N);
        vector<vector<pair<int, int> > > L(N);
        for(int i = 0, v, w, l; i < M; ++i) {
            scanf("%d%d%d", &v, &w, &l);
            S[v-1].push_back(make_pair(w-1, l));
        }
        for(int i = 0, v, w, l; i < K; ++i) {
            scanf("%d%d%d", &v, &w, &l);
            L[v-1].push_back(make_pair(w-1, l));
        }
        memset(P, -1, sizeof(P));
        for(int i = 0; i < N; ++i) {
            queue<int> QQ;
            P[i][i] = 0;
            QQ.push(i);
            while(!QQ.empty()) {
                int v = QQ.front();
                QQ.pop();
                for(int k = 0, w, d; k < S[v].size(); ++k) {
                    w = S[v][k].first;
                    d = P[i][v] + S[v][k].second;
                    if(P[i][w] == -1 || P[i][w] < d) {
                        P[i][w] = d;
                        QQ.push(w);
                    }
                }
            }
        }
        memset(Q, -1, sizeof(Q));
        for(int i = 0; i < N; ++i) {
            queue<int> QQ;
            Q[i][i] = 0;
            QQ.push(i);
            while(!QQ.empty()) {
                int v = QQ.front();
                QQ.pop();
                for(int k = 0, w, d; k < L[v].size(); ++k) {
                    w = L[v][k].first;
                    d = Q[i][v] + L[v][k].second;
                    if(Q[i][w] == -1 || Q[i][w] > d) {
                        Q[i][w] = d;
                        QQ.push(w);
                    }
                }
            }
        }
        int x = -1, y = -1;
        double rate = 0.0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(P[i][j] > 0 && Q[j][i] > 0 &&
                    rate < (double)P[i][j] / (double)Q[j][i]) {
                    x = i;
                    y = j;
                    rate = (double)P[i][j] / (double)Q[j][i];
                }
            }
        }
        
        memset(DN, -1, sizeof(DN));
        memset(UP, -1, sizeof(UP));
        
        do {
            int i = x;
            memset(P[i], -1, sizeof(DN));
            queue<int> QQ;
            P[i][i] = 0;
            QQ.push(i);
            while(!QQ.empty()) {
                int v = QQ.front();
                QQ.pop();
                for(int k = 0, w, d; k < S[v].size(); ++k) {
                    w = S[v][k].first;
                    d = P[i][v] + S[v][k].second;
                    if(P[i][w] == -1 || P[i][w] < d) {
                        P[i][w] = d;
                        DN[w] = v;
                        QQ.push(w);
                    }
                }
            }
        } while(false);
        
        do {
            int i = y;
            memset(Q[i], -1, sizeof(DN));
            queue<int> QQ;
            Q[i][i] = 0;
            QQ.push(i);
            while(!QQ.empty()) {
                int v = QQ.front();
                QQ.pop();
                for(int k = 0, w, d; k < L[v].size(); ++k) {
                    w = L[v][k].first;
                    d = Q[i][v] + L[v][k].second;
                    if(Q[i][w] == -1 || Q[i][w] > d) {
                        Q[i][w] = d;
                        UP[w] = v;
                        QQ.push(w);
                    }
                }
            }
        } while(false);
        
        printf("%d", y + 1);
        output(UP, y, x);
        output(DN, x, y);
        puts("");
        
        printf("%.3lf\n", rate);
    }
    
}
