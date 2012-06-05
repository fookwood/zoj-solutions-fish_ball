#include <stdio.h>

int     part;
int     n;
int     step;
int     L , C;
int     Time [1001];
int     MinLecture [1001];
int     MinDis [1001];

void    init ()
{
        int     i;
        scanf ( "%d %d" , &L , &C );
        for ( i = 1; i <= n; i ++ ) scanf ( "%d" , &Time [i] );

}

int     use ( int t )
{
        if ( !t ) return 0;
        if ( t <= 10 ) return -C;
        return ( t - 10 ) * ( t - 10 );
}

void    MinOne ()
{
        int     i , j;
        int     l , cost;
        int     sum;
        MinLecture [0] = MinDis [0] = 0;
        for ( i = 1; i <= n; i ++ ) {
                MinLecture [i] = 30000;
                for ( sum = 0 , j = i - 1; j >= 0; j -- ) {
                        sum += Time [j + 1];
                        if ( sum > L ) break;
                        if ( MinLecture [j] > MinLecture [i] ) continue;
                        cost = MinDis [j] + use ( L - sum );
                        if ( MinLecture [j] == MinLecture [i] && cost >= MinDis [i] ) continue;
                        MinLecture [i] = MinLecture [j];
                        MinDis [i] = cost;
                }
                MinLecture [i] ++;
        }
}

void    print ()
{
        printf ( "Case %d:\n\n" , step );
        MinOne ();
        printf ( "Minimum number of lectures: %d\n" , MinLecture [n] );
        printf ( "Total dissatisfaction index: %d\n" , MinDis [n] );
}

main ()
{
        scanf ( "%d" , &part );
        for ( ; part ; part -- ) {
                step = 0;
                while ( scanf ( "%d" , &n ) , n ) {
                        if ( step ) printf ( "\n" );
                        step ++;
                        init ();
                        print ();
                }
                if ( part > 1 ) printf ( "\n" );
        }
}
 