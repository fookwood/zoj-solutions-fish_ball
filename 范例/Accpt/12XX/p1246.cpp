#define DEBUG
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

char    data [20];
int     contain [17];
int     Num [16] [17];

void    Work ()
{
        memset ( Num , 0 , sizeof ( Num ) );

        int     dep = 1 , *p , i , w;
        contain [1] = 1;
        in >> data;
        while ( dep ) {
                in >> data;
                if ( strcmp ( data , "LOOP" ) == 0 ) {
                        in >> data;
                        if ( data [0] == 'n' ) contain [++ dep] = -1; else contain [++dep] = atol ( data );
                        memset ( Num [dep] , 0 , sizeof ( Num [dep] )); 
                } else
                if ( strcmp ( data , "OP" ) == 0 ) {
                        in >> data;
                        Num [dep] [0] += atol ( data );
                } else {
                        p = &Num [dep - 1] [0];

                        if ( contain [dep] < 0 ) { w = 1; p ++; }
                        else w = contain [dep];

                        for ( i = 0; i < 16; i ++ )
                                *( p ++ ) += Num [dep] [i] * w;
                        dep --;
                }
        }
}

void    Print ()
{
        int     i , first = 1;
        out << "Runtime = ";
        for ( i = 15; i >= 0; i -- ) if ( Num [0] [i] ) {
                if ( first ) first = 0; else out << '+';
                if ( !i ) out << Num [0] [i];
                if ( i && Num [0] [i] > 1 ) out << Num [0] [i] << '*';
                if ( i ) out << 'n';
                if ( i > 1 ) out << '^' << i;
        }
        if ( first ) out << '0';
        out << endl;
}

main ()
{
        int     total , step = 1;

        for ( in >> total; step <= total; step ++ ) {
                out << "Program #" << step << endl;
                Work ();
                Print ();
                out << endl;
        }
}
