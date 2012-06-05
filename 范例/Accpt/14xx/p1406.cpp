// zju 1406
//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream>
#include <fstream>
using namespace std;

ifstream in ( "p.in" );
ofstream out ( "p.out" );

int     N;
int     dis [26] [26];

void    init ()
{
        int     i , j , tot , t;
        char    ch1 , ch2;
        memset ( dis , 0xff , sizeof ( dis ));
        for ( i = 0; i + 1 < N; i ++ ) {
                in >> ch1 >> tot;
                for ( j = 0; j < tot; j ++ ) {
                        in >> ch2 >> t;
                        dis [ch1 - 'A'] [ch2 - 'A'] = t;
                        dis [ch2 - 'A'] [ch1 - 'A'] = t;                        
                }
        }
}

int     Prim ()
{
        bool    Reach [26] = {false};
        int     Min [26];
        int     i , j , k , ret = 0;

        Reach [0] = 1;
        
        for ( i = 0; i < N; i ++ )
                Min [i] = dis [0] [i];
        Min [0] = 0;

        for ( i = 1; i < N; i ++ ) {
                k = -1;
                for ( j = 1; j < N; j ++ ) if ( !Reach [j] && Min [j] != -1 )
                        if ( k == -1 || Min [j] < Min [k] ) k = j;

                ret += Min [k];
                Reach [k] = 1;
                for ( j = 1; j < N; j ++ ) if ( !Reach [j] && dis [k] [j] != -1 )
                        if ( Min [j] == -1 || Min [j] > dis [k] [j] )
                                Min [j] = dis [k] [j];

        }
        return ret;
}

int main(int argc, char* argv[])
{
        while ( in >> N , N ) {
                init ();
                out << Prim () << endl;
        }
        return 0;
}
//---------------------------------------------------------------------------
 