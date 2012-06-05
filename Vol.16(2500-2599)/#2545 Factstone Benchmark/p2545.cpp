// 2893100 2008-05-06 14:47:33 Accepted 2545 C++ 00:00.08 3968K 呆滞的慢板 

// 简单数论，做得比较血腥
// 要求不比 2^D 大的 N! ，输出 N
// 转化一下，即求 log( N! ) < log( 2^D )
// 即 log2( N! ) < D
// 即 sum( log2(i), i = 1..N ) < D
// 于是生成 sum( log2(i), i = 1..n ) 的部分和
// 然后二分 D 即可 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double  D[400000];

int main() {
    
    int     N;
    double  bit;
    const double log2 = log( 2.0 );

    D[0] = 0.0;
    for( int i = 1; i < 400000; ++i )
        D[i] = D[i - 1] + log( double( i ) ) / log2;

    while( ( cin >> N ) && N ) {

        N = ( N - 1960 ) / 10;
        bit = 4;
        while( N-- > 0 )    bit *= 2;
        cout << ( lower_bound( D, D + 400000, bit ) - D ) - 1 << endl;

    }
    
}
