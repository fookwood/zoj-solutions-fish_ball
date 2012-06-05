#include <string.h>
#include <stdio.h>

const   int     Limit   = 255;
char    defau [] = "<default>";

char    data [Limit];
char    Protocol [Limit] , Host [Limit] , Port [Limit] , Path [Limit];

void    Work ()
{
        int     pos , len = strlen ( data );
        char    *p , *q1 , *q2;

        p = strstr ( data , "://" );
        pos = p - data;
        strncpy ( Protocol , data , pos ); Protocol [pos] = 0;
        p += 3;

        q1 = strstr ( p , ":" );
        q2 = strstr ( p , "/" );

        if ( q1 == NULL ) {
                strcpy ( Port , defau );

                if ( q2 == NULL ) {
                        pos = len - ( p - data );
                        strncpy ( Host , p , pos ); Host [pos] = 0;
                        strcpy ( Path , defau );
                } else {
                        pos = q2 - p;
                        strncpy ( Host , p , pos ); Host [pos] = 0;
                        pos = len - ( q2 - data ) - 1;
                        strncpy ( Path , q2 + 1 , pos ); Path [pos] = 0;
                }
        } else {
                if ( q2 == NULL ) {
                        pos = q1 - p;
                        strncpy ( Host , p , pos ); Host [pos] = 0;

                        pos = len - ( q1 - data ) - 1;
                        strncpy ( Port , q1 + 1 , pos ); Port [pos] = 0;
                        strcpy ( Path , defau );
                } else {
                        pos = q2 - q1 - 1;
                        if ( pos >= 0 ) {
                                pos = q1 - p;
                                strncpy ( Host , p , pos ); Host [pos] = 0;

                                pos = q2 - q1 - 1;
                                strncpy ( Port , q1 + 1 , pos ); Port [pos] = 0;
                                pos = len - ( q2 - data ) - 1;
                                strncpy ( Path , q2 + 1 , pos ); Path [pos] = 0;
                        } else {
                                pos = q2 - p;
                                strncpy ( Host , p , pos ); Host [pos] = 0;

                                pos = len - ( q2 - data ) - 1;
                                strncpy ( Path , q2 + 1 , pos ); Path [pos] = 0;

                                strcpy ( Port , defau );
                        }
                }
        }

        printf ( "Protocol = %s\n" , Protocol );
        printf ( "Host     = %s\n" , Host );
        printf ( "Port     = %s\n" , Port );
        printf ( "Path     = %s\n" , Path );
        printf ( "\n" );
}

main ()
{
        int     step , total;
        scanf ( "%d" , &total );
        for ( step = 1; step <= total; step ++ ) {
                scanf ( "%s" , data );
                printf ( "URL #%d\n" , step );
                Work ();
        }
}
 