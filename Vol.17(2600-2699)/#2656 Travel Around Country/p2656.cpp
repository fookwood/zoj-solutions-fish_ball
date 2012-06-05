// 这道题我自觉得做得太漂亮了
// 1.85s 468K 1AC 
// 真想知道排名第一的，怎么可以做到 < 1s 的

// 算法如下，实际上，两个参数 O 和 U，说白了就是一个 O - U
// 代表每个站的油量变化，只要从某个站开始直到结束，油量保持为正即可
// 从第一个开始累加，每当累加到负数的时候，将加到负的油量和城市编号压栈
// 这样到最后，得到的堆栈就是从某个正增量的站开始，走到最远的一段所耗费的油量
// 注意，这样的方式压栈，如果是可能的话，那就只有栈顶是正的
// 然后将堆栈所有元素都加起来，如果非负，那么该出发城市就是栈顶指定的城市
// 否则，不可能 

#include <cstdio>

int main() {
	int	N,	x1,	x2;
	int	fuel[10000],	top,	city[10000];
	while( scanf( "%d", &N ) != EOF ) {
		fuel[0] = city[0] = top = 0;
		for( int i = 0; i < N; i++ ) {
			scanf( "%d%d", &x1, &x2 );
			fuel[top] += ( x1 - x2 );
			if( fuel[top] < 0 || i == N - 1 ) {
				fuel[++top] = 0;
				city[top] = i + 1;
			}
		}
		for( int i = 1; i < top; i++ ) fuel[i] += fuel[i - 1];
		if( fuel[top - 1] < 0 ) printf( "impossible\n" );
		else			printf( "%d\n", city[top - 1] );
	}
}
