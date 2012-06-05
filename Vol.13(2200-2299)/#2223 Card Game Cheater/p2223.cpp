// 3023917 2008-08-06 02:05:28 Accepted 2223 C++ 00:00.00 852K 呆滞的慢板 

// 找最大二分匹配 

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
#include <string>
using namespace std;

int P[128];

struct Card {
    char    C[3];
};

istream& operator >> ( istream& is, Card& card ) {
    return  is >> card.C;
}

inline bool operator < ( Card a, Card b ) {
    return  P[a.C[0]]+P[a.C[1]] < P[b.C[0]]+P[b.C[1]];
}

BinMatch    binmatch;

int     T,  N;

Card    adam[26],   eve[26];

int main() {
    
    for( char i = '2'; i <= '9'; ++i )
        P[i] = ( i - '0' ) * 10;
        
    P['T'] = 100;   P['J'] = 110;
    P['Q'] = 120;   P['K'] = 130;   P['A'] = 140; 
    P['C'] = 1;     P['D'] = 2;
    P['S'] = 3;     P['H'] = 4;
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        binmatch.init( N, N );
        
        for( int i = 0; i < N; ++i )
            cin >> adam[i];
            
        for( int i = 0; i < N; ++i )
            cin >> eve[i];
            
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                if( adam[i] < eve[j] ) 
                    binmatch.insert( i, j );
                    
        binmatch.run();
        
        cout << binmatch.matchCnt() << endl;
        
    }
    
}
