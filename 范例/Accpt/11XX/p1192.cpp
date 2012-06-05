#include <stdio.h>
#include <algorithm>

using   namespace std;

struct  TInfo {
        int     Time , Exist , UnExist , Introduce , Remove;
}       Data [200];

int     N , M , Pow [21] , Opt [1 << 20];

int     len , Heap [1 << 20];

bool    comp ( const int & a , const int & b )
{
        return  Opt [a] > Opt [b];
}

void    init ()
{
        char    Str1 [30] , Str2 [30];
        int     i , j;
        for ( i = 0; i < M; i ++ ) {
                Data [i].Exist = Data [i].UnExist = Data [i].Introduce = Data [i].Remove = 0;
                scanf ( "%d %s %s" , &Data [i].Time , Str1 , Str2 );
                for ( j = 0; j < N; j ++ ) {
                        if ( Str1 [j] == '+' ) Data [i].Exist |= Pow [j]; else
                        if ( Str1 [j] == '-' ) Data [i].UnExist |= Pow [j];
                        if ( Str2 [j] == '+' ) Data [i].Introduce |= Pow [j]; else
                        if ( Str2 [j] == '-' ) Data [i].Remove |= Pow [j];
                }
                Data [i].Remove = ~Data [i].Remove;
        }

        memset ( Opt , 0xff , 4 << N );
        Heap [0] = ( 1 << N ) - 1 , len = 1 , Opt [Heap [0]] = 0;
}

void    Work ()
{
        int     i , p , q , cost;
        while ( len ) {
                p = Heap [0];
                pop_heap ( Heap , Heap + len , comp ) , len --;

                for ( i = 0; i < M; i ++ ) {
                        if ( (p & Data [i].Exist) != Data [i].Exist || p & Data [i].UnExist ) continue;
                        q = p & Data [i].Remove | Data [i].Introduce;
                        cost = Opt [p] + Data [i].Time;
                        if ( Opt [q] != -1 && cost >= Opt [q] ) continue;
                        Opt [q] = cost;
                        Heap [len ++] = q , push_heap ( Heap , Heap + len , comp );
                }
        }

}

main ()
{
        int     i , step = 0;
        for ( i = 0; i < 21; i ++ ) Pow [i] = 1 << i;

        while ( scanf ( "%d%d" , &N , &M ) , N || M ) {
                printf ( "Product %d\n" , ++ step );
                
                init ();
                Work ();

                if ( Opt [0] == -1 ) printf ( "Bugs cannot be fixed.\n" );
                        else printf ( "Fastest sequence takes %d seconds.\n" , Opt [0] );
                printf ( "\n" );
        }
}
 