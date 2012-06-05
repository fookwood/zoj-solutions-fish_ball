// 2972159 2008-07-11 18:05:01 Accepted 1311 C++ 00:00.15 896K 呆滞的慢板 

// 割顶，求割顶的个数，搞了好久，我太肤浅了
// 本来不会这样的，抄书的程序的时候想当然了，囫囵吞枣，舍本逐末，活该！！

// 更郁闷的是这个错误的 DFS 居然把割边的题给过了的
// 现在回去掘墓鞭尸...唯有如此...

// 下面是个典故，留在这里激励自己... 

/*                              造酒忘米
                                明.江盈科 

    一人问造酒之法于酒家。酒家曰：“一斗米，一两曲，加二斗水，相参和，
酿七日，便成酒。”其人善忘，归而用水二斗，曲一两，相参和，七日而尝之，
犹水也，乃往诮酒家，谓不传与真法。酒家曰：“尔第不循我法也。”其人曰：
“我循尔法，用二斗水，一两曲。”酒家曰：“可有米么？”其人俯首思曰：
“是我忘记下米！。” 
    噫！并酒之本而忘之，欲求酒，及于不得酒，而反怒怨教之者之非也。
世之学者，忘本逐末，而学不成，何异于是！ */

#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool    V[101][101]; 

int     N;

int     dph, cnt;   // DFS 次序，割点总数 
int     ord[101];   // 顶点的遍历序 
int     low[101];   // 顶点的子树中回边指向的最低序 
int     pre[101];   // 顶点的 DFS 树祖先 
int     tre[101];   // 顶点向下树边数 
int     ans[101];   // 是否割点 

void DFS( int v ) {
    
    low[v] = ord[v] = dph++;
    
    for( int w = 1; w <= N; ++w ) if( V[v][w] ) {
        
        // 树边 
        if( ord[w] == -1 ) {
            pre[w] = v;
            tre[v]++;
            DFS( w );
            if( low[v] > low[w] )
                low[v] = low[w];
            if( low[w] >= ord[v] )
                ans[v] = 1;
        }
        // 非父边，即为回边或下边 
        else if( w != pre[v] ) {
            if( low[v] > ord[w] )
                low[v] = ord[w];
        }
    }
    
}


int main() {
    
    string  input;
    
    while( cin >> N && N ) {

        // 建图 
        memset( V, 0, sizeof( V ) );
        
        int x,  y;
        
        while( cin >> x && x ) {
            getline( cin, input );
            istringstream   is( input );
            while( is >> y ) 
                V[x][y] = V[y][x] = true; 
        }
        
        // 初始化
        dph = 0,    cnt = 0;
        memset( ord, -1, sizeof( ord ) );
        memset( low, -1, sizeof( low ) );
        memset( pre, -1, sizeof( pre ) );
        memset( tre,  0, sizeof( tre ) );
        memset( ans,  0, sizeof( ans ) );
        
        DFS( 1 );
        
        ans[1] = tre[1] > 1; 
        for( int i = 1; i <= N; ++i )
            cnt += ans[i];
        
        // 状态调试标记 
        #ifndef ONLINE_JUDGE
        cout << "seq: ";for( int i = 1; i <= N; ++i ) printf( "%3d", i );       puts(""); 
        cout << "ord: ";for( int i = 1; i <= N; ++i ) printf( "%3d", ord[i] );  puts("");
        cout << "low: ";for( int i = 1; i <= N; ++i ) printf( "%3d", low[i] );  puts("");
        cout << "pre: ";for( int i = 1; i <= N; ++i ) printf( "%3d", pre[i] );  puts("");
        cout << "tre: ";for( int i = 1; i <= N; ++i ) printf( "%3d", tre[i] );  puts("");
        cout << "ans: ";for( int i = 1; i <= N; ++i ) printf( "%3d", ans[i] );  puts("");
        #endif 
        
        cout << cnt << endl; 

    }
    
}
