#define DEBUG

#include <iostream>
#include <strstream>
#include <fstream>

using namespace std;

#ifdef DEBUG
        ifstream in ( "p.in" );
        ofstream out ( "p.out" );
#else
        istream & in = cin;
        ostream & out = cout;
#endif

int     N;
char    data [100];
int     Len;
int     Ansa [100] , Ansb [100];

bool    init ()
{
        int     i , a , b;
        in.getline( data , 100 ); 
        istrstream sin ( data , strlen ( data ) + 1 );
        N = 1;
        sin >> a; if ( a == 0 ) return false;
        sin >> b; for ( i = 0; i < b; i ++ ) N *= a;
        while ( sin >> a ) {
                sin >> b;
                for ( i = 0; i < b; i ++ ) N *= a;
        }
        N --;
        return true;
}

void    Part ()
{
        int     i;
        int     t;
        Len = 0;
        for ( i = 2; i <= N; i ++ ) if ( N % i == 0 ) {
                for ( t = 0; N % i == 0; N /= i ) t ++;
                Ansa [Len] = i; Ansb [Len] = t;
                Len ++;
        }
        for ( i = Len - 1; i >= 0; i -- ) {
                out << Ansa [i] << ' ' << Ansb [i];
                if ( !i ) out << endl;
                        else out << ' ';
        }
}

main ()
{
        while ( init ()) Part ();
}
 