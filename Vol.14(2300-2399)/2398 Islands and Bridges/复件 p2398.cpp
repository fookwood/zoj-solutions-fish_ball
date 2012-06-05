// 中等偏难的哈密顿路径，蛮搞... TLE

#include <iostream>
#include <vector>
using namespace std;

// case 数，顶点数，边数 
int     T,  N,  M;

// 顶点权值 
int     V[14];

// 最大计数，当前权值，最大权值 
int     cnt, wgt, mx;

// 在此采用双重图表示 
// 邻接表用于图搜索 
vector<int> G1[14];
// 邻接矩阵用于边查询 
bool        G2[14][14];

// 已访问标记 
bool    B[14];
vector<int> trace; 
 

void Hamilton( int v, int s ) {
    
    // 搜索到哈密顿路径 
    if( s == 1 ) {
        // 读取该路径的权值 
        for( int i = wgt = 0; i < N; ++i ) {
//cout << trace[i] << ' '; 
            // 第一项，顶点权 
            wgt += V[trace[i]];
            // 第二项，边权 
            if( i + 1 < N )
                wgt += ( V[trace[i]] * V[trace[i+1]] ); 
            // 第三项，环路权
            if( i + 2 < N &&
                G2[trace[i]][trace[i+2]] ) {
                wgt += V[trace[i]] * 
                       V[trace[i+1]] *
                       V[trace[i+2]];
            }
        }
//cout << "  " << wgt << endl; 
        if( wgt == mx ) ++cnt;
        else if( wgt > mx ) {
            mx = wgt;
            cnt = 1; 
        }
        return; 
    }
    
    // 深溯(树边) 
    for( int i = 0; i < G1[v].size(); ++i ) {
        if( !B[G1[v][i]] ) {
            B[G1[v][i]] = true;
            trace.push_back( G1[v][i] );
            Hamilton( G1[v][i], s - 1 );
            trace.pop_back();
            B[G1[v][i]] = false;
        }
    }
    
} 


int main() {
    
    for( cin >> T; T--; ) {
        
        // 建图 
        cin >> N >> M;
        
        for( int i = 1; i <= N; ++i ) {
            cin >> V[i];
            G1[i].clear();
            memset( G2[i], 0, sizeof( G2[i] ) ); 
        }
        
        if( N == 1 ) { cout << V[1] << 1 << endl; continue; }
        
        for( int i = 1; i <= M; ++i ) {
            int x,  y;
            cin >> x >> y;
            G1[x].push_back( y );
            G1[y].push_back( x );
            G2[x][y] = G2[y][x] = true;
        }
        
        // 开始哈密顿搜索，以所有顶点为起点做一次 
        cnt = mx = 0;
        for( int pos = 1; pos <= N; ++pos ) { 
            
            // 初始化
            trace.clear(); 
            memset( B, 0, sizeof( B ) );
        
            // DFS
            trace.push_back( pos ); 
            B[pos] = true; 
            Hamilton( pos, N );
            
        }
        
        // 结果，注意同一条哈密顿路径会被计算了两次 
        cout << mx << ' ' << cnt / 2 << endl; 
         
    }
    
}
 
