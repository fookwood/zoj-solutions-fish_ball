// 3028508 2008-08-09 14:27:11 Accepted 2221 C++ 00:00.42 1248K 呆滞的慢板 

// 可以归约成一个最小路径覆盖，然后用二分匹配搞 

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
#include <vector>
#include <cmath>
using namespace std;

int     T,  N,  x,  y;
char    s;

BinMatch    binmatch;

struct Taxi {
    int begin,  end;
    int a,  b,  c,  d;
};

vector<Taxi > V;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i ) {
            cin >> x >> s >> y;
            V[i].begin = x * 60 + y; 
            cin >> V[i].a >> V[i].b >> V[i].c >> V[i].d;
            V[i].end = V[i].begin + 
                       abs( V[i].a - V[i].c ) + 
                       abs( V[i].b - V[i].d );
        }
        
        binmatch.init( N, N );
        
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                if( V[i].end + 
                    abs( V[j].a - V[i].c ) + 
                    abs( V[j].b - V[i].d ) < V[j].begin )
                    binmatch.insert( i, j );
                    
        binmatch.run();
        
        cout << N - binmatch.matchCnt() << endl;
        
    }
    
}
