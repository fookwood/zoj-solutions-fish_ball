// 2938218 2008-05-31 15:20:36 Accepted 2750 C++ 00:00.47 4820K 呆滞的慢板 

// 单源最短路，Floyd 会超时
// 第一次写的 Dijkstra，相当的难看... 

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int G[1000][1000];

const int MAX = 2000000000;

typedef pair<int, int>  Data;

int main() {
    
    string  input;
    int     N;
    map<string, vector<int> >   head;
    map<string, vector<int> >::iterator iter;
    int     P[1000];
    string  V[1000];
    char    S[2000];
    int     M,          K;
    Data    T[1000],    Q[1000];
        
    while( scanf( "%d", &N ) && N ) {
    
        memset( G, -1, sizeof( G ) );
        
        head.clear();
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%d%s", P + i, S );
            input = S;
            head[input.substr(0,4)].push_back(i);
            V[i] = input.substr( input.size() - 4 );
        }
        
        for( int i = 0; i < N; ++i ) {
            iter = head.find( V[i] );
            if( iter == head.end() )
                continue;
            for( int j = 0; j < iter -> second.size(); ++j )
                G[i][iter->second[j]] = P[i];
        }
        
        for( K = M = 0; K < N; ++K ) {
            Q[K].first = MAX;   // first 代表总路径长 
            Q[K].second = K;    // seconde 代表节点号 
        }
    
        Q[0].first = 0;
        T[M] = Q[0];
        Q[0].first = -1;
        
        while( --K ) {
            
            for( int i = 0; i < N; ++i ) {
                if( G[T[M].second][i] != -1 &&
                    Q[i].first > G[T[M].second][i] + T[M].first ) {
                    Q[i].first = G[T[M].second][i] + T[M].first;
                }
            }
            int min_val = MAX, mini = -1;
            for( int i = 1; i < N; ++i ) {
                if( Q[i].first != -1 &&
                    Q[i].first < min_val ) {
                    min_val = Q[i].first;
                    mini = i;
                }
            }
            if( min_val == MAX )
                break;
            T[++M] = Q[mini];
            Q[mini].first = -1;
        }

        for( int i = 0; i <= M; ++i ) {
            if( T[i].second == N - 1 ) {
                cout << T[i].first << endl;
                break;
            }
            if( i == M )
                cout << -1 << endl;
        }

    }
    
}
