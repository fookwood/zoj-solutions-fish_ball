#include <stdio.h>
#include <string.h>

int      N , M;
char     Ans [100] [100];
char     Data [100] , Key [100];

int main(int argc, char *argv[])
{
    int      i , j , k , t;
    while ( scanf ( "%s" , Key ) , strcmp ( "THEEND" , Key ) ) {
          M = strlen ( Key );
          scanf ( "%s" , Data ); 
          N = strlen ( Data ) / M;
          for ( t = 0 , i = 'A'; i <= 'Z'; i ++ )
              for ( j = 0; j < M; j ++ ) if ( Key [j] == i )
                  for ( k = 0; k < N; k ++ ) Ans [k] [j] = Data [t ++];
          for ( i = 0; i < N; i ++ )
              for ( j = 0; j < M; j ++ ) printf ( "%c" , Ans [i] [j] );
          printf ( "\n" );
    }
}
