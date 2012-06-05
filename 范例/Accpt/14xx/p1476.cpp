// zju 1476
//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
        int     a , b;
        while ( scanf ( "%d%d" , &a , &b ) , a || b ) {
                if ( a * ( b + 1 ) % 60 == 0 )
                        printf ( "1\n" );
                else if ( a * ( b + 1 ) * ( b + 1 ) % 60 == 0 )
                        printf ( "2\n" );
                else printf ( "Impossible\n" );
        }

        return 0;
}
//---------------------------------------------------------------------------
 