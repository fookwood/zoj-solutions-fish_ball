// 3026271 2008-08-07 11:53:13 Accepted 1059 C++ 00:00.03 872K 呆滞的慢板 

// 求完美匹配，难度在于建图的处理，参考引用的解题报告 

// 至于其后的完美匹配，可以先匹配然后检查边，也可以贪心 

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
        return  ans;
    }

}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int T,  ID_cnt,  NAME_cnt;

string  ID[20], NAME[20];
map<string, int>    ID_idx, NAME_idx;

bitset<20>  inside, matrix[40];

BinMatch    binmatch;

int addName( string name ) {
    if( NAME_idx.find( name ) == NAME_idx.end() ) {
        NAME[NAME_cnt] = name;
        return  NAME_idx[name] = NAME_cnt++;
    }
    return  NAME_idx[name];
}

int addID( string id ) {
    if( ID_idx.find( id ) == ID_idx.end() ) {
        ID[ID_cnt] = id;
        return  ID_idx[id] = ID_cnt++;
    }
    return  ID_idx[id];
}

int main() {

    for( cin >> T; T--; ) {
        
        ID_cnt = 0;
        ID_idx.clear();
        
        int N;  cin >> N;
        for( int i = 0; i < N; ++i ) {
            string  input;
            cin >> input;
            addID( input );
        }
        
        NAME_cnt = 0;
        NAME_idx.clear();
        
        for( int i = 0; i < 40; ++i )
            matrix[i].set();
        
        inside.reset();
        
        char    c;
        while( cin >> c && c != 'Q' ) {
            string input;  cin >> input;
            switch( c ) {
                case 'E': inside.set( addName(input) );     break;
                case 'L': inside.reset( addName(input) );   break;
                case 'M': matrix[addID(input)] &= inside;   break;
            }
        }
        
        binmatch.init( NAME_cnt, ID_cnt );
        
        for( int j = 0; j < ID_cnt; ++j )
            for( int i = 0; i < NAME_cnt; ++i )
                if( matrix[j][i] )
                    binmatch.insert( i, j );

        binmatch.runPerfect();
        
        vector<pair<int, int> > P = binmatch.getMatch();
        
        vector<string>  match( NAME_cnt, "???" ); 
            
        for( int i = 0; i < P.size(); ++i )
            match[P[i].first] = ID[P[i].second];
        
        for( int i = 0; i < NAME_cnt; ++i )
            match[i] = ( NAME[i] + ":" + match[i] );
            
        sort( match.begin(), match.end() );
        
        for( int i = 0; i < match.size(); ++i )
            cout << match[i] << endl;
        
        if( T ) puts( "" );
        
    }

}
