#include <stdio.h>

int     h , m;
int     m1 , m2;
int     d;
int     sh , sm;

main ()
{
        printf ( "Problem 3 by team x\n" );
        printf ( "==============================================================================\n" );
        printf ( " True     True     Minutes From   Minutes From   Discrepancy  Swapped  Swapped\n" );
        printf ( "Hours  Minutes   Minute Hand In   Hour Hand In    Of Minutes    Hours  Minutes\n" );
        printf ( "                  Swapped Clock  Swapped Clock\n" );
        printf ( "==============================================================================\n" );

        
        while ( scanf ( "%d %d" , &h , &m ) != EOF ) {
                printf ( "%5d%9d" , h , m );

                m1 = h % 12 * 5 + m / 12;  if ( m % 12 >= 6 ) m1 ++;
                m2 = ( m % 5 ) * 12;

                d = ( m2 - m1 + 60 ) % 60; if ( d > 30 ) d = 60 - d;


                printf ( "%17d%15d%14d" , m1 , m2 , d );
                if ( d <= 12 ) {
                        sh = m / 5; if ( !sh ) sh = 12;
                        sm = m1;
                        printf ( "%9d%9d" , sh , sm );
                } else printf ( "       --       --" );
                printf ( "\n" );
        }


        printf ( "==============================================================================\n" );
        printf ( "End of problem 3 by team x\n" );
}
 