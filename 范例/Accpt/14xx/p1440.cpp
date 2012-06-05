#include <stdio.h>
#include <algorithm>

using   namespace std;

unsigned int  Ni;
int     N;
int     Data [100000] , Code [100000] , tmp [100000] , Sort [100000];


void    GB_Sort ( int left , int right )
{
        if ( left == right ) return;

        int     mid = ( left + right ) >> 1;
        int     i = left , j = mid + 1 , len = 0;
        GB_Sort ( left , mid );
        GB_Sort ( mid + 1 , right );

        while ( i <= mid && j <= right )
                if ( Sort [i] < Sort [j] ) tmp [len ++] = Sort [i ++];
                        else tmp [len ++] = Sort [j ++] , Ni += mid - i + 1;

        while ( i <= mid ) tmp [len ++] = Sort [i ++];
        while ( j <= right ) tmp [len ++] = Sort [j ++];

        memcpy ( Sort + left , tmp , len << 2 );
}

bool    cmp ( const int & a , const int & b )
{
        return Data [a] < Data [b];
}

main ()
{
//        freopen ( "p.in" , "r" , stdin );

        int     i , j , k;
        int     Num;
        Ni = 0;
        scanf ( "%d" , &N );
        for ( i = 0; i < N; i ++ ) scanf ( "%d" , &Data [i] ) , Sort [i] = Data [i];
        GB_Sort ( 0 , N - 1 );

        int     low , high , mid , key;
        for ( i = 0; i < N; i ++ ) {
                low = 0 , high = N , key = Data [i];
                while ( low + 1 < high ) {
                        mid = ( low + high ) >> 1;
                        if ( Sort [mid] <= key ) low = mid;
                                else high = mid;
                }
                Code [i] = low;
        }

        Num = 0;
        for ( i = 0; i < N; i ++ ) if ( Code [i] >= 0 ) {
                Num ++;
                for ( j = i; Code [j] >= 0; j = k )
                        k = Code [j] , Code [j] = -1;
        }

        printf ( "%d\n%u\n" , N - Num , Ni );
//        system ( "pause" );
}
 