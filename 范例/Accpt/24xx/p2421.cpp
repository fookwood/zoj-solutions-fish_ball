#include <stdio.h>
#include <string.h>

#define MAXN 500010
int      Num [MAXN];
bool     Appear [10000000];

void     prepare ();

main ()
{
     prepare ();
     int     N;
     while ( scanf ( "%d" , &N ) , N != -1 )
           printf ( "%d\n" , Num [N] );
}

void prepare ()
{
     memset ( Appear , 0 , sizeof ( Appear ));
     Num [0] = 0;Appear [0] = true;
     for ( int i = 1; i <= MAXN; i ++ ) {
         Num [i] = Num [i - 1] - i > 0 && !Appear [Num [i - 1] - i] ? Num [i - 1] - i : Num [i - 1] + i;
         Appear [Num [i]] = true; 
     }
}
// 1668077 2006-03-08 19:48:27 Accepted 2421 C++ 00:00.04 12156K AndyZhau 
