#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string,int> Dic;
int N , Max [10000] , Pre [10000] , Ans , Pos_ , Next [10000] , Bucket [21];
string Data [10000] , Sort [10000];

void   init ();
void   Work ();
bool   Input ( string & );
void   Print ( int );

main ()
{
     int Total;
     for ( cin >> Total; Total; Total -- ) {
         init ();
         Work ();
         Print ( Pos_ );
         if ( Total > 1 ) cout << endl;
     }
     
}

void Print ( int k )
{
     if ( k == -1 ) return;
     Print ( Pre [k] );
     cout << Data [k] << endl;
}

void Work ()
{
     memset ( Max , 0 , sizeof ( Max ));
     int  i , j , len , l;
     map <string,int> :: iterator Iter;
     
     string Tmp;
     Ans = 0;
     for ( l = 1; l <= 20; l ++ )
     for ( i = Bucket [l]; i != -1; i = Next [i] ) {
         Pre [i] = -1;
         len = Sort [i].length ();
         if ( len == 1 ) { Max [i] = 1; continue; }
         Pre [i] = -1;
         for ( j = 0; j < len; j ++ ) {
             Tmp = Sort [i] , Tmp.erase ( j , 1 );
             Iter = Dic.find ( Tmp );
             if ( Iter != Dic.end () && Max [Iter->second] > Max [i] ) Max [i] = Max [Iter->second] , Pre [i] = Iter->second;
         }
         Max [i] ++;
         if ( Max [i] > Ans ) Ans = Max [i] , Pos_ = i;
     }
}

void init ()
{
     Dic.clear ();
     N = 0;
     int len , i , j;
     char    T;
     memset ( Bucket , 0xff , sizeof ( Bucket ));
     while ( true ) {
           if ( N == 0 ) while ( !Input ( Data [0] ));
           else if ( !Input ( Data [N] ) ) break;
           Sort [N] = Data [N];
           len = Sort [N].length ();
           Next [N] = Bucket [len] , Bucket [len] = N;
           for ( i = 0; i < len; i ++ )
               for ( j = i + 1; j < len; j ++ ) if ( Sort [N] [i] > Sort [N] [j] )
                   T = Sort [N] [i] , Sort [N] [i] = Sort [N] [j] , Sort [N] [j] = T;
           Dic [Sort [N]] = N;
           N ++;
     }
}

bool Input ( string & a )
{
     char  Tmp [40];
     if ( !cin.getline ( Tmp , 40 ) || Tmp [0] == 0 ) return false;
     a = (string) Tmp;
     return true;
}
