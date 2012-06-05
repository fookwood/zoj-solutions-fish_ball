#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAX 1000
#define Pi      3.141592657
using namespace std;

struct  TNode {
        int     x , y;
};

int     N , L;
vector  <TNode> Node;

bool    check ( int a , int b , int c , int d )
{
        return a * d >= b * c;         
}

void    WorkForPol ()
{
        int     i , Last , Next;
        bool    change = true;
        while ( change ) {
                change = false;
                for ( i = 0; i < Node.size(); i ++ ) {
                        Last = i - 1; Next = i + 1;
                        if ( Last < 0 ) Last += Node.size();
                        if ( Next == Node.size() ) Next = 0;
                        if ( check ( Node [Next].x - Node [i].x , Node [Next].y - Node [i].y , Node [Last].x - Node [i].x , Node [Last].y - Node [i].y ) ) {
                                Node.erase( Node.begin() + i );
                                i --; change = true;
                        }
                }
        }
/*        printf ( "%d\n" , Node.size() );
        for ( i = 0; i < Node.size (); i ++ )
                printf ( "%d %d\n" , Node [i].x , Node [i].y );
*/
}

double  dis ( TNode &a , TNode &b )
{
        return sqrt ( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

double  add ( TNode &a , TNode &b , TNode &c )
{
        int     tmp = ( a.x - b.x ) * ( c.x - b.x ) + ( a.y - b.y ) * ( c.y - b.y );
        double  l1 = dis ( a , b );
        double  alfa = acos ( double ( tmp ) / l1 / dis ( b , c ) );
        return  ( Pi - alfa ) * L + l1;
}

int     Ans ()
{
        double  ret = 0;
        int     i , Last , Next;
        for ( i = 0; i < Node.size(); i ++ ) {
                Last = i - 1; Next = i + 1;
                if ( Last < 0 ) Last += Node.size();
                if ( Next == Node.size() ) Next = 0;
                ret += add ( Node [Last] , Node [i] , Node [Next] );
        }
        return  int ( ret + 0.5 );
}

main ()
{
        // wall.a d.out
        freopen ( "wall.01" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total , i;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                scanf ( "%d%d" , &N , &L );
                Node.resize( N );
                for ( i = 0; i < N; i ++ ) scanf ( "%d%d" , &Node [i].x , &Node [i].y );
                WorkForPol ();
                printf ( "%d\n" , Ans () );
                if ( total > 1 ) printf ( "\n" );
        }
}
 