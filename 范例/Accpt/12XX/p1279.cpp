#define DEBUG

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#ifdef DEBUG
        ifstream in ( "p.in" );
        ofstream out ( "p.out" );
#else
        istream & in = cin;
        istream & out = cout;
#endif

int     Total;
int     Num1;
int     Num2;
char    data [100];

int     range ( char ch )
{
        if ( ch == 'V' ) return 0;
        if ( ch == 'U' ) return 1;
        if ( ch == 'C' ) return 2;
        if ( ch == 'D' ) return 3;
        return -1;
}

int     Input ()
{
        scanf ( "%s" , data );
        int     len = strlen ( data );
        int     ret = 0;
        for ( int i = 0; i < len; i ++ )
                ret = ret * 4 + range ( data [i] );
        return ret;
}


bool    Work ()
{
        int     i;
        int     Num3;
        Num1 = Input ();
        Num2 = Input ();
        for ( i = 0; i < 3; i ++ ) {
                scanf ( "%s" , data );
                if ( data [0] == 'A' ) Num2 += Num1;
                else if ( data [0] == 'L' ) Num2 *= 4;
                else if ( data [0] == 'R' ) Num2 /= 4;
        }
        Num3 = Input ();
        return Num2 == Num3;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        printf ( "COWCULATIONS OUTPUT\n" );
        scanf ( "%d" , &Total );
        while ( Total ) {
                if ( Work () ) printf ( "YES\n" );
                else printf ( "NO\n" );
                Total --;
        }
        printf ( "END OF OUTPUT\n" );
}
 