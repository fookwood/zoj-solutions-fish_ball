// 2955573 2008-06-24 01:14:40 Accepted 2072 C++ 00:00.04 840K 呆滞的慢板 

// n = 2 的 Josephu 环函数 J(n) 有一个很强的结论
// J(n) = ROL(n) ROL 即循环左移
// 注意，循环是按最大二进制长度作循环的
// 然后，如果 潜逃无限次，最终将收敛到全 1 的局面
// 每次判别一下是不是已经收敛完全了，是则跳出
// 这样就可以对付嵌套次数超大的情况了 

#include <iostream>
using namespace std;

typedef unsigned long long u64;

int main () {
    
    u64 n,  k,  p,  v;
    
    while( cin >> n >> k ) {
        
        while( k-- ) {
            p = 1;
            while( p <= n )
                p <<= 1;
            v = n;
            n <<= 1;
            n ^= p;
            n |= 1;
            if( v == n )
                break;
        }
        
        cout << n << endl;
        
    }
    
}
