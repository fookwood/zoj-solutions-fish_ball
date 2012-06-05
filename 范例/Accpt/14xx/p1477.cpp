#include <iostream>
#include <string>
using   namespace std;

//#define DEBUG
#ifdef  DEBUG
        #include <fstream>
        ifstream in ( "p.in" );
        ofstream out ( "p.out" );
        #define cin in
        #define cout out
#endif

string  Order , Code;
int     Num [110] , len;
bool    Used [110];

void    Sort ()
{
        int     i , j , t;
        bool    flag;
        for ( i = 0; i < len; i ++ ) Num [i] = i;
        for ( i = 0; i < len; i ++ ) {
                flag = false;
                for ( j = len - 2; j >= i; j -- )
                        if ( Code [Num [j]] > Code [Num [j + 1]] )
                                t = Num [j] , Num [j] = Num [j + 1] , Num [j + 1] = t , flag = true;
                if ( !flag ) return;
        }
}

string  EnCode ()
{
        string  Ret;
        Ret.resize( len );
        for ( int i = 0; i < len; i ++ )
                Ret [i] = Num [i] ? Code [Num [i] - 1] : Code [len - 1];
        return  Ret;
}

string  DeCode ()
{
        string  Ret;
        Ret.resize( len );
        int     i , j , k;
        char    Next;

        memset ( Used , 0 , sizeof ( Used ));
        for ( i = 0; Code [Num [i]] != Code [len]; i ++ );
        for ( k = 1 , j = 0; k < len; k ++ ) {
                Used [i] = true , Ret [j] = Code [Num [i]];
                if ( j ) j --; else j = len - 1;
                for ( Next = Code [i] , i = len - 1; Used [i] || Code [Num [i]] != Next; i -- );
        }       Ret [j] = Code [Num [i]];
        return  Ret;
}

main ()
{
        while ( cin >> Order >> Code ) {
                len = Code.length();
                if ( Order == "decode" ) len --;
                Sort ();
                if ( Order == "encode" ) cout << EnCode () << endl;
                        else cout << DeCode () << endl;
        }
}
 