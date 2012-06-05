#include <stdio.h>
#include <string.h>

bool     Searched;
int      Sum , N , Num [12] , Many [12] , Include [12];

bool     init ()
{
    scanf ( "%d%d", &Sum , &N );
    if ( Sum == 0 && N == 0 ) return false;

    int  i , j;    
    for ( i = 0; i < N; i ++ ) scanf ( "%d" , &Num [i] );
    for ( j = 0 , Many [j] = 1 , i = 1; i < N; i ++ ) if ( Num [i] != Num [i - 1] )
        Num [++ j] = Num [i] , Many [j] = 1;
        else Many [j] ++;
    N = ++ j;

    return true;      
}

void     printans ( int depth )
{
 int     Ans [12] , len = 0 , i , j = 0;
 for ( i = 0; i < depth; i ++ )
     for ( j = 0; j < Include [i]; j ++ ) Ans [len ++] = Num [i];
 if ( len == 0 ) return;
 Searched = true;
 for ( i = 0; i < len; i ++ ) {
     if ( i ) printf ( "+" );
     printf ( "%d" , Ans [i] );
 }
 printf ( "\n" );
}

void     Search ( int depth , int get )
{
 if ( depth && Include [depth - 1] && get == Sum ) printans ( depth );
 if ( get > Sum || depth == N ) return;
 
 for ( int i = Many [depth]; i >= 0; i -- )
     Include [depth] = i , Search ( depth + 1 , get + Num [depth] * i );
}

int main(int argc, char *argv[])
{
    while ( init () ) {
          printf ( "Sums of %d:\n" , Sum );
          Searched = false;
          memset ( Include , 0 , sizeof ( Include ));
          Search ( 0 , 0 );
          if ( !Searched ) printf ( "NONE\n" );
    }
}
