//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int     len;
int     Num [30];

int main(int argc, char* argv[])
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     i , Sum , Part;
        while ( scanf ( "%d" , &len ) , len ) {
                for ( Sum = i = 0; i < len; i ++ ) {
                        scanf ( "%d" , &Num [i] );
                        Sum += Num [i];
                }
                if ( Sum % 2 == 0 ) {
                        Sum >>= 1;
                        for ( Part = i = 0; Part < Sum; i ++ )
                                Part += Num [i];
                        if ( Part == Sum ) printf ( "Sam stops at position %d and Ella stops at position %d.\n" , i , i + 1 );
                                else printf ( "No equal partitioning.\n" );
                } else printf ( "No equal partitioning.\n" );
        }
        return 0;
}
//---------------------------------------------------------------------------
 