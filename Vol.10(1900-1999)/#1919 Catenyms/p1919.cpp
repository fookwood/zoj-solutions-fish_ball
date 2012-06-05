// 2968788 2008-07-09 21:42:23 Accepted 1919 C++ 00:00.08 972K 呆滞的慢板 

// 产生有向图的欧拉路径，相当 BT + XE 
// 注意自环和平行边的处理 
// 另外还要仔细地考虑如何让得到的路径字典序最小
// *&^%#^%$ 妈的，这字典序太 xe 了，Special Judge 多好啊...555.. 

#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
using namespace std;

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



// 邻接矩阵表示，每个节点存放所有边 
vector<string>  G[26]; 
// path 是获取的欧拉路径，trace 是递归时的路径 
vector<string>  path,   trace; 
// ....
int         T,  N; 
// 顶点的出入度 
int         IN[26], OUT[26]; 
// 并查集（判连通） 
Union<26>   U; 


// 获取欧拉路径 
void Tour( int v ) {
    
    while( G[v].size() ) {
        trace.push_back( G[v].back() );
        G[v].pop_back(); 
        Tour( trace.back()[trace.back().size() - 1] - 'a' );
        path.push_back( trace.back() );
        trace.pop_back(); 
    }
    
} 

int main() {
    
    for( cin >> T; T--; ) {
      
        U.init( 26 ); 
        
        for( int i = 0; i < 26; ++i ) {
            G[i].clear(); 
            IN[i] = OUT[i] = 0; 
        }

        for( cin >> N; N--; ) {
            string  input;
            cin >> input;
            int x = input[0] - 'a',
                y = input[input.size() - 1] - 'a';
            IN[x]++;
            OUT[y]++; 
            U.merge( x, y );
            G[x].push_back( input );
        } 

        bool    yes = true;
        int     V = 0,  cnt = 0;
        int     begin_pos = 0; 
        for( int i = 0; i <26; ++i ) {
            V += IN[i] || OUT[i]; 
            if( IN[i] == OUT[i] )
                continue;
            if( IN[i] - OUT[i] > 1 ||
                IN[i] - OUT[i] < -1 ) {
                yes = false;
                break;
            } 
            ++cnt;
            if( IN[i] - OUT[i] == 1 )
                begin_pos = i; 
        }

        // 有两个以上奇度点或者
        // 有不平衡点(出入度相差 1 以上) 或者 
        // 不连通，都判为无欧拉路径 
        if( cnt > 2 || !yes || U.getSets() + V != 27 ) {
            puts( "***" );
            continue; 
        }

        // 下面已经确认有欧拉路径，开始寻路 
        path.clear();
        trace.clear(); 

        // 保证字典序
        for( int i = 0; i < 26; ++i )
            if( G[i].size() > 1 )
                sort( G[i].begin(), G[i].end(), greater<string>() );

        // 注意如果有一个点 入度 = 出度 + 1
        // 必须从这个点开始周游 
        if( begin_pos == 0 )
            while( !IN[begin_pos] && !OUT[begin_pos] )
                ++begin_pos; 
        Tour( begin_pos );

        cout << path.back();
        path.pop_back(); 
        while( path.size() ) {
            cout << '.' << path.back();
            path.pop_back(); 
        }

        cout << endl; 
        
    } 
    
} 
