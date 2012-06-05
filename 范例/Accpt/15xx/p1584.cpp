#include <stdio.h>
#include <string.h>

int     N;
char    d [1 << 12];

struct  HP {
        int     len , s [1 << 12];
        HP operator *(const HP &b );
        void    print ();
}       a , b , c;

void    HP :: print ()
{
        int     i;
        while ( len > 1 && s [len - 1] == 0 ) len --;
        for ( i = len - 1; i >= 0; i -- ) printf ( "%c" , s [i] + '0' );
        printf ( "%c" , 10 );
}

HP HP :: operator * ( const HP &b )
{
        HP      c;
        int     i , j;
        memset ( c.s , 0 , sizeof ( c.s ));
        for ( i = 0; i < len; i ++ )
                for ( j = 0; j < b.len; j ++ )
                        c.s [i + j] += s [i] * b.s [j];

        c.len = len + b.len - 1;
        for ( i = j = 0; i < c.len; i ++ ) {
                j += c.s [i];
                c.s [i] = j % 10;
                j /= 10;
        }
        while ( j ) c.s [c.len ++] = j % 10 , j /= 10;
        return  c;
}

void    part ()
{
        int     N2 = N / 2;
        int     i;
        a.len = b.len = N2;
        for ( i = 0; i < N2; i ++ ) a.s [i] = d [i] - '0';
        for ( i = 0; i < N2; i ++ ) b.s [i] = d [N - 1 - i] - '0';
        while ( a.len > 1 && a.s [a.len - 1] == 0 ) a.len --;
        while ( b.len > 1 && b.s [b.len - 1] == 0 ) b.len --;
}

main ()
{
        while ( scanf ( "%s" , d ) != EOF ) {
                N = strlen ( d );
                if ( N > 1 << 10 ) {
                        printf ( "0\n" );
                        continue;
                }
                if ( N & 1 ) d [N ++] = '0' , d [N] = 0;
                part ();
                c = a * b;
                c.print();
        }
}
 