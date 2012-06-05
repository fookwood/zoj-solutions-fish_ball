// 经典 Josephu 环 问题，m = 2 的情形，有超强的算法
// 即将 n 循环左移 1 位即可，具体说明见解题报告
// 2885671 2008-05-03 01:39:13 Accepted 2239 C++ 00:00.00 388K 呆滞的慢板

#include <cstdio>

int main() {
    
    int     x,  e;
    
    while( scanf( "%de%d", &x, &e ) && x ) {
        
        while( e-- ) x *= 10;
        for( e = 1; e <= x; e <<= 1 );
        printf( "%d\n", ( x << 1 ) - e + 1 );
        
    }
    
}
