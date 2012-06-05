//#define DEBUG

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

int     Start , N , Total;
int     Line [20];
char    data [100];

void    init ()
{

        in >> Start >> N; in.getline( data , 100 );
        int     i , t;
        memset ( Line , 0 , sizeof ( Line )); Total = 0;
        for ( i = 0; i < N; i ++ ) {
                in.getline( data , 100 );
                istrstream rin ( data , 0 );
                while ( rin >> t ) { Line [t] ++; Line [i] ++; Total ++; }
        }
        in.getline( data , 100 );
}

bool    check ()
{
        int     oddnum = 0 , oddlast , i;
        for ( i = 0; i < N; i ++ ) if ( Line [i] % 2 ) {
                oddnum ++; oddlast = i;
        }
        return ( oddnum == 0 && Start == 0 ) || ( oddnum == 2 && oddlast == Start && oddlast );
}

main ()
{
        while ( in >> data , strstr ( data , "ENDOFINPUT" ) == NULL ) {
                init ();
                if ( check () ) out << "YES " << Total << endl;
                        else out << "NO" << endl;
        }
}
 