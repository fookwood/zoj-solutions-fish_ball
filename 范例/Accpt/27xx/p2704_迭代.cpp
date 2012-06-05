#include <stdio.h>
#include <string.h>
#define MaxLen    400000

int     N;
char    data [MaxLen];
int     Left [MaxLen];

bool    isregular ( char , char );
void    solve ();

main ()
{
     while ( scanf ( "%s" , data ) == 1 ) {
           solve ();
     }
}

void solve ()
{
     int   i , j;
     N = strlen ( data );
     memset ( Left , 0 , sizeof ( Left ));
     for ( i = 0; i < N; i ++ ) if ( data [i] == ')' || data [i] == ']' ) {
         for ( j = i - 1; j >= 0 && Left [j] != 0; j -= Left [j] );
         if ( j >= 0 && isregular ( data [j] , data [i] )) {
              for ( ; j && Left [j - 1]; j -= Left [j - 1] );
              Left [i] = i - j + 1;
         }
     }
     for ( i = j = 0; i < N; i ++ ) if ( Left [i] > Left [j] ) j = i;
     for ( i = j - Left [j] + 1; i <= j; i ++ ) printf ( "%c" , data [i] );
     printf ( "\n\n" );
}


bool isregular ( char a , char b )
{
     return a == '(' && b == ')' || a == '[' && b == ']';
}
