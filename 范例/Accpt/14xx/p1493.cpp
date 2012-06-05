#include <stdio.h>
#include <ctype.h>

const   int     change [16] = { '8' , '9' , 'a' , 'b' , 'c' ,'d' ,'e' ,'f' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' }; 

char    ch;
int     N;
int     b [10000];

main ()
{
       
        int     i , j , tmp , sum;

        while ( scanf ( "%d" , &N ) != EOF ) {

                for ( sum = i = 0; i < N; i ++ ) {
                        tmp = 0;
                        while ( scanf ( "%c" , &ch ) , !isxdigit ( ch ) );
                        tmp = ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10;
                        while ( scanf ( "%c" , &ch ) , !isxdigit ( ch ) );
                        tmp <<= 4;
                        tmp += ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10;
                        tmp -= sum;
                        if ( tmp > 7 ) b [i] = 7; else
                        if ( tmp < -8 ) b [i] = -8; else
                                b [i] = tmp;
//                        printf ( "%d %d %d\n" , tmp , sum , b [i] );

                        sum += b [i];
                }
                        printf ( "%d\n" , N >> 1 );
                        for ( i = j = 0; i < N; i ++ ) {
                                printf ( "%c" , change [b [i] + 8] );
                                if ( i & 1 )
                                        if ( ++ j == 8 ) j = 0 , printf ( "\n" );
                                                else if ( i < N - 1 ) printf ( " " );
                        }
                        if ( j ) printf ( "\n" );
        }

//        system ( "pause" );
}
 