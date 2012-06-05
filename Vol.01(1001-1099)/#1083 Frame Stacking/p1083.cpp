// 2894654 2008-05-06 21:44:35 Accepted 1083 C++ 00:00.01 840K 呆滞的慢板

// 困扰我好久好久的题啊！！
// 是拓扑排序！！
// 先将所有可能的字母求出来，纪录成一个图
// 对每个字母，它的方框边上有其他字母，那么这里就有一条拓扑图的边
// 然后，顺序输出所有拓扑排序！！
// 写得都恶心了，还好写完之后居然调试直接成功 + AC ！！ 

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int     L[256];
char    A[30][31];
int     H,  W,  N;
set<char>   S;
vector<char>  Node;
vector<char>  stk;
bool    E[30][30];
bool    n_visit[30];


void DFS( int remain ) {
    
    if( remain == 0 ) {
        for( int i = 0; i < stk.size(); ++i )
            putchar( stk[i] );
        putchar( '\n' );
        return;
    }
    
    for( int i = 0; i < N; ++i ) {
        if( n_visit[i] ) {
            bool  yes = true;
            for( int j = 0; j < N; ++j ) {
                if( E[j][i] ) {
                    yes = false;
                    break;
                }
            }
            if( yes ) {
                vector<int> path( 0 );
                for( int j = 0; j < N; ++j ) {
                    if( E[i][j] ) {
                        path.push_back( j );
                        E[i][j] = false;
                    }
                }
                n_visit[i] = false;
                stk.push_back( Node[i] );
                DFS( remain - 1 );
                stk.pop_back();
                n_visit[i] = true;
                for( int j = 0; j < path.size(); ++j )
                    E[i][path[j]] = true;
            }
        }
    }
    
}


int main() {
    
    while( cin >> H >> W ) {
        
        S.clear();
        
        for( int i = 0; i < H; ++i ) {
            cin >> A[i];
            for( int j = 0; j < W; ++j )
                if( A[i][j] != '.' )
                    S.insert( A[i][j] );
        }
        
        Node.clear();
        for( set<char>::iterator iter = S.begin();
                iter != S.end(); ++iter ) {
            Node.push_back( *iter );
        }

        N = Node.size();
        
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                E[i][j] = false;
                
        for( int i = 0; i < 256; ++i )  L[i] = -1;
        
        for( int i = 0; i < N; ++i )    L[Node[i]] = i;
        
        // 生成拓扑图邻接矩阵 
        for( int i = 0; i < N; ++i ) {
            
            int x1 = 10, x2 = 0, y1 = 10, y2 = 0;
            for( int j = 0; j < H; ++j ) {
                for( int k = 0; k < W; ++k ) {
                    if( A[j][k] == Node[i] ) {
                        x1 = min( x1, j );
                        x2 = max( x2, j );
                        y1 = min( y1, k );
                        y2 = max( y2, k );
                    }
                }
            }
            
            for( int j = x1; j <= x2; ++j ) {
                if( A[j][y1] != '.' && A[j][y1] != Node[i] )
                    E[i][L[A[j][y1]]] = true;
                if( A[j][y2] != '.' && A[j][y2] != Node[i] )
                    E[i][L[A[j][y2]]] = true;
            }
            
            for( int j = y1; j <= y2; ++j ) {
                if( A[x1][j] != '.' && A[x1][j] != Node[i] )
                    E[i][L[A[x1][j]]] = true;
                if( A[x2][j] != '.' && A[x2][j] != Node[i] )
                    E[i][L[A[x2][j]]] = true;
            }
            
        }
        
        // 生成所有拓扑排序并输出 
        for( int i = 0; i < N; ++i )
            n_visit[i] = true;
        stk.clear();
        DFS( N );

    }
    
}
