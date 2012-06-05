// 3024832 2008-08-06 16:45:39 Accepted 1654 C++ 00:00.03 1036K 呆滞的慢板 

// 考虑如何将此问题归约成一个匹配问题？
// 令顶点集为所有连通的线段集合
// 横线段和竖线段为二分图的两个划分
// 如果一个横线段和一个竖线段相交处有一个 o 那么存在一条边 


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
#include <map> 
#include <vector> 
using namespace std;

int     T,  M,  N,  p1, p2, n1, n2, X,  Y;

char    A[50][50];

typedef pair<pair<int, int>, pair<int, int> >   Segment;

Segment seg( int x1, int y1, int x2, int y2 ) {
    return  make_pair( make_pair( x1, y1 ),
                       make_pair( x2, y2 ) );
} 

Segment now; 

map<Segment, int>    Vertical,   Horizontal; 

vector<pair<int, int> >    V; 

BinMatch    binmatch; 

int main() {
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
        cin >> M >> N;
        for( int i = 0; i < M; ++i )
            cin >> A[i];
        
        Vertical.clear();
        Horizontal.clear(); 
        V.clear(); 
    
        X = Y = 1;
    
        for( int i = 0; i < M; ++i ) {
            
            for( int j = 0; j < N; ++j ) if( A[i][j] == 'o' ) {
                
                p1 = p2 = i;
                while( p1 >= 0 && A[p1][j] != '#' ) --p1;
                while( p2 < N  && A[p2][j] != '#' ) ++p2;
                now = seg( p1+1, j, p2-1, j );
                n1 = Vertical[now]; 
                if( !n1 ) n1 = Vertical[now] = X++;
                
                p1 = p2 = j;
                while( p1 >= 0 && A[i][p1] != '#' ) --p1;
                while( p2 < M  && A[i][p2] != '#' ) ++p2;
                now = seg( i, p1+1, i, p2-1 );
                n2 = Horizontal[now]; 
                if( !n2 ) n2 = Horizontal[now] = Y++;
                
                V.push_back( make_pair( n1, n2 ) );
                
            }
            
        }
        
        binmatch.init( X, Y );
        
        for( int i = 0; i < V.size(); ++i )
            binmatch.insert( V[i].first, V[i].second );
            
        binmatch.run();
        
        cout << "Case :" << t << endl << binmatch.matchCnt() << endl;
        
    }
    
}
