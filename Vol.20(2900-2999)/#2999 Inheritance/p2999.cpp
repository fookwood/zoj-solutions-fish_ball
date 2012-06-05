// 527 2008-06-21 14:23:25 Accepted 1004 C++ 00:01:81 3816K 呆滞的慢板 

// 2954140 2008-06-21 17:48:58 Accepted 2999 C++ 00:01.83 3816K 呆滞的慢板 

// 时间戳.. 考察一个有根树两个节点的继承关系
// 这里是个森林，时间戳要保证整个森力都戳过，瓶颈在于 map 的地方，换 hash 会快 
// 月赛现场做的，搞了 18 wa + tle + rte.... 

#include <vector>
#include <string>
#include <map>
using namespace std; 

vector<int> G[30010];
int     p1[30010],  p2[30010],  top; 
int     T = 0,  tt;
int     N,  x,  y,  v; 
int     in[30010],  out[30010], R[30010]; 
bool    visited[30010];
char    s1[1000],   s2[1000];
map<string, int>    M;
map<string, int>::iterator  iter;


int main() {
    
    int     T = 0; 
    
    while( scanf( "%s", s1 ) != EOF ) {

        scanf( "%d", &N );
        
        if( T++ )   puts( "" ); 
    
        printf( "Project %d\n", T ); 

        M.clear();

        for( int i = 0; i < N; ++i )
            G[i].clear();
        
        memset( R, -1, sizeof( R ) );
        memset( visited, 0, sizeof( visited ) );

        int X = 0; 
        for( int i = 0; i < N; ++i ) {
            
            scanf( "%s%s", s1, s2 );
            
            iter = M.find( s2 );
            if( iter == M.end() )
                y = M[s2] = X++;
            else    y = iter -> second;
            
            iter = M.find( s1 );
            if( iter == M.end() )
                x = M[s1] = X++;
            else    x = iter -> second;
            
            G[y].push_back( x );
            R[x] = y;
            
        }
        
        tt = 0;
        for( int i = 0; i < N; ++i ) {
            if( !visited[i] ) {
                v = i;
                while( R[v] != -1 )
                    v = R[v];
                top = 0;
                p1[top] = v;
                p2[top] = 0;
                visited[v] = true;
                in[v] = tt++;
                while( top >= 0 ) {
                    if( p2[top] < G[p1[top]].size() ) {
                        y = G[p1[top]][p2[top]]; 
                        if( !visited[y] ) {
                            in[y] = tt++;
                            visited[y] = true;
                            ++top;
                            p1[top] = y;
                            p2[top] = 0;
                        }
                        else    ++p2[top];
                    }
                    else    out[p1[top--]] = tt++;
                }
                
            }
        }
        
        for( scanf( "%d", &N ); N--; ) {
            scanf( "%s%s", s1, s2 );
            x = M[s1];
            y = M[s2];
            if( in[x] >= in[y] &&
                out[x] <= out[y] )
                puts( "Yes" );
            else
                puts( "No" );
        }
        

    } 

} 
