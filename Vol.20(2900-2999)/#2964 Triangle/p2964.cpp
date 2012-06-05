// 2951169 2008-06-16 22:15:49 Accepted 2964 C++ 00:00.16 844K 呆滞的慢板 

// 相当经典数论题，用欧拉函数有很强的结论：
// 问题是要找 a ^ l = a ^ m = a ^ n ( mod z )
// 其中 l > m > n > 0 并且 m + n > l
// 由于 a 与 z 互质，因此
// 如果求得最小正整数的 k 使得 a ^ k = 1 mod z
// 那么，如果 a ^ p = y
// a ^ ( p + ? * k ) = Y，即可实现同余

// 此时，问题转化为找一个最小的 k, 使得 a ^ k = mod z
// 然后一个以 k 为公差的等差数列（3 个数），则为结果
// 另外为满足 m + n > l，可以取： 
//     n = k + 1, m = 2k + 1, l = 3k + 1
//     即为满足条件的最小解 l + m + n = 6k + 3

// 下面是 k 的求法：
// 由费马小定理可知：a ^ phi(z) = 1 mod z, phi 是欧拉函数
// 然后，phi(z) 不是最小的，但是不难想到
// 一定存在 phi(z) 的某个因子，使得 a ^ k = 1 mod z
// 然后，先求出 phi(z)，在枚举他的因子，求出最小者即可

// 感谢 “和谐讨论”群的 [菜鸟也 AC] 和 曹鹏大牛 


#include <iostream>
using namespace std;

int phi( int n ) {

    int ret = 1;

    for( int i = 2; i * i <= n; i++ ) {

        if( n % i == 0 ) {
            n /= i;
            ret *= ( i - 1 );
            while( n % i == 0 ) {
                n /= i;
                ret *= i;
            }
        }
    
    }
        
    if( n > 1 )
        ret *= ( n - 1 );
    
    return ret;

}

int pw( const int& A, const int& K, const int& Z ) {
    
    if( K == 0 )
        return  1;
        
    long long P = pw( A, K >> 1, Z );
        
    if( K % 2 == 0 )
        return  P * P % Z;
    else
        return  ( P * P % Z * A ) %Z;
    
}

int main() {

    int     T,  A,  Z;
    
    for( scanf( "%d", &T ); T--; ) {
    
        scanf( "%d%d", &A, &Z );
        
        if( Z == 1 ) {
            puts( "9" );
            continue;
        }
    
        int step = phi( Z ),    ans;
        
        for( int i = 1; i * i <= step; ++i ) {
            if( step % i == 0 ) {
                if( pw( A, i, Z ) == 1 ) {
                    ans = i;
                    break;
                }
                if( pw( A, step / i, Z ) == 1 )
                    ans = step / i;
            }
        }
        
        cout << 6ll * ans + 3 << endl;
    
    }

}
