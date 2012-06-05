#include <bitset>
#include<iostream>
using namespace std;

typedef long long i64;

// Calculates a^b mod n
i64 mod_exp(i64 a, i64 b, i64 n) {
    i64 d = 1, i = 0;
    while( i64(1)<<i < b ) ++i;
    for( ; i >= 0; --i ) {
        d = (d * d) % n;
        if( i64(1)<<i & b )
            d = (d * a) % n;
    }
    return d;
}

bool witness( i64 a, i64 n ) {
    i64 t = 0, u = n - 1;
    while( (u & i64(1)) == 0 ) {
        u >>= 1;
        t += 1;
    }
    i64 x = mod_exp(a, u, n);
    for(int i = 1; i <= t; ++i) {
        i64 xx = x * x % n;
        if(xx == 1 && x != 1 && x != n-1 )
            return true;
        x = xx;
    }
    return x != 1;
}

bool isPrime(i64 n, i64 s) {
    if(n < 10000) {
        for( int i = 2; i * i <= n; ++i )
            if(n % i == 0)
                return false;
        return true;
    }
    while(s--) {
        i64 a = rand() % (n-1);
            if( witness(a, n) )
                return false;
    }
    return true;
}

int main() {
    int x;
    while( scanf( "%d", &x ) != EOF ) {
        if( x <= 1 ) {
            puts( "NO" );
            continue;
        }
        if( 1||x > 100 ) {
            puts( x != 1 && isPrime(x, 50) ? "YES" : "NO" );
            continue;
        }
        bool yes = true;
        for(long long i = 2; i * i <= x; ++i ) {
            if( x % i == 0 ) {
                yes = false;
                break;
            }
        }
        puts( yes ? "YES" : "NO" );
    }
}
