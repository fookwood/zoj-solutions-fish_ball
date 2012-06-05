// 中等偏难的哈密顿路径，蛮搞... TLE

#include <cstdio>
#include <cstring>

////////////////////////////////////////////////////
//                 并查集模板 v1.1                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ:      并查集最大元素总数(模板参数);     //
//  2. init:    初始化 N 各元素的并查集;          //
//  3. check:   检查两个元素是否共集，并合并之;   //
//  4. getSets: 返回并查集的子集个数;             //
//  5. single:  检查一个点是否孤立;               // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class Union {
    int elem,   subSets;
    int* U;
    bool* B; 
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ+1]; B = new bool[SZ+1]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    bool single( const int& v ) { return !B[v]; } 
    int getSets() const { return subSets; }
    ~Union() { delete [] U; delete [] B; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 0; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
    B[x] = B[y] = true; 
    int p = x, q = y, r = y;
    while( U[p] != p ) p = U[p];
    while( U[q] != q ) q = U[q];
    if( p == q ) return true;
    U[q] = p;
    while( U[r] != p ) {
        q = U[r];
        U[r] = p;
        r = q;
    }
    subSets--;
    return  false;
}

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////



// case 数，顶点数，边数 
int     T,  N,  M;

// 顶点权值 
int     V[14];

// 最大计数，当前权值，最大权值 
int     cnt, wgt, mx;

// 在此采用双重图表示 
// 邻接表用于图搜索 
int     G1[14][14];
// 邻接矩阵用于边查询 
bool    G2[14][14];

// 已访问标记 
bool    B[14];
int     trace[14]; 
 
// 并查集(判连通前置剪枝)
Union<14>   U; 

void Hamilton( int v, int s ) {
    
    // 搜索到哈密顿路径 
    if( s == 1 ) {
        // 读取该路径的权值 
        wgt = 0;
        for( int i = 1; i <= N; ++i ) {
//cout << trace[i] << ' '; 
            // 第一项，顶点权 
            wgt += V[trace[i]];
            // 第二项，边权 
            if( i + 1 <= N )
                wgt += ( V[trace[i]] * V[trace[i+1]] ); 
            // 第三项，环路权
            if( i + 2 <= N &&
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
    for( int i = 1; i <= G1[v][0]; ++i ) {
        if( !B[G1[v][i]] ) {
            B[G1[v][i]] = true;
            trace[trace[0]++] = G1[v][i];
            Hamilton( G1[v][i], s - 1 );
            --trace[0];
            B[G1[v][i]] = false;
        }
    }
    
} 


int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        // 建图 
        scanf( "%d%d", &N, &M );
        
        U.init( N ); 
        
        for( int i = 1; i <= N; ++i ) {
            scanf( "%d", V + i );
            G1[i][0] = 1;
            memset( G2[i], 0, sizeof( G2[i] ) ); 
        }
        
        if( N == 1 ) { printf( "%d 1\n", V[1] ); continue; }
        
        for( int i = 1; i <= M; ++i ) {
            int x,  y;
            scanf( "%d%d", &x, &y );
            U.merge( x, y ); 
            G1[x][G1[x][0]++] = y;
            G1[y][G1[y][0]++] = x;
            G2[x][y] = G2[y][x] = true;
        }
        
        // 如果不连通，剪掉
        if( U.getSets() != 1 ) {
            puts( "0 0" );
            continue; 
        }
        
        // 开始哈密顿搜索，以所有顶点为起点做一次 
        cnt = mx = 0;
        for( int pos = 1; pos <= N; ++pos ) { 
            
            // 初始化
            trace[0] = 1; 
            memset( B, 0, sizeof( B ) );
        
            // DFS
            trace[trace[0]++] = pos; 
            B[pos] = true; 
            Hamilton( pos, N );
            
        }
        
        // 结果，注意同一条哈密顿路径会被计算了两次 
        printf( "%d %d\n", mx, cnt / 2 ); 
         
    }
    
}
 
