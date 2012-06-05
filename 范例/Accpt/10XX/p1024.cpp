#include <stdio.h>

const   int     Limit [13] =
        {0 , 31, 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

int     n;
int     year , month , day;
int     i;
int     Win [2002] [12] [31];

int     Sepecial ( int year )
{
        if ( year % 400 == 0 ) return 1;
        if ( year % 100 == 0 ) return 0;
        if ( year % 4 == 0 ) return 1;
        return 0;
}

int     live ( int year , int month , int day )
{
        if ( year < 1900 || year > 2001 ) return 0;
        if ( year == 2001 && month == 12 ) return 0;
        if ( year == 2001 && month == 11 && day > 4 ) return 0;
        if ( month < 1 || day < 1 ) return 0;
        if ( Sepecial ( year ) && month == 2 && day == 29 ) return 1;
        if ( day > Limit [month] ) return 0;
        return 1;
}

int     AddDay ( int year, int month , int day )
{
        if ( Sepecial ( year ) && month == 2 && day == 28 ) day ++;
        else if ( day == Limit [month] ) { day = 1; month ++; if ( month == 13 ) { month = 1; year ++; } }
        else day ++;
        
        if ( live ( year , month , day ) && !Win [year] [month] [day] ) return 1;
        else return 0;
}

int     AddMonth ( int year , int month , int day )
{
        if ( month == 12 ) { month = 1; year ++; }
        else month ++;
        
        if ( live ( year , month , day ) && !Win [year] [month] [day] ) return 1;
        else return 0;
}

void    init ()
{
        int     y , m , d;
        AddDay ( 2001 , 11 , 2 );
        for ( y = 2001 ; y >= 1900; y -- )
                for ( m = 12; m > 0; m -- )
                        for ( d = 31; d > 0; d -- ) {
                                if ( !live ( y , m , d ) ) continue;
                                if ( y == 2001 && m == 11 && d == 4 )
                                        Win [y] [m] [d] = 0;
                                else if ( AddDay ( y , m , d ) || AddMonth ( y , m , d ) ) Win [y] [m] [d] = 1;
                                else Win [y] [m] [d] = 0;

                        }
        
}

main ()
{
        init ();
        scanf ( "%d" , &n );
        for ( i = 0; i < n ; i ++ ) {
                scanf ( "%d %d %d" , &year , &month , &day );
                if ( live ( year , month , day ) && Win [year] [month] [day] )
                        printf ( "YES\n" );
                else printf ( "NO\n" );
        }
}
 