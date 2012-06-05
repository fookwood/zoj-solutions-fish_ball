// 2954149 2008-06-21 17:56:35 Accepted 2996 C++ 00:00.00 832K 呆滞的慢板 

// 求 C(m, n) 模 2

// 知道 C(m, n) = m! / n! / (m-n)!
// 那么，分子和分母的 2 因子数相减，大于零则结果为 0，否则为 1

// 下面算法在 log(n) 时间求出 n! 中 2 的因子数:
// 显然，n! = n * n-1 * ... * 1
// 那么因子数应该为 <= n 的所有 2 因子数的和
// 先提出一个二因子，共有 total += n / 2 个
// 然后 n /= 2
// 注意，剩下的继续进行，直到 n = 0
// 这样，如果一个数有多个 2 因子，也都会被算上 

#include <iostream>
using namespace std;

int f2( int x ) {
    int ans = 0;
    while( x >>= 1 ) ans += x;
    return  ans;
}

int main() {
    
    int m,  n,  k;
    
    while( cin >> m >> n ) {
        k = m - n;
        if( f2( m ) - f2( n ) - f2( k ) > 0 )
                puts( "0" );
        else    puts( "1" );
    }
    
}
