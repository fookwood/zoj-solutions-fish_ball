//#define DEBUG

#include <iostream>
#include <fstream>
using namespace std;

#ifdef  DEBUG
ifstream in ( "p.in" );
ofstream out ( "p.out" );
#else
istream & in = cin;
ostream & out = cout;
#endif

const   int     maxLimit  = 190000;
const   int     PDown   = 1000000;
const   int     Goal    = 123456780;
const   int     dx [4] = { 0 , -1 , 0 , 1 };
const   int     dy [4] = { -1 , 0 , 1 , 0 };
const   char    cho [4] = { 'l' , 'u' , 'r' , 'd' };
const   int     powfor10 [10] = { 1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 10000000 , 100000000 , 1000000000 };

int     Start;
int     Bucket [PDown];
int     Line [maxLimit] , Next [maxLimit] , Pos [maxLimit] , Pre [maxLimit];
char    Choose [maxLimit];

bool    init ()
{
        Start = 0;
        int     i;
        char    t;
        for ( i = 0; i < 9; i ++ ) {
                if ( ! ( in >> t )) return false;
                Start *= 10;
                if ( t != 'x' ) Start += t - '0';
        }
        return true;
}

int     check ( int t )
{
        int     i = Bucket [t % PDown];
        while ( i != -1 ) {
                if ( Line [i] == t ) return i;
                i = Next [i];
        }
        return -1;
}

bool    range ( int x , int y )
{
        return x >= 0 && x < 3 && y >=0 && y < 3;
}

void    search ()
{
        int     s = 0 , t = 1;
        int     x , y , tx , ty , tp , temp , d;
        int     i;

        Pos [0] = 0;
        for ( i = 0; i < PDown; i ++ ) Bucket [i] = -1;
        Line [0] = Goal; Next [0] = Bucket [Goal % PDown]; Bucket [Goal % PDown] = 0;

        while ( s != t ) {
                x = Pos [s] / 3;
                y = Pos [s] % 3;

                for ( i = 0; i < 4; i ++ ) {
                        tx = x + dx [i]; ty = y + dy [i];
                        if ( !range ( tx , ty )) continue;
                        tp = tx * 3 + ty;
                        d = Line [s] / powfor10 [tp] % 10;
                        temp = Line [s] - d * powfor10 [tp] + d * powfor10 [Pos [s]];
                        d = check ( temp );

                        if ( d != -1 ) continue;
                        Line [t] = temp;
                        Pos [t] = tp;
                        Next [t] = Bucket [temp % PDown];
                        Pre [t] = s;
                        Choose [t] = cho [i];
                        Bucket [temp % PDown] = t;
                        t ++;
                }
                s ++;
        }
}

void    Work ()
{
        int     t;
        t = check ( Start );
        if ( t == -1 ) {
                out << "unsolvable";
                return;
        }
        while ( t ) {
                out << Choose [t];
                t = Pre [t];
        }
}

main ()
{
        search ();
        while ( 1 ) {
                if ( !init () ) break;
                Work ();
                out << endl;
        }
}
 