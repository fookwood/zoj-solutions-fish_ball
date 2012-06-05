#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define cin fin
#define cout fout
ifstream fin ("input");
ofstream fout ( "p.out" );
#endif

main ()
{
     string  Str;
     char    Data [10000];
     while ( cin.getline(Data,sizeof(Data)) ) {
           Str = (string) Data;
           int len = Str.length () , i , j;
           for ( i = 0; i < len; i = j ) {
               for ( j = i + 1; j < len && j - i < 9 && Str [j] == Str [i]; j ++ );
               if ( j - i > 1 ) {
                    cout << j - i << Str [i];
                    continue;
               }
               for ( j = i + 1; j < len && Str [j] != Str [j - 1]; j ++ );
               if ( j < len && Str [j] == Str [j - 1] ) j --;
               cout << '1';
               for ( ; i < j; i ++ ) {
                     cout << Str [i];
                     if ( Str [i] == '1' ) cout << '1';
               }
               cout << '1';
           }
           cout << endl;
     }
}
