//#define DEBUG

#include <iostream>

#ifdef DEBUG
#include <fstream>
#endif

using namespace std;

#ifdef DEBUG
        ifstream in ( "p.in" );
        ofstream out ( "p.out" );
#else
        istream & in = cin;
        ostream & out = cout;
#endif

int     first;
char    data [3] [4];

int     Ord ( int k )
{
        char    *p;
        int     ret;
        int     len = strlen ( data [k] ) , d = 0;
        if ( len == 2 )
                if ( data [k] [1] == '#' ) d = 1; else d = -1;
        p = & data [k] [0];
        if ( *p == 'A' || *p == 'a' ) ret = 0; else
        if ( *p == 'B' || *p == 'b' ) ret = 2; else
        if ( *p == 'C' || *p == 'c' ) ret = 3; else
        if ( *p == 'D' || *p == 'd' ) ret = 5; else
        if ( *p == 'E' || *p == 'e' ) ret = 7; else
        if ( *p == 'F' || *p == 'f' ) ret = 8; else
        if ( *p == 'G' || *p == 'g' ) ret = 10;
        ret += d;
        if ( ret < 0 ) ret = 11;
        return ret;
}

int     init ()
{
        int     i;
        for ( i = 0; i < 3; i ++ )
                if ( !( in >> data [i]) ) return 0;
        return 1;
}

int     Find ( int a , int b , int c )
{
        int     l1 , l2;
        l1 = ( b - a + 12 ) % 12;
        l2 = ( c - b + 12 ) % 12;
        if ( l1 == 3 && l2 == 4 ) return 1;
        if ( l1 == 4 && l2 == 3 ) return 2;
        return 0; 
}

void    Swap ( int & a , int & b )
{
        int     t;
        t = a; a = b; b = t;
}

int     Check ()
{
        int     a = Ord ( 0 ), b = Ord ( 1 ) , c = Ord ( 2 );
        int     state;

        if ( a > b ) Swap ( a , b );
        if ( a > c ) Swap ( a , c );
        if ( b > c ) Swap ( b , c );

        first = a; state = Find ( a , b , c ); if ( state ) return state;
        first = b; state = Find ( b , c , a ); if ( state ) return state;
        first = c; state = Find ( c , a , b ); return state;        
}

char    Back ( int t )
{
        if ( t == 0 ) return 'A'; else
        if ( t == 1 ) { out << 'A'; return '#'; } else
        if ( t == 2 ) return 'B'; else
        if ( t == 3 ) return 'C'; else
        if ( t == 4 ) { out << 'C'; return '#'; } else
        if ( t == 5 ) return 'D'; else
        if ( t == 6 ) { out << 'D'; return '#'; } else
        if ( t == 7 ) return 'E'; else
        if ( t == 8 ) return 'F'; else
        if ( t == 9 ) { out << 'F'; return '#'; } else
        if ( t == 10 ) return 'G';
        out << 'G'; return '#';
}

main ()
{
        int     i , state;
        while ( init () ) {
                state = Check ();
                out << data [0] << ' ' << data [1] << ' ' << data [2];
                if ( state == 2 ) { out << " is a "; out << Back ( first ); out << " Major chord.\n"; } else
                if ( state == 1 ) { out << " is a "; out << Back ( first ); out << " Minor chord.\n"; } else
                out << " is unrecognized.\n";
        }
}
 