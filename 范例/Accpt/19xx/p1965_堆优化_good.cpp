#include <stdio.h>
#include <functional>
#include <algorithm>
#define  MAXN       50
using    namespace  std;

int      N , Deg [MAXN] , Last [MAXN] , Heap [MAXN] , LenHeap;
int      LeftChild [MAXN] , RightBrother [MAXN];

bool     init ()
{
         char Str [1000];
         if ( !gets ( Str ) ) return false;
         N = 0;
         int delta = -1 , len =strlen ( Str );
         while ( ++ delta < len && sscanf ( Str + delta , "%d" , &Deg [N ++] ) != EOF )
               while ( delta < len && Str [delta] != ' ' ) delta ++;
         N ++;
         return true;
}

void     Print ( int p )
{
         if ( p == -1 ) return;
         printf ( "(%d" , p + 1 );
         for ( int q = LeftChild [p]; q != -1; q = RightBrother [q] ) printf ( " " ) , Print ( q );
         printf ( ")" );
}

void     Work ()
{
         if ( N == 0 ) { printf ( "(1)\n" ); return; }
         memset ( Last , 0xff , sizeof ( Last ));
         memset ( LeftChild , 0xff , sizeof ( LeftChild ));
         memset ( RightBrother , 0xff , sizeof ( RightBrother ));
         
         for ( int i = 0; i + 1 < N; i ++ ) Last [-- Deg [i]] = i;
         LenHeap = 0;
         for ( int i = 0; i < N; i ++ ) if ( Last [i] == -1 ) Heap [LenHeap ++] = i;
         make_heap ( Heap , Heap + LenHeap , less<int> () );
  
         for ( int i = 0; i + 1 < N; i ++ ) {
             RightBrother [Heap [0]] = LeftChild [Deg [i]] , LeftChild [Deg [i]] = Heap [0];
             pop_heap ( Heap , Heap + LenHeap , less<int> () ) , LenHeap --;
             if ( Last [Deg [i]] == i ) Heap [LenHeap ++] = Deg [i] , push_heap ( Heap , Heap + LenHeap , less<int>() );
         }
         Print ( N - 1 );
         printf ( "\n" );
}

main ()
{
     while ( init () ) {
           Work ();
     }
}
