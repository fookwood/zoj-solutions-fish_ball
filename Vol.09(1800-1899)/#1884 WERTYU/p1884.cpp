// 2942592 2008-06-04 22:22:00 Accepted 1884 C++ 00:00.00 384K 呆滞的慢板 

// 用手指在键盘上一拉.... 

#include <cstdio>
#include <cstring>

char    L[128] = { 0 };
char*   P = "`1234567890-=\tQWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main() {
    
    L[' '] = ' ';
    L['\n'] = '\n';
    
    for( int i = strlen( P ) - 1; i; --i )
        L[P[i]] = P[i-1];
    
    char    c;
    while( ( c = getchar() ) != EOF )
        putchar( L[c] );
    
}
