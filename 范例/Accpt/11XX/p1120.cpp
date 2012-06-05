#include <stdio.h>

int     N;
double  TimeTake , per;
double  Left;
int     a , b , c;

main ()
{
        scanf ( "%d %lf" , &N , &TimeTake );
        per = TimeTake * 2 / ( N - 1 );
         
        printf ( "Program 1 by team X\n" );
        printf ( "N =%4d, T =%6.1lf\n" , N , TimeTake );
        while ( scanf ( "%d %d" , &a , &b ) != EOF ) {
                c = ( a - b + N ) % N;
                if ( c % 2 == 0 ) Left = (( c / 2 ) - 0.25 ) * per;
                        else Left = (( c - 1 ) / 2 + 0.25 ) * per;
                printf ( "Chair%4d meets chair%4d, remaining time =%6.1lf\n" , a , b , Left );
        }
        printf ( "End of program 1 by team X\n" );
}
 