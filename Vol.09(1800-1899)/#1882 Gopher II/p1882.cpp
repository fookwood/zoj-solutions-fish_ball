// 3023911 2008-08-06 01:30:36 Accepted 1882 C++ 00:00.21 876K 呆滞的慢板 

// 二部图最大匹配，根据各个参数，可以确定某地鼠是否可以安全到达某个洞 
// 如果是，它们之间存在一条边，求这个二部图的最大匹配 

//////////////////////////////////////////////////////////
//                 二分匹配算法类模板 v1.0              //
//////////////////////////////////////////////////////////
//                                                      //
// 求一个无权二分图的最大匹配                           //
// 1. init:     构造空匹配关系表;                       //
// 2. insert:   插入一个新的匹配关系;                   //
// 3. run:      在确定大小和匹配关系后运行计算;         //
// 4. matchCnt: 返回最大匹配数;                         // 
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
    
}; 


//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
using namespace std;

BinMatch    binmatch;

double  x[100], y[100];
double  X[100], Y[100];
    
int n,  m,  s,  v;

int main() {
    
    
    while( cin >> n >> m >> s >> v ) {
        
        double  dis = s * v;
        
        for( int i = 0; i < n; i++ )
            cin >> x[i] >> y[i];
            
        for( int i = 0; i < m; i++ )
            cin >> X[i] >> Y[i];
            
        binmatch.init( n, m );
            
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                if( hypot( (X[j]-x[i]), (Y[j]-y[i]) ) < dis + 1e-5 )
                binmatch.insert( i, j );
            }
        }
        
        binmatch.run();
        
        cout << n - binmatch.matchCnt() << endl;
        
    }
}
