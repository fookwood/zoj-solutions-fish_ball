#include <stdio.h>
#include <string.h>

int     N , Num [301];

int     Answer ()
{
        memset ( Num , 0 , sizeof ( Num ));
        Num [0] = 1;
        
        int     i , j , k;
        for ( i = j = 1; j <= N; j += i + i + 1 , i ++ )
                for ( k = 0; k + j <= N; k ++ ) Num [k + j] += Num [k];
        return  Num [N];
}

main ()
{
        while ( scanf ( "%d" , &N ) , N )
                printf ( "%d\n" , Answer () );
}
 