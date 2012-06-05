#include <stdio.h>
#include <string.h>

char    Data [60];
int     Num [2] [26];

main ()
{
        int     total , step;
        int     i , j , Ans , len;

        for ( scanf ( "%d\n" , &total ) , step = 1; step <= total; step ++ ) {
                memset ( Num , 0 , sizeof ( Num ));
                for ( j = 0; j < 2; j ++ ) {
                        gets ( Data ); len = strlen ( Data );
                        for ( i = 0; i < len; i ++ )
                                Num [j] [Data [i] - 'a'] ++;
                }
                for ( Ans = i = 0; i < 26; i ++ )
                        Ans += Num [0] [i] > Num [1] [i] ? Num [0] [i] - Num [1] [i] : Num [1] [i] - Num [0] [i];

                printf ( "Case #%d:  %d\n" , step , Ans ); 
        }
}
