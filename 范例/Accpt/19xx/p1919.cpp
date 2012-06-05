#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MaxSize 1000

using   namespace std;
char    data [MaxSize] [25] , Last [MaxSize];
int     N;

int     degreein [26] , degreeout [26];
int     Len [26] , Bucket [26] [MaxSize] , Reach [26];

int     AnsLen , Ans [MaxSize];

bool    cmp ( const int & a, const int &b )
{
        return  strcmp ( data [a] , data [b] ) < 0;
}

void    init ()
{
        memset ( Len , 0 , sizeof ( Len ));
        memset ( Reach , 0 , sizeof ( Reach ));
        memset ( degreein , 0 , sizeof ( degreein ));
        memset ( degreeout , 0 , sizeof ( degreeout ));
        scanf ( "%d" , &N );
        char    a , b;
        int     i;
        for ( i = 0; i < N; i ++ ) {
                scanf ( "%s" , data [i] );
                a = data [i] [0] - 'a'; b = data [i] [strlen ( data [i] ) - 1] - 'a';
                Bucket [a] [Len [a] ++] = i;
                degreein [a] ++ , degreeout [b] ++;
                Last [i] = b;
        }
        for ( i = 0; i < 26; i ++ ) if ( Len [i] > 1 )
                sort ( Bucket [i] , Bucket [i] + Len [i] , cmp );
        AnsLen = 0;

/*        for ( i = 0; i < 26; i ++ ) if ( Len [i] ) {
                for ( int j = 0; j < Len [i]; j ++ )
                        printf ( "%s " , data [Bucket [i] [j]] );
                printf ( "\n" );
        }
*/
}

void    Search ( int loc )
{
        int     choose;
        while ( Reach [loc] < Len [loc] ) {
                choose = Bucket [loc] [Reach [loc] ++];
                Search ( Last [choose] );
                Ans [AnsLen ++] = choose;
        }
}

void    Print ()
{
        int     i;
        for ( i = AnsLen - 1; i >= 0; i -- ) {
                printf ( "%s" , data [Ans [i]] );
                if ( i ) printf ( "." );
        }
        printf ( "\n" );
}

bool    check ()
{
        int     Start , Tot , i;

        for ( Start = -1 , i = 0; i < 25; i ++ ) if ( degreein [i] || degreeout [i] )
                if ( Start == -1 ) Start = i;
                
        for ( Tot = 0 , i = 25; i >= 0; i -- ) {
                if ( degreein [i] - degreeout [i] > 1 || degreeout [i] - degreein [i] > 1 ) return false;
                if ( ( degreein [i] + degreeout [i] ) % 2 ) {
                        Tot ++;
                        if ( degreein [i] > degreeout [i] ) Start = i;
                }
        }
//        printf ( "%d\n" , Tot );
        if ( Tot > 2 ) return false;

        Search ( Start );

//        printf ( "AnsLen = %d\n" , AnsLen );
//        Print ();
        return AnsLen == N;
}

main ()
{
        freopen ( "c.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                if ( check () ) Print ();
                        else printf ( "***\n" );
        }
}
 