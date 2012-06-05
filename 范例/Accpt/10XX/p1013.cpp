#define  DEBUG

#include <iostream>

using namespace std;

#ifdef DEBUG
#include <fstream>
#endif

#ifdef DEBUG
        ofstream fout ( "p.out" );
        ostream & out = fout;
        ifstream fin ( "p.in" );
        istream & in = fin;
        ofstream fdebug ( "debug.txt" );
#else
        istream & in = cin;
        ostream & out = cout;
#endif

const   int     MAX_C   = 200;

int     Have [3];
int     Use [3] [2] , Capab [3] , TotalCapab;
int     Opt [MAX_C] [MAX_C] [2];
int     n;
int     Limit [100] [2];

void    init ()
{
        int     i;
        for ( i = 0; i < 3; i ++ ) 
                in >> Use [i] [0] >> Use [i] [1] >> Capab [i];

        for ( i = 0; i < 3; i ++ )
                in >> Have [i];

        in >> TotalCapab;

        for ( i = 0; i < n; i ++ )
                in >> Limit [i] [0] >> Limit [i] [1];
}

int     Value ( int a , int b , int t )
{
        int     c = Opt [a] [b] [t];

        if ( c < 0 ) return -1;

        int     Small;
        int     ret;
        int     One;
        int     MaxL;

        One = Have [0] * Capab [0] + Have [1] * Capab [1] + Have [2] * Capab [2];

        if ( TotalCapab > One ) One = TotalCapab;

        MaxL = 99999999;
        if ( Have [0] != 0 ) MaxL = min ( MaxL , a / Have [0] );
        if ( Have [1] != 0 ) MaxL = min ( MaxL , b / Have [1] );
        if ( Have [2] != 0 ) MaxL = min ( MaxL , c / Have [2] );

        #ifdef DEBUG
                fdebug << a << ' ' << b << ' ' << c << endl; 
        #endif

        ret = One * MaxL + Capab [0] * ( a - Have [0] * MaxL )
                + Capab [1] * ( b - Have [1] * MaxL )
                + Capab [2] * ( c - Have [2] * MaxL );
        
        return ret;
}

int     Dp ()
{
        int     a = 0 , b = 1;
        int     i , j , k , ai , aj;
        int     ua , ub;
        int     ua2 , ub2;
        int     l;
        int     ret;

        for ( i = 0; i < MAX_C; i ++ )
                for ( j = 0; j < MAX_C; j ++ ) Opt [i] [j] [a] = -1;
        Opt [0] [0] [a] = 0;

        for ( k = 0; k < n; k ++ ) {
                for ( i = 0; i < MAX_C; i ++ ) for ( j = 0; j < MAX_C; j ++ ) Opt [i] [j] [b] = -1;

                for ( i = 0; i < MAX_C; i ++ )
                        for ( j = 0; j < MAX_C; j ++ ) {
                                if ( Opt [i] [j] [a] < 0 ) continue;

                                for ( ai = 0; ai + i < MAX_C; ai ++ ) {
                                        ua = ai * Use [0] [0]; ub = ai * Use [0] [1];
                                        if ( ua > Limit [k] [0] || ub > Limit [k] [1] ) break;

                                        for ( aj = 0; aj + j <MAX_C; aj ++ ) {
                                                ua2 = ua + aj * Use [1] [0]; ub2 = ub + aj * Use [1] [1];
                                                if ( ua2 > Limit [k] [0] || ub2 > Limit [k] [1] ) break;

                                                l = Opt [i] [j] [a] + min ( ( Limit [k] [0] - ua2 ) / Use [2] [0] , ( Limit [k] [1] - ub2 ) / Use [2] [1] );

                                                if ( Opt [i + ai] [j + aj] [b] < l ) Opt [i + ai] [j + aj] [b] = l;

                                        }
                                }
                        }
                a = 1 - a;
                b = 1 - b;
        }

        ret = 0;
        for ( i = 0; i < MAX_C; i ++ )
                for ( j = 0; j < MAX_C; j ++ ) {
                        k = Value ( i , j , a );
                        if ( k > ret ) ret = k;
                }
        return ret;
}

main ()
{
        int     step = 0;
        while ( in >> n , n ) {
                if ( step ) out << endl;
                step ++;
                init ();
                out << "Case " << step << ": " << Dp () << endl;
        }
}
