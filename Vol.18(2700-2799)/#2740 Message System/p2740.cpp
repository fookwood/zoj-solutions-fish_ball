// 2937833 2008-05-31 00:05:43 Accepted 2740 C++ 00:00.06 844K 呆滞的慢板 

// 判定一个图是不是树，直接并查集即可 

#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////
//                 并查集模板 v1.0                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ: 并查集最大元素总数(模板参数);          //
//  2. init:  初始化 N 各元素的并查集;            //
//  3. check: 检查两个元素是否共集，并合并之;     //
//  4. getSets: 返回并查集的子集个数;             //
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class Union {
    int elem,   subSets;
    int* U;
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    int getSets() const { return subSets; }
    ~Union() { delete [] U; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 1; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
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

int main() {
    
    int             M,  N,  X,  Y;
    Union<1001>     U;
    
    while( cin >> M >> N && M ) {
        
        bool    isTree = M == N + 1;
        
        U.init( M );
        
        while( N-- ) {
            cin >> X >> Y;
            if( U.merge( X, Y ) )
                isTree = false;
        }
        
        puts( isTree ? "Yes" : "No" );
        
    }
    
    
}
