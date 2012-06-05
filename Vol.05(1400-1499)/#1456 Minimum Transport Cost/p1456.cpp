// 3008305 2008-07-27 09:58:50 Accepted 1456 C++ 00:00.01 1156K 呆滞的慢板 

// 带路径存储的最短路，Floyd 实现。 

// 注意两点：
// 1. 对于权值相同的时候，比较两条路径的字典序决定是否松弛；
// 2. 对于输出路径 x->y，当 x==y 时要小心，WA 了多次。 

#include <iostream>
#include <vector>
using namespace std;

int     V[201][201],    P[201][201];
int     C[201], x,  y,  z,  N;
vector<int> p1, p2;

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 1; i <= N; ++i )
            for( int j = 1; j <= N; ++j )
                scanf( "%d", &V[i][j] );
        
        for( int i = 1; i <= N; ++i ) {
            scanf( "%d", C + i );
            for( int j = 1; j <= N; ++j ) {
                if( V[j][i] > 0 )
                    V[j][i] += C[i];
                P[j][i] = i;
            }
        }
        
        for( int k = 1; k <= N; ++k ) {
            for( int i = 1; i <= N; ++i ) {
                for( int j = 1; j <= N; ++j ) {
                    if( V[i][k] > 0 && V[k][j] > 0 ) {
                        if( V[i][j] == -1 || V[i][j] > V[i][k] + V[k][j] ) {
                            V[i][j] = V[i][k] + V[k][j];
                            P[i][j] = P[i][k];
                        }
                        else if( V[i][j] == V[i][k] + V[k][j] ) {
                            // 得到两条路径 
                            p1.clear();
                            p2.clear();
                            p1.push_back( x = i );
                            while( x != j )
                                p1.push_back( x = P[x][j] );
                            p2.push_back( x = i );
                            while( x != k )
                                p2.push_back( x = P[x][k] );
                            while( x != j )
                                p2.push_back( x = P[x][j] );
                            if( p2 < p1 ) {
                                V[i][j] = V[i][k] + V[k][j];
                                P[i][j] = P[i][k];
                            } 
                        }
                    }
                }
            }
        }
        
        while( scanf( "%d%d", &x, &y ) && x != -1 ) {
            printf( "From %d to %d :\nPath: %d", x, y, z = x );
            while( x != y ) printf( "-->%d", x = P[x][y] );
            printf( "\nTotal cost : %d\n\n", z != y ? V[z][y] - C[y] : 0 ); 
        } 
        
    }
    
}
