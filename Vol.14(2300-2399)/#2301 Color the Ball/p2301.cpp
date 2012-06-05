// 3033163 2008-08-13 11:00:55 Accepted 2301 C++ 00:00.13 1028K 呆滞的慢板 

// 离散化 + 线段树 

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
    Segment() {} 
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


#include <map> 
using namespace std; 

int     N;

STree<4000>    stree; 

vector<Segment> S; 

map<int, int>   M;
vector<int>     L; 

int main() {

    while( cin >> N ) {
        
        S.resize( N ); 
        M.clear(); 
        L.clear(); 
        
        for( int i = 0; i < N; ++i ) {
            int     x,  y;
            char    c; 
            cin >> x >> y >> c;
            S[i].left = x;
            S[i].right = y + 1;
            S[i].color = c == 'w';
            M[S[i].left] = M[S[i].right] = 0; 
        }
        
        for( map<int, int>::iterator it = M.begin();
            it != M.end(); ++it ) {
            it -> second = L.size();
            L.push_back( it -> first ); 
        }
        
        stree.init( L.size() ); 
        for( int i = 0; i < N; ++i )
            stree.insert( M[S[i].left], M[S[i].right], S[i].color );
        
        S = stree.getSeg();
        
        for( int i = 1; i < S.size(); ++i ) {
            if( S[i].color == 1 ) {
                int l1 = L[S[i].right] - L[S[i].left];
                int l2 = L[S[0].right] - L[S[0].left];
                if( S.front().color == 0 || l2 < l1 )
                    S.front() = S[i];
            } 
        } 
        
        if( S.front().color == 1 )
            cout << L[S.front().left] << ' '
                 << L[S.front().right] - 1 << endl;
        else
            puts( "Oh, my god" );
        
    } 

}
