#include <stdio.h>
#include <iostream>

using namespace std;

int      MulMod ( long long , long long );

int      M;

void     solve ( long long , long long );

main ()
{
     long long P , m;
     while ( cin >> P >> m ) {
           solve ( P , m );
           cout << endl;
     }
}

void solve ( long long P , long long m )
{
     long long   t , np;
     for ( M = 1; m > 1; m -- ) M *= m;
     
     P %= M;
     for ( t = P;; P = np ) {
         np = MulMod ( t , P );
         if ( np == P ) break;
     } 
     cout << np << endl;
}

int  MulMod ( long long a , long long b )
{
     long long    t = a , Ret = 1;
     if ( b == 0 ) return 0;
     while ( b ) {
           if ( b & 1 ) Ret = ( Ret * t ) % M;
           t = ( t * t ) % M;
           b >>= 1;
     }
     return Ret;
}
