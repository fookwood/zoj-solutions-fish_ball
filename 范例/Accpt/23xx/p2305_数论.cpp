#include <iostream>

using namespace std;

long long A , B , C , K;

bool     check ();
void     extended_gcd ( long long , long long , long long & , long long & , long long & );

main ()
{
     long long i;
     while ( cin >> A >> B >> C >> K , A || B || C || K ) {
           for ( i = K , K = 1; i; i -- ) K = K * 2;
//           cout << K << endl;
           if ( B > A ) B -= A; else B = K - ( A - B );
           if ( !check () ) cout << "FOREVER\n";
     }
}

bool check ()
{
     long long gcd , x , y;
     extended_gcd ( K , C , gcd , x , y );
     if ( B % gcd != 0 ) return false;
     K /= gcd , B /= gcd;
     cout << (( B * y ) % K + K ) % K << endl;
     return true;
}

void extended_gcd ( long long a , long long b , long long & gcd , long long &x , long long &y )
{
     if ( b == 0 ) gcd = a , x = 1 , y = 0;
     else extended_gcd ( b , a % b , gcd , y , x ) , y -= x * ( a / b );
}
