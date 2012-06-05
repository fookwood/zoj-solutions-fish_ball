// 3036759 2008-08-15 16:32:38 Accepted 2747 C++ 00:00.34 2140K 呆滞的慢板 

//////////////////////////////////////////////////////
//                  线段树模板 v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// 1. SZ:           模板参数，线段树的最大规模;     //
// 2. init:         初始化线段树区域为未标记;       //
// 3. insert:       将某个线段涂色;                 //
// 4. getSeg:       获取所有线段;                   // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

#define Left( x )       ( x << 1 )
#define Right( x )      ( ( x << 1 ) + 1 )

struct Segment {
    int left, right, color;
    Segment( int l, int r, int c ) :
        left( l ), right( r ), color( c ) {}
};

template<int SZ>
class STree {

    enum { MIXED = -1, BLANK = INT_MAX };
    
    int     C[SZ*2],  L[SZ*2],  R[SZ*2];
    
    void create( int idx, int l, int r ) {
        L[idx] = l;
        R[idx] = r;
        C[idx] = BLANK;
        if( l == r - 1 ) return;
        int mid = l + r >> 1;
        if( l < mid )   create( Left( idx ),  l, mid );
        if( mid < r )   create( Right( idx ), mid, r );
    }
    
    void paint( int idx, int l, int r, int color ) {
        
        if( l == L[idx] && r == R[idx] ) { C[idx] = color; return; }
        
        int mid = L[idx] + R[idx] >> 1;

        if( C[idx] != MIXED ) {
            if( L[idx] < l )
                paint( Left( idx ), L[idx], min( l, mid ), C[idx] );
            if( mid < l )
                paint( Right( idx ), mid, l, C[idx] );
            if( r < R[idx] )
                paint( Right( idx ), max( mid, r ), R[idx], C[idx] );
            if( r < mid )
                paint( Left( idx ), r, mid, C[idx] );
        }

        if( l < mid )   paint( Left( idx ), l, min( mid, r ), color );
        if( r > mid )   paint( Right( idx ), max( mid, l ), r, color );

        C[idx] = C[Left( idx )] == C[Right( idx )] ?
            C[Left( idx )] : MIXED;
        
    }
    
    void traversal( vector<Segment>& stk, int idx ) {
        
        if( C[idx] == BLANK ) return;
        
        if( C[idx] == MIXED ) {
            traversal( stk, Left( idx ) );
            traversal( stk, Right( idx ) );
            return;
        }
        
        if( stk.empty() || stk.back().color != C[idx] || stk.back().right != L[idx] )
                stk.push_back( Segment( L[idx], R[idx], C[idx] ) );
        else    stk.back().right = R[idx];
        
    }

public:

    void init( int sz, int l = 0 ) {
        C[1] = BLANK;
        create( 1, l, l + sz );
    }
    
    void insert( int l, int r, int color ) { paint( 1, l, r, color ); }
    
    vector<Segment> getSeg() {
        vector<Segment> ans;
        traversal( ans, 1 );
        return  ans;
    }

};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////



int     W[10001],   H[10001];

STree<256>  C[200];

int     A[101],     MW[200],    MH[200];

vector<Segment> ans;

struct Rectangle {
    int r1, c1, r2, c2, clr;
    void get() {
        r1, c1, r2, c2, clr;
        scanf( "%d%d%d%d%d", 
            &r1, &c1, &r2, &c2, &clr );
    }
} R[100];

int     N,  X,  Y,  K,  L,  S,  T = 0;

int main() {
    
    while( scanf( "%d%d", &X, &Y ) && ( X || Y ) ) {
        
        if( T++ )   puts( "" );
        
        printf( "Case %d:\n", T );
        
        memset( W, -1, sizeof( W ) );
        memset( H, -1, sizeof( H ) );
        
        cin >> N;
        for( int i = 0; i < N; ++i ) {
            R[i].get();
            R[i].r1 <?= X;
            R[i].r2 <?= X;
            R[i].c1 <?= Y;
            R[i].c2 <?= Y;
            W[R[i].r1] = W[R[i].r2] =
            H[R[i].c1] = H[R[i].c2] = 0;
        }
        
        for( int i = K = 0; i <= X; ++i )
            if( !W[i] ) MW[W[i] = K++] = i;
        
        for( int i = L = 0; i <= Y; ++i )
            if( !H[i] ) MH[H[i] = L++] = i;
        
        for( int i = 0; i < K; ++i )
            C[i].init( L );
        
        for( int n = 0; n < N; ++n )
            for( int i = W[R[n].r1]; i < W[R[n].r2]; ++i )
                C[i].insert( H[R[n].c1], H[R[n].c2], R[n].clr ); 
                    
        memset( A, 0, sizeof( A ) );
        for( int i = 0; i < K; ++i ) {
            ans = C[i].getSeg();
            for( int j = 0; j < ans.size(); ++j ) {
                A[ans[j].color] += 
                    ( MW[i+1] - MW[i] ) *
                    ( MH[ans[j].right] - MH[ans[j].left] );
            }
        }
        
        for( int i = S = 0; i < 101; ++i ) {
            if( A[i] ) {
                ++S;
                printf( "%d %d\n", i, A[i] );
            }
        }
        
        if( S > 1 ) printf( "There are %d colors left on the wall.\n", S );
        else        printf( "There is 1 color left on the wall.\n" );
        
    }
    
}
