// Segment Tree
#define NoColor -1
#define MulColor -2

#include <stdio.h>
#include <string.h>

int     Len;
struct  TNode {
        int     left , right;
        int     col;
        TNode   *LeftChild , *RightChild;
        void    Construct ( int , int );
        void    Insert ( int , int , int );
        void    Calculate ();
} Tree [16000] , *Root = &Tree [0];

int     CalColor [8001] , Many [8001];

void    TNode :: Construct ( int l , int r )
{
        left = l; right = r;
        if ( l + 1 == r ) { LeftChild = NULL; RightChild = NULL; return; }

        int     mid = ( l + r ) >> 1;
        LeftChild = &Tree [Len ++];
        RightChild = &Tree [Len ++];
        LeftChild->Construct( l , mid );
        RightChild->Construct( mid , r );
}

void    TNode :: Insert ( int l , int r , int c )
{
        if ( col == c ) return;
        if ( l == left && r == right ) { col = c; return; }
        int     mid = ( left + right ) >> 1;
        if ( col != MulColor ) { LeftChild -> col = col; RightChild -> col = col; }
        col = MulColor;
        if ( r <= mid ) { LeftChild -> Insert ( l , r , c ); return; }
        if ( l >= mid ) { RightChild -> Insert ( l , r , c ); return; }
        LeftChild -> Insert ( l , mid , c );
        RightChild -> Insert ( mid , r , c );
}

void    TNode :: Calculate ()
{
        if ( col != MulColor && col != NoColor ) {
                int     i;
                for ( i = left; i < right; i ++ ) CalColor [i] = col;
        }
        if ( col == MulColor ) { LeftChild -> Calculate (); RightChild -> Calculate (); }
}

main ()
{
        int     Total , a , b , c , i , t;
        Len = 1; Tree [0].Construct( 0 , 8000 );

//        printf ( "After Construct the Tree , Len = %d\n" , Len );

        while ( scanf ( "%d" , &Total ) != EOF ) {
                Tree [0].col = NoColor;
                while ( Total ) {
                        scanf ( "%d %d %d" , &a , &b , &c );
                        Root -> Insert( a , b , c );
                        Total --;
                }
                memset ( CalColor , 0xff , sizeof ( CalColor ) );
                memset ( Many , 0 , sizeof ( Many ));
                Root -> Calculate ();

                t = -1;
                for ( i = 0; i <= 8000; i ++ ) {
                        if ( CalColor [i] == t ) continue;
                        t = CalColor [i];
                        if ( t != -1 ) Many [t] ++;
                }
                for ( i = 0; i <= 8000; i ++ ) if ( Many [i] )
                        printf ( "%d %d\n" , i , Many [i] );

                printf ( "\n" );
        }
        
}
 