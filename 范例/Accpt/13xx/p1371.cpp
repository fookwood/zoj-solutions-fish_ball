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

int     N , M;
int     Policy;
int     Min , Max , Have;
int     Print [10000];
char    data;
int     Process [10001];

main ()
{
        bool    first = 1;
        int     i , t , Remove , Ans;
        while ( in >> N ) {
                if ( first ) first = 0; else out << endl;
                for ( in >> M , i = 0; i < M; i ++ ) in >> Print [i];

                for ( i = 1; i <= N; i ++ ) Process [i] = 0;
                Policy = 1; Min = 100000; Max = -1; Have = 0;
                Remove = 0; i = 0;
                while ( in >> data , data != 'e' ) {
                        if ( data == 'a' ) {
                                in >> t;
                                Have ++;
                                Process [t] ++;
                                if ( t < Min ) Min = t;
                                if ( t > Max ) Max = t;
                                continue;
                        }
                        if ( data == 'p' ) {
                                in >> t;
                                Policy = t;
                                continue;
                        }

                        Remove ++;
                        if ( Policy == 1 ) {
                                if ( Have ) {
                                        Ans = Min;
                                        Have --; Process [Min] --;
                                        if ( Have ) while ( !Process [Min] ) Min ++;
                                } else Ans = -1;
                        } else {
                                if ( Have ) {
                                        Ans = Max;
                                        Have --; Process [Max] --;
                                        if ( Have ) while ( !Process [Max] ) Max --;
                                } else Ans = -1;
                        }

                        if ( !Have ) { Min = 1000000; Max = -1; }
                        if ( i < M && Remove == Print [i] ) { out << Ans << endl; i ++; }
                }
                for ( ; i < M; i ++ ) out << "-1\n";
        }
}
 