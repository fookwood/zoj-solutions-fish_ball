#include <stdio.h>

int     page;


void    print ()
{
        int     TotalUse = ( page + 3 ) / 4;
        int     Which [100] [4];
        int     i;
        for ( i = 1; i <= TotalUse; i ++ ) {
                if ( 2 * i - 1 <= page ) Which [i] [1] = 2 * i - 1;
                else Which [i] [1] = 0;
                if ( 2 * i <= page ) Which [i] [2] = 2 * i;
                else Which [i] [2] = 0;
        }
        for ( i = TotalUse; i > 0; i -- ) {
                if ( 2 * TotalUse + 2 * ( TotalUse - i ) + 1 <= page )
                        Which [i] [3] = 4 * TotalUse - 2 * i + 1;
                else Which [i] [3] = 0;

                if ( 2 * TotalUse + 2 * ( TotalUse - i ) + 2 <= page )
                        Which [i] [0] = 4 * TotalUse - 2 * i + 2;
                else Which [i] [0] = 0;
        }

        printf ( "Printing order for %d pages:\n" , page );
        for ( i = 1; i <= TotalUse; i ++ ) {
                printf ( "Sheet %d, front: " , i );
                if ( !Which [i] [0] ) printf ( "Blank" );
                else printf ( "%d" , Which [i] [0] );
                printf ( ", " );
                if ( !Which [i] [1] ) printf ( "Blank\n" );
                else printf ( "%d\n" , Which [i] [1] );

                if ( page <= 1  ) continue;
                printf ( "Sheet %d, back : " , i );
                if ( !Which [i] [2] ) printf ( "Blank" );
                else printf ( "%d" , Which [i] [2] );
                printf ( ", " );
                if ( !Which [i] [3] ) printf ( "Blank\n" );
                else printf ( "%d\n" , Which [i] [3] );

        }
}

main ()
{
        while ( scanf ( "%d" , &page ) , page )
                print ();
}
 