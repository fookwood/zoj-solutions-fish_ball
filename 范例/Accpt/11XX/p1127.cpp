#define DEBUG

#include <iostream>

#ifdef DEBUG
        #include <fstream>
#endif

using namespace std;

#ifdef DEBUG
        ofstream fdebug ( "debug.txt" );
        
        fstream infile ( "p.in" );
        istream & in = infile;
        fstream outfile ( "p.out" );
        ostream & out = outfile;

#else
        istream & in = cin;
        ostream & out = cout;
#endif

int     N , Total;
bool    edge [26] [26];
int     choose [26];
bool    fortify [26];
int     value [26];
char    first;

void    init ()
{
        int     i;
        char    a , b;
        in >> N >> first >> Total;

        memset ( fortify , 0 , sizeof ( fortify ));
        memset ( edge , 0 , sizeof ( edge ));

        for ( i = 1; i < N; i ++ ) {
                in >> a >> b;
                edge [a - 'A'] [b - 'A'] = 1;
                edge [b - 'A'] [a - 'A'] = 1;
        }

        fortify [first - 'A'] = 1;
}

int     fix ( int p )
{
        int     i , j , k;
        int     searched [26];

        for ( i = 0; i < N; i ++ )
                if ( fortify [i] ) value [i] = 0;
                        else value [i] = 99999;

        for ( i = 0; i < N; i ++ ) searched [i] = 0;

        for ( i = 0; i < N; i ++ ) {
                k = -1;
                for ( j = 0; j < N; j ++ )
                        if ( !searched [j] ) 
                        if ( k < 0 || value [j] < value [k] ) k = j;
                if ( k < 0 ) break;
                searched [k] = 1;
                for ( j = 0; j < N; j ++ )
                        if ( !searched [j] )
                        if ( edge [k] [j] && value [k] + 1 < value [j] )
                                value [j] = value [k] + 1;
        }

        j = -1;

        #ifdef DEBUG
                for ( i = 0; i < N; i ++ )
                        fdebug << value [i] << ' ';
                fdebug << endl;
        #endif

        for ( i = 0; i < N; i ++ )
                if ( !fortify [i] )
                        if ( j < 0 || value [j] < value [i] ) j = i;
        fortify [j] = 1;
        return j;
}

main ()
{
        init ();
        out << "Program 8 by team X" << endl;

        out << first;
        for ( int i = 1; i < Total; i ++ )
                out << " " << char ( fix ( i ) + 'A' );

        out << endl;
        out << "End of program 8 by team X" << endl;
}



