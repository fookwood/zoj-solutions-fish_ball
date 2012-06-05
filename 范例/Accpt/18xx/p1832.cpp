#include <stdio.h>
#include <string>
#include <map>
#define MAXN 300

using namespace std;

typedef map < string , int > TMap;

int     N;
string  Info [MAXN] , Ans;
TMap    Map , Map2;

bool    init ();
void    solve ();
bool    check ();

main ()
{
     while ( init () ) {
           solve ();
     }
}

bool check ()
{
     TMap :: iterator  Iter , Iter2;
     Map2 = Map;
     string next;
     int  len = Ans.length () , len1;
     for ( Iter = Map2.begin (); Iter != Map2.end (); Iter ++ )
         for ( ; Iter->second; ) {
             Iter -> second --;
             len1 = Iter->first.length ();
             
             if ( len1 > len ) return false;
             if ( Ans.substr ( 0 , len1 ) == Iter->first ) {
                  next = Ans.substr ( len1 , len - len1 );
                  Iter2 = Map2.find ( next );
                  if ( Iter2 == Map2.end () || Iter2->second == 0 ) break;
                  Iter2->second --;
                  continue;
             }             
             if ( Ans.substr ( len - len1 , len1 ) == Iter->first ) {
                  next = Ans.substr ( 0 , len - len1 );
                  Iter2 = Map2.find ( next );
                  if ( Iter2 == Map2.end () || Iter2->second == 0 ) break;
                  Iter2->second --;
                  continue;
             }
             return false;
         }
     return true;
}


void solve ()
{
     TMap  :: iterator Iter;
     Map.clear ();
     for ( int i = 0; i < N; i ++ ) {
         Iter = Map.find ( Info [i] );
         if ( Iter == Map.end () ) Map [Info [i]] = 0 , Iter = Map.find ( Info [i] );
         Iter->second ++;
     }
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < N; j ++ ) if ( i != j ) {
             Ans = Info [i] + Info [j];
             if ( check ()) {
                  printf ( "%s\n" , Ans.c_str ());
                  return;
             }
         }
}

bool init ()
{
     char str [400];
     if ( scanf ( "%s\n" , str ) == EOF ) return false;
     N = 0;
     Info [N ++] = (string) str;
     for ( ;gets ( str ) && str [0]; )
         Info [N ++] = (string) str;
     return true;
}
