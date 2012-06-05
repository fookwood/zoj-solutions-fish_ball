#include <stdio.h>
#include <string.h>
#define HashSize 49999
#define BFSSize 150000

const   int dx [4] = { 0 , 0 , -1 , 1 };
const   int dy [4] = { -1 , 1 , 0 , 0 };

int     Start , Goal , open , closed;
int     Bucket [HashSize] , Line [BFSSize] , Next [BFSSize] , Pre [BFSSize];

int     get_num ( int p [] )
{
        int     tmp , i , j;
        for ( i = 0; i < 6; i += 2 )
                for ( j = i + 2; j < 8; j += 2 )
                        if ( p [i] > p [j] || p [i] == p [j] && p [i + 1] > p [j + 1] )
                                tmp = p [i] , p [i] = p [j] , p [j] = tmp ,
                                tmp = p [i + 1] , p [i + 1] = p [j + 1] , p [j + 1] = tmp;

        for ( tmp = i = 0; i < 8; i ++ ) tmp = ( tmp << 3 ) | p [i];
        return  tmp;
}

void    part_num ( int num , int p [] )
{
        int     i;
        for ( i = 7; i >= 0; i -- ) p [i] = num & 7 , num >>= 3;
}

int     add ( int num )
{
        int     k = num % HashSize , i;

        for ( i = Bucket [k]; i != -1; i = Next [i] ) if ( Line [i] == num ) return i;
        Pre [closed] = open;
        Line [closed] = num , Next [closed] = Bucket [k] , Bucket [k] = closed ++;
        return -1;
}

bool    range ( int x , int y )
{
        return  x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool    init ()
{
        int     Data [8] , i;
        for ( i = 0; i < 8; i ++ ) if ( scanf ( "%d" , &Data [i] ) == EOF ) return false;
        for ( i = 0; i < 8; i ++ ) Data [i] --;
        Start = get_num ( Data );
        part_num ( Start , Data );
        for ( i = 0; i < 8; i ++ ) scanf ( "%d" , &Data [i] ) , Data [i] --;
        Goal = get_num ( Data );
        return true;
}

int     BFS ()
{
        if ( Start == Goal ) return true;

        int     i , k , x , y , extended [8] , example [8] , Key , LastClosed = 0 , step = 0 , flag;
        bool    map [8] [8];

        memset ( Bucket , 0xff , sizeof ( Bucket ));
                // Value
        open = closed = 0;
        for ( add ( Start ); open < closed; open ++ ) {
                if ( open == LastClosed ) step ++ , LastClosed = closed;
                if ( step == 5 ) break;

                memset ( map , 0 , sizeof ( map ));
                part_num ( Line [open] , example );
                for ( i = 0; i < 8; i += 2 ) map [example [i]] [example [i + 1]] = true;

                for ( i = 0; i < 8; i += 2 ) {
                        for ( k = 0; k < 4; k ++ ) {
                                memcpy ( extended , example , sizeof ( example ));

                                x = example [i] + dx [k] , y = example [i + 1] + dy [k];
                                if ( !range ( x , y )) continue;

                                if ( !map [x] [y] ) {
                                        extended [i] = x , extended [i + 1] = y ,
                                        Key = get_num ( extended );
                                        add ( Key );
                                        if ( Key == Goal ) return true;
                                } else {
                                        x += dx [k] , y += dy [k];
                                        if ( !range ( x , y ) || map [x] [y] ) continue;
                                        extended [i] = x , extended [i + 1] = y;
                                        Key = get_num ( extended );
                                        add ( Key );
                                        if ( Key == Goal ) return true;
                                }
                        }
                }
        }

        flag = closed , add ( Goal ) , open = closed - 1;
        for ( open = closed - 1 , step = 0 , LastClosed = open; open < closed; open ++ ) {
                if ( open == LastClosed ) step ++ , LastClosed = closed;
                if ( step == 5 ) break;

                memset ( map , 0 , sizeof ( map ));
                part_num ( Line [open] , example );
                for ( i = 0; i < 8; i += 2 ) map [example [i]] [example [i + 1]] = true;

                for ( i = 0; i < 8; i += 2 ) {
                        for ( k = 0; k < 4; k ++ ) {
                                memcpy ( extended , example , sizeof ( example ));

                                x = example [i] + dx [k] , y = example [i + 1] + dy [k];
                                if ( !range ( x , y )) continue;

                                if ( !map [x] [y] ) {
                                        extended [i] = x , extended [i + 1] = y ,
                                        Key = get_num ( extended );
                                        Key = add ( Key );
                                        if ( Key != -1 && Key < flag ) return true;
                                } else {
                                        x += dx [k] , y += dy [k];
                                        if ( !range ( x , y ) || map [x] [y] ) continue;
                                        extended [i] = x , extended [i + 1] = y;
                                        Key = get_num ( extended );
                                        Key = add ( Key );
                                        if ( Key != -1 && Key < flag ) return true;
                                }
                        }
                }
        }
        return false;
}

main ()
{
        while ( init () ) {
                if ( BFS () ) printf ( "YES\n" );
                        else printf ( "NO\n" );
                
        }
}
