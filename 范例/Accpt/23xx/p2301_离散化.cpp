#include <stdio.h>
#include <map>

using namespace std;

map <int,int> Dic;

int N , Pos [4020] , a [2000] , b [2000] , Len;
char col [2000];
bool Line [4020] , Point [4020];

main ()
{
     bool Put;
     int  la , lb , Max , t , Last;
     map <int,int> :: iterator Iter;
     while ( scanf ( "%d" , &N ) != EOF ) {
           for ( int i = 0; i < N; i ++ ) scanf ( "%d%d%c%c" , &a [i] , &b [i] , &col [i] , &col [i] );
           Dic.clear ();
           Dic [0] = 0;
           for ( int i = 0; i < N; i ++ ) Dic [a [i]] = 0 , Dic [b [i]] = 0;
           memset ( Line , 0 , sizeof ( Line ));
           memset ( Point , 0 , sizeof ( Point ));
           for ( Iter = Dic.begin () , Len = 0; Iter != Dic.end (); Iter ++ )
               Pos [Len] = Iter->first , Iter->second = Len ++;
           for ( int i = 0; i < N; i ++ ) {
               if ( a [i] > b [i] ) a [i] ^= b [i] ^= a [i] ^= b [i];
               Put = col [i] == 'w';
               la = Dic [a [i]] , lb = Dic [b [i]];
               for ( int k = la; k < lb; k ++ ) Point [k] = Line [k] = Put;
               Point [lb] = Put;
           }
           for ( int i = Max = Last = 0; i < Len; i ++ ) {
               if ( Point [i] ) Last ++; else Last = 0;
               if ( Last > Max ) Max = Last , t = Pos [i];
               if ( Line [i] || Pos [i + 1] - Pos [i] == 1 ) Last += Pos [i + 1] - Pos [i] - 1; else Last = 0;
               if ( Last > Max ) Max = Last , t = Pos [i + 1] - 1;
           }
           if ( Max == 0 ) {
                puts ( "Oh, my god" );
                continue;
           }
           printf ( "%d %d\n" , t - Max + 1 , t );
     }
}
