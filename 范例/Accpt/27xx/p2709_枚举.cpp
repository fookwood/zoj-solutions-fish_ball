#include <iostream>
#include <string.h>

using namespace std;

typedef unsigned long long int64;

struct TState {
       int    s [26] , n;
       int &  operator [] ( int Index ) { return s [Index]; }
       int    operator [] ( int Index ) const { return s [Index]; }
       int64  p ( TState & );
       void   print ();
       void   init ();
};

int    N;
TState Start , Min , Max;

int64 c ( int , int );
int64 gcd ( int64 , int64 );
void  solve ();

main ()
{
     while ( cin >> N ) {
           solve ();
           cout << endl;
     }
}

int64 gcd ( int64 a , int64 b )
{
      if ( b == 0 ) return a;
      return gcd ( b , a % b );
}

void solve ()
{
     Start.init ();
     Min = Max = Start;
     
     TState    TmpF;
     bool      first = true;
     
     for ( int j = Start.n; j < N; j ++ ) {
         first = true;
         for ( int i = 0; i < 26; i ++ ) if ( Min [i] ) {
             Min [i] ++;
             if ( first || Min.p ( Start ) < TmpF.p ( Start )) TmpF = Min;
             first = false;
             Min [i] --;
         }
         Min = TmpF;
         for ( int i = 0; i < 26; i ++ ) if ( Max [i] ) {
             Max [i] ++;
             if ( first || Max.p ( Start ) > TmpF.p ( Start )) TmpF = Max;
             first = false;
             Max [i] --;
         }
         Max = TmpF;
     }
     Max.print ();
     Min.print ();
}

int64 TState :: p ( TState & B )
{
      int64 Ret = 1;
      for ( int i = 0; i < 26; i ++ ) if ( s [i] )
          Ret *= c ( s [i] , B [i] );
      return Ret;
}

int64 c ( int a , int b )
{
      if ( a - b < b ) b = a - b;
      int64 Ret = 1;
      for ( int i = 1; i <= b; i ++ ) Ret = Ret * ( a - i + 1 ) / i;
      return Ret;
}

void  TState :: init ()
{
      char   str [200];
      cin >> str;
      n = strlen ( str );
      memset ( s , 0 , sizeof ( s ));
      for ( int i = 0; i < n; i ++ ) s [str [i] - 'A'] ++;
}

void TState :: print ()
{
     int64 Down = c ( N , Start.n ) , Up = p ( Start ) , g = gcd ( Down , Up );
     cout << Up / g << '/' << Down / g << endl;
}
