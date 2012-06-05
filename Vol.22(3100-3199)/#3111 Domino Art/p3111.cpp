// 1842156 2009-04-23 16:59:46 Accepted  3111 C++ 90 184 呆滞的慢板 

// 求多米诺骨牌能否铺成二维网格内的某个图案，可归约成二分匹配。
// 匹配的两个顶点集为要填的奇数格和偶数格，如果两个格子相邻，那么存在条边。
// 如果两个集合等大且匹配是满的，那么结果就是可能的，反之亦然。 

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
using namespace std;

int main() {
    BinMatch bm;
    int M, N;
    char G[60][61];
    int T = 1;
    while(cin >> M >> N && M) {
        for(int i = 0; i < M; ++i)
            cin >> G[i];
        cout << "Case " << T++ << ": ";
        vector<int> h, g;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(G[i][j] == '#') {
                    if(i + j & 1) h.push_back(i * N + j);
                    else g.push_back(i * N + j);
                }
            }
        }
        if(h.size() != g.size()) { puts("Impossible"); continue; }
        bm.init(h.size(), g.size());
        for(int i = 0; i < h.size(); ++i) {
            for(int j = 0; j < g.size(); ++j) {
                int xh = h[i] % N, yh = h[i] / N; 
                int xg = g[j] % N, yg = g[j] / N; 
                if(xh == xg && (yh - yg == 1 || yh - yg == -1) ||
                   yh == yg && (xh - xg == 1 || xh - xg == -1))
                   bm.insert(i, j);
            }
        }
        bm.run();
        puts(bm.matchCnt() == h.size() ? "Possible" : "Impossible");
    }
}
