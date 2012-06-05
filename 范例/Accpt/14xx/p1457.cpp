// Zju 1457 Search

#include <stdio.h>
#include <vector>

using namespace std;

bool    Prime [40];
bool    used [20];
int     N;
        
vector <int> Stack;

void    PrimeIt ()
{
        int     i , j;
        for ( i = 2; i < 40; i ++ ) Prime [i] = 1;
        for ( i = 2; i < 40; i ++ ) if ( Prime [i] )
                for ( j = i << 1; j < 40; j += i ) Prime [j] = 0;
}

void    Search ( int depth )
{
        int     k = Stack.back();
        int     i , *p;

        if ( depth == N ) {
                if ( Prime [k + 1] ) {
                        /*k = 1;
                        for ( p = Stack.begin(); p != Stack.end(); p ++ ) {
                                if ( k ) k = 0; else printf ( " " );
                                printf ( "%d" , *p );
                        }
                        */
                        k = Stack.size();
                        printf ( "1" );
                        for ( i = 1; i < k; i ++ ) printf ( " %d" , Stack.at( i ) );
                        
                        printf ( "\n" );
                }
                return;
        }
        
        for ( i = 2; i <= N; i ++ ) if ( !used [i] && Prime [k + i] ) {
                used [i] = 1;
                Stack.push_back( i );
                Search ( depth + 1 );
                Stack.pop_back();
                used [i] = 0;
        }
}

main ()
{
        int     step = 0;
        PrimeIt ();
        while ( scanf ( "%d" , & N ) != EOF ) {
                step ++;
                printf ( "Case %d:\n" , step );
                Stack.clear();
                memset ( used , 0 , N + 1 );
                Stack.push_back ( 1 );
                if ( N % 2 == 0 ) Search ( 1 );
                printf  ( "\n" );
        }
}
 