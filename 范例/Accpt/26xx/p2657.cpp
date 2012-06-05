#include <iostream>

using namespace std;

long long X , Y , m , n , L;

void extended ( long long a , long long b , long long &gcd , long long &x , long long &y )
{
     if ( b == 0 ) gcd = a , x = 1 , y = 0;
     else extended ( b , a % b , gcd , y , x ) , y -= x * ( a / b );
}

bool check ()
{
     long long x , y , gcd;
     m = (( m - n ) % L + L ) % L , n = (( Y - X ) % L  + L ) % L;
     extended ( L , m , gcd , x , y );
     if  ( n % gcd ) return false;
     n /= gcd , L /= gcd;
     cout << ( ( n * y ) % L + L ) % L << endl;
     return true;
}

main ()
{
     while ( cin >> X >> Y >> m >> n >> L ) {
           if ( !check () ) cout << "Pat\n";
     }
}
