//#define DEBUG

#include <iostream>

#ifdef DEBUG
#include <fstream>
#endif

using namespace std;

#ifdef DEBUG
        ifstream in ( "p.in" );
        ofstream out ( "p.out" );
        ofstream debug ( "debug.txt" );
#else
        istream & in = cin;
        ostream & out = cout;
#endif

const   int     Limit = 1600;

const   int     dx [4] = { 0 , 1 , 0 , -1 };
const   int     dy [4] = { 1 , 0 , -1 , 0 };
const   char    face [4] = { 'e' , 's' , 'w' , 'n' };


int     N , M;
int     bx , by , tx , ty , sx , sy;
char    Map [21] [21];
bool    Opt [21] [21] [4];

struct  TNode {
        int     px , py , pk;
        int     from;
};

int     Open , Closed , LastClosed;
TNode   Line [Limit];
int     Len [Limit];
char    Pass [Limit] [220];


struct  TNodeSub {
        int     x , y;
        int     from;
        char    Pre;
};

bool    Reach [21] [21];
int     OpenSub , ClosedSub;
TNodeSub LineSub [500];

bool    Range ( int x , int y ) { return x >= 0 && x < N && y >= 0 && y < M; } 

bool    Goal ( int x , int y ) { return x == tx && y == ty; }

int     Check ( int px , int py , int bx , int by )
{
        if ( px == bx ) {
                if ( py + 1 == by ) return 0;
                if ( py == by + 1 ) return 2;
        }
        if ( py == by ) {
                if ( px + 1 == bx ) return 1;
                if ( px == bx + 1 ) return 3;
        }
        return -1;
}

bool    init ()
{
        int     i , j;
        in >> N >> M;
        if ( N == 0 ) return false;
        for ( i = 0; i < N; i ++ ) for ( j = 0; j < M; j ++ ) {
                in >> Map [i] [j]; if ( Map [i] [j] == '.' || Map [i] [j] == '#' ) continue;
                if ( Map [i] [j] == 'B' ) { bx = i; by = j; }
                if ( Map [i] [j] == 'S' ) { sx = i; sy = j; }
                if ( Map [i] [j] == 'T' ) { tx = i; ty = j; }
                Map [i] [j] = '.';
        }
        return true;
}

void    Search ( int px , int py , int bx , int by , int father )
{
        int     k , tx , ty , t;

        Map [bx] [by] = '#';
        memset ( Reach , 0 , sizeof ( Reach ));
        LineSub [0].x = px; LineSub [0].y = py; Reach [px] [py] = 1;

        for ( OpenSub = 0 , ClosedSub = 1; OpenSub < ClosedSub; OpenSub ++ ) {
                for ( k = 0; k < 4; k ++ ) {
                        tx = LineSub [OpenSub].x + dx [k]; ty = LineSub [OpenSub].y + dy [k];
                        if ( !Range ( tx , ty ) || Reach [tx] [ty] || Map [tx] [ty] != '.' ) continue;
                        Reach [tx] [ty] = 1;
                        LineSub [ClosedSub].x = tx; LineSub [ClosedSub].y = ty; LineSub [ClosedSub].from = OpenSub; LineSub [ClosedSub].Pre = face [k];
                        ClosedSub ++;

                        t = Check ( tx , ty , bx , by );
                        if ( t >= 0 && !Opt [tx] [ty] [t] ) {
                                Opt [tx] [ty] [t] = 1;
                                Line [Closed].px = tx; Line [Closed].py = ty; Line [Closed].pk = t; Line [Closed].from = father;
                                Len [Closed] = 0;
                                for ( t = ClosedSub - 1; t; t = LineSub [t].from ) Pass [Closed] [Len [Closed] ++] = LineSub [t].Pre;
                                Closed ++;
                        }
                }
        }
        Map [bx] [by] = '.';
}

void    Prepare ()
{
        memset ( Opt , 0 , sizeof ( Opt ) );
        int     k;
        k = Check ( sx , sy , bx , by );
        Line [0].px = sx; Line [0].py = sy; Closed = 1;
        if ( k >= 0 ) { Line [0].pk = k; Open = 0; Opt [sx] [sy] [k] = 1; } else Open = 1;
        LastClosed = Open;
        Search ( sx , sy , bx , by , 0 );
}

int     BFS ()
{
        int     x , y , i , k , father;
        for ( ; Open < Closed; Open ++ ) {
                for ( i = LastClosed; i < Closed; i ++ ) {
                        k = Line [i].pk;
                        if ( Goal ( Line [i].px + dx [k] , Line [i].py + dy [k] ) ) return i;
                } LastClosed = Closed;

                k = Line [Open].pk; x = Line [Open].px + dx [k]; y = Line [Open].py + dy [k];
                if ( !Range ( x + dx [k] , y + dy [k] ) || Map [x + dx [k]] [y + dy [k]] != '.' ) continue;
                if ( Opt [x] [y] [k] ) continue; Opt [x] [y] [k] = 1;

                Line [Closed].px = x; Line [Closed].py = y; Line [Closed].pk = k; Line [Closed].from = Open;
                Len [Closed] = 1; Pass [Closed] [0] = face [k] + 'A' - 'a'; father = Closed; Closed ++;

                Search ( x , y , x + dx [k] , y + dy [k] , father );
        }
        return -1;
}

void    PrintAns ( int p )
{
        if ( !p ) return; PrintAns ( Line [p].from );
        int     i;
        for ( i = Len [p] - 1; i >= 0; i -- )
                out << Pass [p] [i];
}

main ()
{
        int     i;
        int     state , step = 0;

        while ( init () ) {
                step ++; out << "Maze #" << step << endl;
                Prepare ();
                state = BFS ();

                if ( state == - 1 ) out << "Impossible.\n";
                else { PrintAns ( state ); out << endl; } out << endl;
        }
}
