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


#include <bitset>
#include <iostream>
using namespace std;

int N = 0, buf[30000];

char * str = "0123456789abcdefghijklmnopqrstuvwxyz";

bitset<36> tb[256];
    
void decrypt() {
    bitset<36> prob[30];
    for(int len = 1, rem; len <= 30; ++len) {
        for(rem = 0; rem < len; ++rem) {
            bitset<36> mask;
            mask.set();
            for(int j = rem; mask.any() && j < N; j += len) {
                mask &= tb[buf[j]];
            }
            if(!mask.any()) break;
            prob[rem] = mask;
        }
        if(rem == len) {
            BinMatch bm;
            bm.init(len, 36);
            for(int i = 0; i < len; ++i) {
                for(int j = 0; j < 36; ++j) {
                    if(prob[i][j]) {
                        bm.insert(i, j);
                    }
                }
            }
            bm.run();
            if(bm.matchCnt() != len) continue;
            vector<pair<int, int> > ans = bm.getMatch();
            for(int i = 0; i < N; ++i) {
                putchar(str[ans[i % len].second] ^ buf[i]);
            }
            break;
        }
    }
}

int main() {
    
    for(int code = 0; code < 256; ++code) {
        tb[code].reset();
        for(int i = 0; i < 36; ++i) {
            char after = ((char)code) ^ str[i];
            if(isalpha(after) || after == ' ')
                tb[code].set(i);
        }
    }

    for(int t= 0; t < 4; ++t) {
        for(int N = 0; N < 30000; ++N) {
            if(scanf("%d", buf + N) != 1) while(1) puts("fuck!!");
        }
        decrypt();
    }
    
}
