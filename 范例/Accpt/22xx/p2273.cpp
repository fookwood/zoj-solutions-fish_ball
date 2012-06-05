#include <cstdlib>
#include <iostream>

using namespace std;

int   len;
char  Name [500000];
int   Pos [100000];

void  prepare ()
{
 len = 0;
 for ( int i = 1; i < 100000; i ++ ) {
     if ( i > 9999 ) Name [++len] = i / 10000;
     if ( i > 999 ) Name [++len] = i / 1000 % 10;
     if ( i > 99 ) Name [++len] = i / 100 % 10;
     if ( i > 9 ) Name [++len] = i / 10 % 10;
     Name [++len] = i % 10;
     Pos [i] = len;
 }      
}

int     find ( int L , int state = 0 )
{
        if ( L == 1 ) return 1;
        return state & 1 ? find ( L / 2 , state + 1 ) * 2 : find ( ( L + 1 ) / 2 , state + 1 ) * 2 - 1;
}

int main(int argc, char *argv[])
{
    prepare ();
    int     N;
    while ( scanf ( "%d" , &N ) != EOF ) printf ( "%d\n" , Name [find ( Pos [N] )] );
    system("PAUSE");
    return EXIT_SUCCESS;
}
