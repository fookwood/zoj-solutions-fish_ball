#include <stdio.h>
#include <string.h>
#define  MAXN     100

int      N , M , Link [MAXN] , Linkback [MAXN], Ans;
bool     graph [MAXN] [MAXN] , mky [MAXN] , mkx [MAXN];

void     init ();
bool     find ( int );
void     work ();
void     Search ( int );

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         work ();
         if ( total > 1 ) printf ( "\n" );
     }
}

bool find ( int k )
{
     int  t , q = Linkback [k];
     for ( int i = 0; i < M; i ++ ) if ( !mky [i] && graph [k] [i] ) {
         mky [i] = true;
         t = Link [i];
         Link [i] = k; Linkback [k] = i;
         if ( t == -1 || find ( t ) ) return true;
         Link [i] = t; Linkback [k] = q;
     }
     return false;
}

void Search ( int k )
{
     if ( mkx [k] ) return;
     mkx [k] = true;
     for ( int i = 0; i < M; i ++ ) if ( !mky [i] && graph [k] [i] ) {
         mky [i] = true;
         if ( Link [i] != -1 ) Search ( Link [i] );
     }
}

void work ()
{
     memset ( Link , 0xff , sizeof ( Link ));
     memset ( Linkback , 0xff , sizeof ( Linkback ));
     Ans = 0;
     for ( int i = 0; i < N; i ++ ) {
         memset ( mky , 0 , sizeof ( mky ));
         if ( find ( i )) Ans ++;
     }
     printf ( "%d\n" , Ans );
     memset ( mkx , 0 , sizeof ( mkx ));
     memset ( mky , 0 , sizeof ( mky ));
     
     for ( int i = 0; i < N; i ++ ) if ( Linkback [i] == -1 ) Search ( i );
     for ( int i = 0; i < N; i ++ ) if ( !mkx [i] ) printf ("1 %d\n" , i + 1 );
     for ( int i = 0; i < M; i ++ ) if ( mky [i] ) printf ( "2 %d\n" , i + 1 );
}

void init ()
{
     char Str [200];
     scanf ( "%d%d\n" , &N , &M );
     for ( int i = 0; i < N; i ++ ) {
           scanf ( "%s" , Str );
           for ( int j = 0; j < M; j ++ ) graph [i] [j] = (Str [j] == '*');
     }
}
