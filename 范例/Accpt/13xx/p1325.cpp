#include <stdio.h>
#include <string.h>

char    Data [255];
char    Pre [255];

void    Prepare ()
{
        memset ( Pre , ' ' , sizeof ( Pre ) );
        Pre ['A'] = 'A'; Pre ['E'] = '3';
        Pre ['H'] = 'H'; Pre ['I'] = 'I';
        Pre ['J'] = 'L'; Pre ['L'] = 'J';
        Pre ['M'] = 'M'; Pre ['8'] = '8';
        Pre ['S'] = '2'; Pre ['T'] = 'T';
        Pre ['U'] = 'U'; Pre ['V'] = 'V';
        Pre ['W'] = 'W'; Pre ['X'] = 'X';
        Pre ['Y'] = 'Y'; Pre ['Z'] = '5';
        Pre ['1'] = '1'; Pre ['2'] = 'S';
        Pre ['3'] = 'E'; Pre ['5'] = 'Z';
}

bool    Check ( char a , char b )
{
        if ( ( a == '0' || a == 'O' ) && ( b == '0' || b == 'O' )) return true;
        return Pre [a] == b;
}

int     WorkWithData ()
{
        int     len = strlen ( Data );
        int     i;
        int     regular = 1 , mirrored = 1 << 1;
        char    *p1 = &Data [0] , *p2 = &Data [len - 1];
        for ( i = 0; i < ( len + 1 ) / 2; i ++ , p1 ++ , p2 --) {
                if ( *p1 != *p2 ) regular = 0;
                if ( !Check ( *p1 , *p2 ) ) mirrored = 0;
                if ( ! ( regular | mirrored ) ) return 0;
        }
        return regular | mirrored;
}

main ()
{

        int     state;
        Prepare ();
        while ( scanf ( "%s" , Data ) != EOF ) {
                state = WorkWithData ();
                if ( state == 0 ) printf ( "%s -- is not a palindrome." , Data ); else
                if ( state == 1 ) printf ( "%s -- is a regular palindrome." , Data ); else
                if ( state == 2 ) printf ( "%s -- is a mirrored string." , Data ); else
                printf ( "%s -- is a mirrored palindrome." , Data );
                printf ( "\n\n" );
        }
}
 