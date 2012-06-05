#include <stdio.h>
#define MAX     50000

int     Len;
struct  TNode {
        int     left , right;
        int     minstep;
        TNode   *LeftChild , *RightChild;
        void    Construct ( int , int );
        void    Insert ( int , int );
        int     GetRank ( int , int );
}       STree [MAX * 3 + 2] , *Root = &STree [0];

int     N , M;

void    TNode :: Construct ( int l , int r )
{
        left = l; right = r; minstep = 999999;
        if ( l == r ) { LeftChild = NULL; RightChild = NULL; return; }
        int     mid = ( l + r ) >> 1;
        LeftChild = &STree [Len ++];
        RightChild = &STree [Len ++];
        LeftChild->Construct ( l , mid );
        RightChild->Construct( mid + 1 , r );
}

void    TNode :: Insert ( int p , int x )
{
        if ( x < minstep ) minstep = x;
        if ( left == right ) return;

        if ( p <= ( left + right ) >> 1 ) LeftChild->Insert( p , x );
                else RightChild->Insert( p , x );
}

int     TNode :: GetRank ( int l , int r )
{
        if ( l == left && r == right ) return minstep;
        int     mid = ( left + right ) >> 1;
        if ( r <= mid ) return LeftChild->GetRank( l , r );
        if ( l > mid ) return RightChild->GetRank( l , r );
        int     ret1 , ret2;
        ret1 = LeftChild->GetRank( l , mid );
        ret2 = RightChild->GetRank( mid + 1 , r );
        return ret1 < ret2 ? ret1 : ret2;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        int     i , a , b , p;
        while ( scanf ( "%d %d" , &N , &M ) != EOF ) {
                Len = 1; Root->Construct( 1 , N );

                Root->Insert ( 1 , 0 );

                for ( i = 0; i < M; i ++ ) {
                        scanf ( "%d%d" , &a , &b );
                        if ( a < b ) {
                                p = Root->GetRank ( a , b - 1 );
                                Root->Insert ( b , p + 1 );
                        }
                } 
                printf ( "%d\n" , Root->GetRank( N , N ) );
        }
}
 