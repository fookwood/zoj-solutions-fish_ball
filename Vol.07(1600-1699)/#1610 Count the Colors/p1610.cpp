// 3032149 2008-08-12 16:20:14 Accepted 1610 C++ 00:00.25 1088K 呆滞的慢板 

// 基础线段树 

#define Assert1( x )    { if( !(x) ) while( 1 ); }                 // TLE 
#define Assert2( x )    { if( !(x) ) while( 1 ) new int[1000]; }   // MLE 
#define Assert3( x )    { if( !(x) ) while( 1 ) *(int*)NULL = 1; } // RTE SIGSEGV 
#define Assert4( x )    { if( !(x) ) while( 1 ) puts( "OLE" ); }   // OLE 
#define Assert5( x )    { if( !(x) ) printf( "%d", 1 / 0 ); }      // RTE SIGFPE 
#define Assert6( x )    { if( !(x) ) system( "pause" ); }          // RF 


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
    void disp() { printf( "[%2d,%2d): %d\n", left, right, color ); }
};

template<int SZ>
class STree {
    
public:

    enum { MIXED = -1, BLANK = INT_MAX };
    
    int     C[SZ],  L[SZ],  R[SZ];
    
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
    
    void traversal( vector<Segment>& stk, int idx ) const {
        
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
    
    vector<Segment> getSeg() const {
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

STree<20000>   stree;
    
int     N,  x,  y,  c; 

map<int, int>   M;

void disp( pair<int, int> p ) { printf( "%d %d\n", p.first, p.second ); }
    
int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        stree.init( 8000 );
        
        while( N-- ) {
            scanf( "%d%d%d", &x, &y, &c );
            stree.insert( x, y, c );
        }

        vector<Segment>  V = stree.getSeg();
    
        M.clear();
        
        for( int i = 0; i < V.size(); ++i )
            ++M[V[i].color];
        
        for_each( M.begin(), M.end(), disp );
        
        puts( "" ); 
        
    }
    
}
