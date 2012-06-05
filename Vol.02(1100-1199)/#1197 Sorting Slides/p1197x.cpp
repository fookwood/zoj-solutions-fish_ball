// 3025812 2008-08-07 01:22:10 Accepted 1197 C++ 00:00.01 860K 呆滞的慢板 

// 模板集成完美匹配功能 

// 找完美匹配，先找一个普通匹配，然后要求完全匹配 

// 然后遍历各个匹配边，依次删除该边，重新匹配 
// 如果删掉之后匹配数不发生改变，则匹配不惟一 

// 此题要求完美匹配，求有几个完美的匹配就输出几个... 
// 因此，在检验的时候，如果条件不符，要相应地删除该匹配边... 


//////////////////////////////////////////////////////////
//          二分匹配算法类模板（邻接矩阵实现） v1.3     //
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
// 1.2 新增邻接矩阵版本，具备删边功能;                  //
// 1.3 新增完美匹配功能;                                // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;
 
class BinMatch {
    
    int     X,  Y,  M; 
    vector<vector<bool> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int w = 0; w <= Y; ++w ) {
            if( G[v][w] && !mark[w] ) {
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
        G.assign( X + 1, vector<bool>( Y + 1, false ) );
    } 
    
    void insert( int v, int w ) { G[v][w] = true; }
    
    void erase( int v, int w ) { G[v][w] = false; }
    
    void run() {
        back.assign( Y + 1, -1 );
        for( int v = M = 0; v <= X; ++v ) {
            mark.assign( Y + 1, false ); 
            M += find( v );
        }
    } 
    
    int matchCnt() const { return M; }
    
    void runPerfect() {
        run();
        vector<int> old_match = back; 
        int         old_matchs = M; 
        vector<int> exclude;
        for( int i = 0; i <= Y; ++i ) {
            if( old_match[i] != -1 ) {
                G[old_match[i]][i] = false;
                run();
                G[old_match[i]][i] = true;
                if( M == old_matchs )
                    exclude.push_back( i ); 
            } 
        } 
        for( int i = 0; i < exclude.size(); ++i )
            old_match[exclude[i]] = -1;
        back = old_match;
    } 
    
    vector<pair<int, int> > getMatch() const {
        vector<pair<int, int> > ans;
        for( int i = 0; i < Y; ++i )
            if( back[i] != -1 )
                 ans.push_back( make_pair( back[i], i ) );
        sort( ans.begin(), ans.end() );
        return  ans;
    }
    
    
}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

BinMatch    binmatch; 

struct  Rectangle {
    int     x1, x2, y1, y2;
    void get() { cin >> x1 >> x2 >> y1 >> y2; }
    bool inside( int x, int y ) const {
        return  x >= x1 && x <= x2 &&
                y >= y1 && y <= y2;
    }
};

int     T = 1,  N,  x,  y;

vector<Rectangle>   V; 

vector<pair<int, int> > P;

int main() {
    
    while( cin >> N && N ) {
        
        binmatch.init( N, N );
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i )
            V[i].get();
            
        for( int i = 0; i < N; ++i ) {
            cin >> x >> y;
            for( int j = 0; j < N; ++j )
                if( V[j].inside( x, y ) )
                    binmatch.insert( j, i );
        }
        
        binmatch.runPerfect();

        cout << "Heap " << T++ << endl;

        P = binmatch.getMatch();

        if( P.size() == 0 ) {
            puts( "none\n" );
            continue;
        }
        
        for( int i = 0; i < P.size(); ++i ) {
            if( i ) putchar( ' ' );
            printf( "(%c,%d)", char( P[i].first + 'A' ), P[i].second + 1 );
        }
        puts( "\n" );
        
    }
    
}
