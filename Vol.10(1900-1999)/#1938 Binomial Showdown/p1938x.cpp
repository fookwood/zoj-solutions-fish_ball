// 我郁闷了 n 久，永远也不知道为什么这样都 TLE 

#include <iostream>
using namespace std;

int main() {
    double  sum;
    int     i,  n,  k;
    while( ( cin >> n >> k ) && ( k || n ) ) {
        sum = 1.0;
        if( k + k > n ) k = n - k;  
        // 就是这里出事，一个很大的 k，加起来成了一个负数，那就循环死了 
        for( i = 1; i <= k; i++ )
            sum *= ( double( n - k + i ) / double( i ) );
        cout << int( sum ) << endl;
    }
    return  0;
}
