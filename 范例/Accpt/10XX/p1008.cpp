#include <stdio.h>
#include <string.h>

struct  Tdata   {
        int     Next;
        int     Down , Right;
        int     Many;
        };

int     part;
int     n , Tot;
int     table [10] [10];
int     Map [10] [10];
Tdata   Line [26];
bool    FindSol;


void    init ()
{
        int     i , k;
        bool    appear;
        int     U , R , D , L;
        memset ( table , 0 , sizeof ( table ));
        memset ( Line , 0 , sizeof ( Line ));
        for ( i = 0 , Tot = 0; i < n * n; i ++ ) {
                scanf ( "%d %d %d %d" , &U , &R , &D , &L );
                for ( appear = 0 , k = table [U] [L]; !appear && k; k = Line [k].Next )
                        if ( Line [k].Down == D && Line [k].Right == R ) {
                                appear = 1;
                                Line [k].Many ++;
                        }
                if ( !appear ) {
                        Tot ++;
                        Line [Tot].Next = table [U] [L];
                        table [U] [L] = Tot;
                        Line [Tot].Down = D;
                        Line [Tot].Right = R;
                        Line [Tot].Many = 1;
                }
        }
}

void    search ( int x , int y )
{
        int     i , j;

        if ( x == n ) { FindSol = 1; return;  };
        if ( x == 0 && y == 0 ) {
                for ( i = 1; i <= Tot; i ++ ) if ( Line [i].Many ) {
                        Map [0] [0] = i;
                        Line [i].Many --;
                        if ( y == n - 1 ) search ( x + 1 , 0 );
                        else search ( x , y + 1 );
                        Map [0] [0] = 0;
                        Line [i].Many ++;
                        if ( FindSol ) return;
                }
        } else
        if ( x == 0 ) {
                for ( i = 0; i < 10; i ++ ) {
                     for ( j = table [i] [Line [Map [x] [y - 1]].Right];
                                j; j = Line [j].Next ) if ( Line [j].Many ) {
                                Map [x] [y] = j;
                                Line [j].Many --;
                                if ( y == n - 1 ) search ( x + 1 , 0 );
                                else search ( x , y + 1 );
                                Map [x] [y] = 0;
                                Line [j].Many ++;
                                if ( FindSol ) return;
                     }
                }
        }
        if ( y == 0 ) {
                for ( i = 0; i < 10; i ++ ) {
                        for ( j = table [Line [Map [x - 1] [y]].Down] [i] ;
                                j; j = Line [j].Next ) if ( Line [j].Many ) {
                                Map [x] [y] = j;
                                Line [j].Many --;
                                if ( y == n - 1 ) search ( x + 1 , 0 );
                                else search ( x , y + 1 );
                                Map [x] [y] = 0;
                                Line [j].Many ++;
                                if ( FindSol ) return;
                        }

                }
        }
        else {
                for ( j = table [Line [Map [x - 1] [y]].Down] [Line [Map [x] [y - 1]].Right];
                        j; j = Line [j].Next ) if ( Line [j].Many ) {
                        Map [x] [y] = j;
                        Line [j].Many --;
                        if ( y == n - 1 ) search ( x + 1 , 0 );
                        else search ( x , y + 1 );
                        Map [x] [y] = 0;
                        Line [j].Many ++;
                        if ( FindSol ) return;
                }
        }
}

main ()
{
        part = 0;
        while ( scanf ( "%d" , &n ) , n ) {
                if ( part ++ ) printf ( "\n" );
                init ();
                FindSol = 0;

                search ( 0 , 0 );

                printf ( "Game %d: " , part );
                if ( FindSol ) printf ( "Possible\n" );
                else printf ( "Impossible\n" );
        }
}
 