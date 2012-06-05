// 这都不能上榜~~ 这是超简单题，不过既然是上榜的高手，肯定有超乎想象的手段 
// 2809781 2008-03-29 17:21:35 Accepted 2060 C++ 00:00.02 388K 呆滞的慢板 
#include <cstdio>

int main() {
    int     N;
    while( scanf( "%d", &N ) != EOF )
        puts( ( ( N + 2 ) & 3 ) ? "no" : "yes" );
}
