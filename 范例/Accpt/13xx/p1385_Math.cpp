//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
// zju 1385

#include <stdio.h>

int     n , m;

int     Pow ( int p )
{
        int     ret;
        for ( ret = 0 , p >>= 1; p; p >>= 1 )
                ret += p;
        return ret;
}

int main(int argc, char* argv[])
{
        int     total , i;
        scanf ( "%d" , &total );
        for ( i = 0; i < total; i ++ ) {
                scanf ( "%d%d" , &n , &m );
                n -= m /2 + 1;
                m = ( m - 1 ) / 2;
                if ( n < 0 || m < 0 || n < m )
                        printf ( "0\n" );
                        else
                        if ( Pow ( n ) - Pow ( m ) - Pow ( n - m ) )
                                printf ( "0\n" );
                                else printf ( "1\n" );               
        }
        return 0;
}
//---------------------------------------------------------------------------
 