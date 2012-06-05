// 3027512 2008-08-08 10:55:35 Accepted 1516 C++ 00:00.02 864K 呆滞的慢板 

// 可归约成二分匹配的问题
// 首先，将整个网格分成两部分，按照国际棋盘的颜色
// 明显的，黑色的格子是不可能用一个方块根白色的格子相连的
// 于是，可行的黑格和白格为二分图的两组顶点
// 如果某黑格与某白格相邻，增加一条边
// 然后求最大匹配 


//////////////////////////////////////////////////////////
//                 二分匹配算法类模板 v1.1              //
//////////////////////////////////////////////////////////
//                                                      //
// 求一个无权二分图的最大匹配                           //
// 1. init:     构造空匹配关系表;                       //
// 2. insert:   插入一个新的匹配关系;                   //
// 3. run:      在确定大小和匹配关系后运行计算;         //
// 4. matchCnt: 返回最大匹配数;                         // 
// 5. getMatch: 返回匹配标号的 vector<pair>;            // 
//                                                      //
// 1.1 新增返回所有匹配功能;                            // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;
 
class BinMatch {
    
    int     X,  Y,  M; 
    vector<vector<int> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int i = 0, w; i < G[v].size(); ++i ) {
            w = G[v][i]; 
            if( !mark[w] ) {
                mark[w] = true;
                if( back[w] == -1 || find( back[w] ) ) {
                    back[w] = v;
                    return  true;
                }
            }
        } 
        return  false;
    }
    
public:
    
    void init( int x, int y ) {
        X = x;  Y = y; 
        G.assign( X + 1, vector<int>( 0 ) );
    } 
    
    void insert( int v, int w ) { G[v].push_back( w ); }
    
    void run() {
        back.assign( Y + 1, -1 );
        for( int v = M = 0; v <= X; ++v ) {
            mark.assign( Y + 1, false ); 
            M += find( v );
        }
    } 
    
    int matchCnt() const { return M; }
    
    vector<pair<int, int> > getMatch() const {
        vector<pair<int, int> > ans;
        for( int i = 0; i < Y; ++i )
            if( back[i] != -1 )
                 ans.push_back( make_pair( back[i], i ) );
        return  ans;
    } 
    
}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////



#include <iostream>
#include <map>
using namespace std;

int     N,  M,  K,  x,  y; 

bool    A[101][101];

map<pair<int, int>, int >    S1, S2;

int C1, C2;

BinMatch    binmatch;

int main() {

    while( cin >> N >> M && N ) {
        
        memset( A, 0, sizeof( A ) );
    
        for( cin >> K; K--; ) {
            scanf( "%d%d", &x, &y );
            A[x-1][y-1] = true;
        }
        
        C1 = C2 = 0;
        S1.clear();
        S2.clear();
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        S1[make_pair( i, j )] = C1++;
                    else
                        S2[make_pair( i, j )] = C2++;
                }
            }
        }
        
        binmatch.init( C1, C2 );
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 1; j < M; ++j ) {
                if( !A[i][j-1] && !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        binmatch.insert( S1[make_pair(i,j)],
                                         S2[make_pair(i,j-1)] );
                    else
                        binmatch.insert( S1[make_pair(i,j-1)],
                                         S2[make_pair(i,j)] );
                }
            }
        }
        
        for( int i = 1; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( !A[i-1][j] && !A[i][j] ) {
                    if( ( i + j ) % 2 )
                        binmatch.insert( S1[make_pair(i,j)],
                                         S2[make_pair(i-1,j)] );
                    else
                        binmatch.insert( S1[make_pair(i-1,j)],
                                         S2[make_pair(i,j)] );
                }
            }
        }
        
        binmatch.run();
        
        cout << binmatch.matchCnt() << endl;
    
    }


}    
