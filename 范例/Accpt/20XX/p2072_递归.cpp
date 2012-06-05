#include <stdio.h>
#include <iostream>

using namespace std;

long long f ( long long , bool );

long long  A , B , NA;

main ()
{
     while ( cin >> A >> B ) {
           for ( NA = A; B; B -- , A = NA ) {
               NA = f ( A , false );
               if ( NA == 1 || A == NA ) break;
           }
           cout << NA << endl;
     }
}

long long f ( long long K , bool odd )
{
     if ( K <= 1 ) return K;
     if ( odd ) return f ( K / 2 , ( K & 1LL ) == 0LL ) * 2;
     else return f ( ( K + 1 ) / 2 , ( K & 1LL ) == 1LL ) * 2 - 1;
}
