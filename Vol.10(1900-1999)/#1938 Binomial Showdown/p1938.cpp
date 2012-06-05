#include <iostream>
using namespace std;

int main() {
    double  sum;
    int     i,  n,  k;
    while( ( cin >> n >> k ) && ( k || n ) ) {
        sum = 1.0;
        if( k > n - k ) k = n - k;
        for( i = 1; i <= k; i++ )
            sum *= ( double( n - k + i ) / double( i ) );
        // 这里乘个这样的书是为了防止 int( 1.9999999999... ) = 1 之类的情况 
        cout << int( sum * 1.000000000001 ) << endl;
    }
}
