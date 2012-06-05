// 3027329 2008-08-08 00:34:04 Accepted 1364 C++ 00:00.03 852K 呆滞的慢板 

// 最小覆盖点集 Konig 定理 

// 注意读题，At the beginning they are both work at mode_0. 

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
using namespace std;

int     U,  V,  E;

BinMatch    binmatch; 

int main() {
    
    while( cin >> U && U ) {
        
        cin >> V >> E; 
        
        binmatch.init( U, V );
        
        while( E-- ) {
            
            int x,  y;
            
            cin >> x >> x >> y;
            
            if( x && y )
                binmatch.insert( x, y );
             
        } 
        
        binmatch.run();
        
        cout << binmatch.matchCnt() << endl;
        
    } 
    
}
