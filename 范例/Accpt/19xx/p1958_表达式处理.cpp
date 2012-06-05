#include <stdio.h>
#include <string.h>
#include <ctype.h>

int      Len , Ans;
char     Data [1000];

int      CharToInt ( int s , int t )
{
         int       Ret = 0;
         for ( int i = s; i < t; i ++ ) if ( isupper ( Data [i] ) )
             Ret |= 1 << ( Data [i] - 'A' );
         return  Ret;
}

int      NextPos ( int s )
{
         int have = 1 , i;
         for ( i = s + 1; have; i ++ ) {
             if ( Data [i] == '(' || Data [i] == '{' ) have ++;
             if ( Data [i] == ')' || Data [i] == '}' ) have --;
         }
         return i;
}

void     IntToChar ( int s )
{
         printf ( "{" );
         for ( int i = 0; i < 26; i ++ ) if ( s & ( 1 << i ) )
             printf ( "%c" , i + 'A' );
         printf ( "}\n" );
}

int      Value ( int l , int r )
{
         int   Next = NextPos ( l );
         if ( Next == r ) return Data [l] == '(' ? Value ( l + 1 , Next - 1 ) : CharToInt ( l + 1 , Next - 1 );
         
         int  Part = -1 , Next2;
         for ( Next2 = Next; Next2 != r; Next2 = NextPos ( Next2 + 1 ) )
             if ( Data [Next2] == '+' || Data [Next2] == '-' ) Part = Next2;
                else if ( Part == -1 || Data [Part] == '*' ) Part = Next2;
                
         int    First = Value ( l , Part ) , Second = Value ( Part + 1 , r );
         if ( Data [Part] == '+' ) return First | Second;
         if ( Data [Part] == '-' ) return First & (~Second);
         if ( Data [Part] == '*' ) return First & Second;
}

main ()
{
     while ( gets ( Data ) ) {
           int    len = strlen ( Data );
           IntToChar ( Value ( 0 , len ) );
     }
}
