#include <iostream.h>

const   int dx [4] = { 1 , -1 , 0 , 0 };
const   int dy [4] = { 0 , 0 , -1 , 1 };


int     part , p;
int     n;
int     change [16];
int     map [20] [20] [2];

void    readin ()
{
        cin >> n;
        
        for ( int i = 0; i < 16; i ++ ) cin >> change [i];
        for ( int i = 0; i < 20; i ++ )
                for ( int j = 0; j < 20; j ++ )
                        cin >> map [i] [j] [0];
}

void    Work ()
{
        int     a = 0 , b = 1 , i , j;
        int     k , s;
        for ( ; n ; n -- ) {
        
                for ( i = 0; i < 20 ; i ++ )
                        for ( j = 0; j < 20 ; j ++ ) {
                                s = map [i] [j] [a];
                                for ( k = 0; k < 4; k ++ )
                                        if ( i + dx [k] >=0
                                        && i + dx [k] < 20
                                        && j + dy [k] >= 0
                                        && j + dy [k] < 20 ) s += map [i + dx [k]] [j + dy [k]] [a];

                                map [i] [j] [b] = map [i] [j] [a] + change [s];
                                if ( map [i] [j] [b] < 0 ) map [i] [j] [b] = 0;
                                if ( map [i] [j] [b] > 3 ) map [i] [j] [b] = 3;
                        }
                a = 1 - a;
                b = 1 - b;
        }

        for ( i = 0; i < 20 ; i ++ ) {
                for ( j = 0; j < 20 ; j ++ )
                        if ( map [i] [j] [a] == 3 ) cout << '#';
                                else if ( map [i] [j] [a] == 2 ) cout << 'X';
                                else if ( map [i] [j] [a] == 1 ) cout << '!';
                                else cout << '.';
                cout << endl;
        }
}


main ()
{
        cin >> part;
        for ( p = 0 ; p < part ; p ++ ) {
                if ( p > 0 ) cout << endl;
                readin ();
                Work ();
        }



}
 