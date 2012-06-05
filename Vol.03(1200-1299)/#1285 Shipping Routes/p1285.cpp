// 1887207 2009-05-29 02:22:51 Accepted  1285 C++ 0 184 呆滞的慢板 

// 普通的全源最短路，映射一下名称之后 Floyd 即可。 

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    
    int T;
    cin >> T;
    
    puts("SHIPPING ROUTES OUTPUT\n");
    
    for(int t = 1; t <= T; ++t) {
        printf("DATA SET %d\n\n", t);
        int N, M, Q;
        cin >> N >> M >> Q;
        map<string, int> MP;
        for(int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            MP[s] = i;
        }
        int G[30][30] = {};
        memset(G, -1, sizeof(G));
        for(int i = 0; i < M; ++i) {
            string s, t;
            cin >> s >> t;
            G[MP[s]][MP[t]] = 1;
            G[MP[t]][MP[s]] = 1;
        }
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    if(G[j][i] != -1 && G[i][k] != -1) {
                        if(G[j][k] == -1 || G[j][k] > G[j][i] + G[i][k])
                            G[j][k] = G[j][i] + G[i][k];
                    }
                }
            }
        }
        
        for(int i = 0; i < Q; ++i) {
            int k, l;
            string s, t;
            cin >> k >> s >> t;
            l = G[MP[s]][MP[t]];
            if(l == -1)
                puts("NO SHIPMENT POSSIBLE");
            else
                printf("$%d\n", k * l * 100);
        }
        
        puts("");
    }
    
    puts("END OF OUTPUT");
}
