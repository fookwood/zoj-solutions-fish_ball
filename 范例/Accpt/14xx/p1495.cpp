// zju 1495
#include <stdio.h>

int     N;
int     now;

main ()
{
        int     i , tmp;
        while ( scanf ( "%d" , &N ) , N ) {
                for ( now = N , i = 0; i < N; i ++ ) {
                        scanf ( "%d" , &tmp );
                        if ( tmp < now ) now = tmp;
                        now --;
                }
                printf ( "%d\n" , - now );
        }
}
 