#include <iostream.h>

const   int     num [3] [3] = { 0 , 1 , 2 , 7 , 8 , 3 , 6 , 5 , 4 };

struct  TNode {
        char    Present [9];
}       Data [6];

void    init ()
{
        int     i , j , k;
        for ( i = 0; i < 3; i ++ )
                for ( j = 0; j < 3; j ++ ) cin >> Data [4].Present [num [i] [j]];
        for ( i = 0; i < 3; i ++ )
                for ( k = 0; k < 4; k ++ )
                        for ( j = 0; j < 3; j ++ ) cin >> Data [k].Present [num [i] [j]];
        for ( i = 0; i < 3; i ++ )
                for ( j = 0; j < 3; j ++ ) cin >> Data [5].Present [num [i] [j]];
}

bool    check ()
{
        int     i , k;
        for ( k = 0; k < 6; k ++ )
                for ( i = 0; i < 8; i ++ ) if ( Data [k].Present [i] != Data [k].Present [i + 1] ) return false;
                return true;
}

void    ChangeSelf ( TNode &Self )
{
        char    t1 = Self.Present [0] , t2 = Self.Present [1];
        for ( int i = 0; i < 6; i ++ ) Self.Present [i] = Self.Present [i + 2];
        Self.Present [6] = t1 , Self.Present [7] = t2;
}

void    ChangeFour ( TNode &a , int Sa , TNode &b , int Sb , TNode &c , int Sc , TNode &d , int Sd )
{
        char    Tmp;
        for ( int i = 0; i < 3; i ++ , Sa = ( Sa + 1 ) % 8 , Sb = ( Sb + 1 ) % 8 , Sc = ( Sc + 1 ) % 8 , Sd = ( Sd + 1 ) % 8 )
                Tmp = a.Present [Sa] , a.Present [Sa] = b.Present [Sb] , b.Present [Sb] = c.Present [Sc] , c.Present [Sc] = d.Present [Sd] , d.Present [Sd] = Tmp;
}

main ()
{
        int     total , state , Limit , i;
        for ( cin >> total; total; total -- ) {
                init ();
                while ( cin >> state , state != 0 ) {
                        if ( state < 0 ) state = -state , Limit = 1; else Limit = 3;
                        for ( i = 0; i < Limit; i ++ )
                                switch ( state ) {
                                        case    1:      ChangeFour ( Data [4] , 6 , Data [1] , 6 , Data [5] , 6 , Data [3] , 2 ) , ChangeSelf ( Data [0] );
                                                break;
                                        case    2:      ChangeFour ( Data [4] , 4 , Data [2] , 6 , Data [5] , 0 , Data [0] , 2 ) , ChangeSelf ( Data [1] );
                                                break;
                                        case    3:      ChangeFour ( Data [4] , 2 , Data [3] , 6 , Data [5] , 2 , Data [1] , 2 ) , ChangeSelf ( Data [2] );
                                                break;
                                        case    4:      ChangeFour ( Data [4] , 0 , Data [0] , 6 , Data [5] , 4 , Data [2] , 2 ) , ChangeSelf ( Data [3] );
                                                break;
                                        case    5:      ChangeFour ( Data [3] , 0 , Data [2] , 0 , Data [1] , 0 , Data [0] , 0 ) , ChangeSelf ( Data [4] );
                                                break;
                                        case    6:      ChangeFour ( Data [1] , 4 , Data [2] , 4 , Data [3] , 4 , Data [0] , 4 ) , ChangeSelf ( Data [5] );
                                                break;
                                }
                }
                if ( check () ) cout << "Yes, grandpa!\n";
                        else cout << "No, you are wrong!\n";
        }
}
 