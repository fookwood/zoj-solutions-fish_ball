#include <stdio.h>

#define MAXN 40000

int     R , Len , S , T , N , Q;

struct  TMatrix {
        int s [2] [2];
        TMatrix () { s [0] [0] = s [1] [1] = 1; s [0] [1] = s [1] [0] = 0; }
        TMatrix operator * ( const TMatrix & B ) const {
                TMatrix Ret;
                Ret.s [0] [0] = ( s [0] [0] * B.s [0] [0] + s [0] [1] * B.s [1] [0] ) % R;
                Ret.s [0] [1] = ( s [0] [0] * B.s [0] [1] + s [0] [1] * B.s [1] [1] ) % R;
                Ret.s [1] [0] = ( s [1] [0] * B.s [0] [0] + s [1] [1] * B.s [1] [0] ) % R;
                Ret.s [1] [1] = ( s [1] [0] * B.s [0] [1] + s [1] [1] * B.s [1] [1] ) % R;
                return Ret;
        }
        void print () {
             for ( int i = 0; i < 2; i ++ ) {
                 for ( int j = 0; j < 2; j ++ ) {
                     if ( j ) printf ( " " );
                     printf ( "%d" , s [i] [j] );
                 }
                 printf ( "\n" );
             }
        }
};

struct  TNode {
        int left , right;
        TNode *LeftChild , *RightChild;
        TMatrix Mul;
        void    Create ( int , int );
        void    Get ();
};

TMatrix Ans;
TNode   Tree [MAXN * 2 + 2] , *Root = &Tree [0];

bool    init ();
void    solve ();

main ()
{
     bool    first = true;
     while ( init () ) {
           if ( first ) first = false; else printf ( "\n" );
           solve ();
     }
}

void solve ()
{
     for ( int i = 0; i < Q; i ++ ) {
         if ( i ) printf ( "\n" );
         scanf ( "%d%d" , &S , &T );
         S -- , T --;
         Ans = TMatrix ();
         Root->Get ();
         Ans.print ();
     }
}

bool init ()
{
     if ( scanf ( "%d%d%d" , &R , &N , &Q ) == EOF ) return false;
     Len = 1;
     Root->Create ( 0 , N - 1 );
     return true;
}

void TNode :: Get ()
{
     if ( left >= S && right <= T ) { Ans = Ans * Mul; return; }
     if ( T < left || S > right ) return;
     LeftChild->Get ();
     RightChild->Get ();
}

void TNode :: Create ( int l , int r )
{
     left = l , right = r;
     if ( left == right ) { 
          for ( int i = 0; i < 2; i ++ )
              for ( int j = 0; j < 2; j ++ ) scanf ( "%d" , &Mul.s[i] [j] );
          LeftChild = RightChild = NULL; 
          return; 
     }
     int mid = ( left + right ) >> 1;
     LeftChild = Tree + Len ++;
     RightChild = Tree + Len ++;
     LeftChild->Create ( l , mid );
     RightChild->Create ( mid + 1 , r );
     Mul = LeftChild->Mul * RightChild->Mul;
}
