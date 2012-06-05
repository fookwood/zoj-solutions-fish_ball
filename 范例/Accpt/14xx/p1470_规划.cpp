#include <stdio.h>
#include <string.h>

#define MAXN      22

int     f [MAXN] [MAXN] [MAXN] , N , M;

void prepare ();

int  find ( int , int , int );
void solve ();

main ()
{
     prepare ();
     while ( scanf ( "%d%d" , &N , &M ) != EOF ) {
           solve ();
     }
}

void solve ()
{
     int   Sum = 0 , k;
     for ( k = N; k >= 0; k -- )
         Sum += find ( k , N , M );
     printf ( "%d\n" , Sum );
}

int  find ( int depth , int nodes , int leaves )
{
     if ( depth < 0 || nodes < leaves ) return 0;
     if ( f [depth] [nodes] [leaves] != -1 ) return f [depth] [nodes] [leaves];
     int  depthl , depthr , nodesl , nodesr , leavesl , leavesr , tl , tr;
     f [depth] [nodes] [leaves] = 0;
     for ( int i = 0; i < 2; i ++ )
         for ( int j = 0; j < 2; j ++ ) if ( !i || !j ) {
             depthl = depth - i - 1 , depthr = depth - j - 1;
             for ( nodesl = 0; nodesl < nodes; nodesl ++ )
                 for ( nodesr = nodes - nodesl - 1 , leavesl = 0; leavesl <= leaves; leavesl ++ ) {
                     leavesr = leaves - leavesl;
                     tl = find ( depthl , nodesl , leavesl );
                     tr = find ( depthr , nodesr , leavesr );
                     f [depth] [nodes] [leaves] += tl * tr;
                 }
         }
     return f [depth] [nodes] [leaves];
}

void    prepare ()
{
     memset ( f , 0xff , sizeof ( f ));
     for ( int i = 0; i < MAXN; i ++ )
         for ( int j = 0; j < MAXN; j ++ ) f [0] [i] [j] = 0;
     f [0] [0] [0] = 1;
     f [1] [1] [1] = 1;
     f [1] [1] [0] = 0;
}
