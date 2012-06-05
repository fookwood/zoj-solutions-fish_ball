// 特殊的数据结构题：并集树 RPWT
// 开始我做 TLE 了好几次，其实离成功一步之遥
// 用一个 int 数据组双用途存放数据，每个节点都是个叶子
// 如果存放的是正数，则代表其双亲的下标
// 如果存放的是负数，则代表这棵树的节点数
// 初始化时，所有的节点都赋值 -1 (只有一个元素(自己)的集合) 
// 当新增一个连接 x ~ y 的时候，先对 x 结点和 y 结点朔源(找到他们所在的集合树的根)
// 如果同源，证明已经在同一个集合中，不用操作
// 否则，令 x 所在的树根指向 y 的树根，并且令 y 的树根值(负数)加上 x 原来树根的个数 
// 查找的时候，朔源，并且输出树根值即可，同时，对树进行压缩
// 先朔源找到树根，然后再次从所查询的叶子开始，令每一个中途节点都指向这个树根
// 那么，从所查询的叶子往上的所有节点，高度降到了 1

// 开始我做的 TLE 就是因为没有做压缩高度处理，改了之后就过了
// 感谢“冗余的代码”博客 http://cruxd.programfan.com 提供的解题报告！ 

#include <cstring>
#include <cstdio>

int main() {
	int	N,	M,	T = 0;
	int	x,	y,	root,	temp;
	char	op[2];
	int	P[100001];
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		if( T++ ) putchar( '\n' );
		printf( "Case %d:\n", T );
		for( int i = 1; i <= N; i++ ) P[i] = -1;
		while( M-- ) {
			scanf( "%s", op );
			if( *op == 'M' ) {
				scanf( "%d%d", &x, &y );
				while( P[x] > 0 )	x = P[x];
				while( P[y] > 0 )	y = P[y];
				if( x != y ) {
					P[y] += P[x];
					P[x] = y;
				}
			}
			else {
				scanf( "%d", &x );
				root = x;
				while( P[root] > 0 )	root = P[root];
				while( P[x] > 0 ) {
					temp = x;
					x = P[x];
					P[temp] = root;
				}
				printf( "%d\n", -P[x] );
			}
		}
	}
}
