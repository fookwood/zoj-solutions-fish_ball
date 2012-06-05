#define DEBUG

#include <iostream>
#include <strstream>

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

int     Time;
int     N , Min;
int     M;
int     len [30];
int     Cost [30] [11];
char    data [1000];

bool    init ()
{
        in >> data;
        if ( strstr ( data , "ENDOFINPUT" ) != NULL ) return false;
        in >> N; in.getline( data , 1000 );
        int     i;
        for ( i = 0; i < N; i ++ ) {
                in.getline( data , 1000 );
                len [i] = Cost [i] [0] = 0;
                istrstream rin ( data );
                while ( rin >> Cost [i] [len [i] + 1] ) {
                        len [i] ++;
                        Cost [i] [0] += Cost [i] [len [i]];
                }
        }
        in >> Time;
        in >> data;
        return true;
}

main ()
{
        int     i , j , T;
        while ( init () ) {
                Min = 999999999;
                for ( i = 0; i < N; i ++ ) {
                        T = Time % Cost [i] [0];
                        for ( j = 1; T >= Cost [i] [j]; j++ ) T -= Cost [i] [j];
                        if ( T ) T = Cost [i] [j] - T;
                        if ( T < Min ) Min = T;
                }
                out << Min << endl;
        }
}
 