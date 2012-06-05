// 3046403 2008-08-22 21:43:34 Accepted 1508 C++ 00:00.58 1620K 呆滞的慢板 

// 典型差分约束系统，我做的第一道差分约束的题目

// 注意要将差分约束的所有约束分析进才开始动手，否则会招致无尽 WA 

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v( v ), w( w ), l( l ) {}
    void get() { scanf( "%d%d%d", &v, &w, &l ); }
};

Edge    E[50001];

int     D[50001],   N,  mx, mn;

int bellman_ford() {
    
    memset( D, 0, sizeof( D ) );
    
    for( int i = mn; i < mx; ++i ) {
        bool  quit = true;
        for( int j = mn; j < mx; ++j  )
            if( D[j+1] > D[j] ) { quit = false; D[j+1] = D[j]; }
        for( int j = mx; j > mn; --j  )
            if( D[j-1] - D[j] > 1 ) { quit = false; D[j-1] = D[j] + 1; }
        for( int j = 0; j < N; ++j )
            if( D[E[j].w] > D[E[j].v] - E[j].l )
                { D[E[j].w] = D[E[j].v] - E[j].l; quit = false; }
        if( quit )  break;
    }
    
    return  -D[mx];
    
}

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
    
        mx = INT_MIN;
        mn = INT_MAX;
        for( int i = 0; i < N; ++i ) {
            E[i].get();
            E[i].w += 1;
            mx >?= E[i].w;
            mn <?= E[i].v;
        }

        printf( "%d\n", bellman_ford() );

    }
    
}
