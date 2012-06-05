// 骗了我好多 WA 啊！！
// 如果输入有 8 条边，前 5 条已经确认了所有关系，那么后面的即使矛盾也可以确认
// 也就是说，矛盾和最终确认是同优先级的！！
// 逻辑！！题目的叙述！！不 BS 一下对不起自己

// 算法是这样的，做一个图邻接矩阵
// 若 A < B 则存在 E<A,B>
// 做一个有向无权图，未标记为 -1
// 没加入一个关系 A<B
// 检查 adj[A][B]
// 若 0，则存在矛盾，标记矛盾 
// 若 1，则是重复的标记，跳过
// 若 -1，是一个新的关系，标记，计数加 1
//     并且，同样递归考察有没有 从别的边能到 A 的 (C<A)；
//     或者从 B 到别的点的 (B<C)；如果有，执行上述同样的判别
// 这样做逻辑比拓扑排序清晰，但有一点是递归的堆栈可能比较深，因此 400 多 K 的秒过 


#include <cstdio>
#include <cstring>

int	N,	Q;
char	adj[26][26],	oper[4];
int	inconsistency;
int	determine,	count;

void remark( int p1, int p2, int i ) {	
	// -1 是未标记是合法的，现标记之，并向前追溯
	if( adj[p1][p2] == -1 ) {
		adj[p1][p2] = 1;
		adj[p2][p1] = 0;
		// 每标记一个新路径都要增加一个计数 
		count++;
		// 考察有否可传递的点 
		for( int j = 0; j < N; j++ )
			if( adj[p2][j] == 1 )
				remark( p1, j, i );
		for( int j = 0; j < N; j++ )
			if( adj[j][p1] == 1 )
				remark( j, p2, i );
	} 
	// 1 是重复标记，直接跳出 
	else if( adj[p1][p2] == 1 ) return; 
	// 否则是 0，标记了一个矛盾
	else {
		inconsistency = i;
		return;
	}
}

int main() {
	while( scanf( "%d%d", &N, &Q ) && ( N || Q ) ) {
		memset( adj, -1, 676 );
		inconsistency = 0;
		determine = 0;
		count = 0; 
		int	p1,	p2;
		for( int i = 1; i <= Q; i++ ) {
			// 输入 
			scanf( "%s", oper );
			// 如果已经存在矛盾，跳过 
			if( inconsistency || determine ) continue;
			// 读取两个操作数 
			p1 = oper[0] - 'A';
			p2 = oper[2] - 'A';
			// 不允许自身相连 
			if( p1 == p2 ) {
				inconsistency = i;
				continue;
			}
			// 否则进行递归标记 
			remark( p1, p2, i );
			// 如果标记计数达到了 N * (N - 1) / 2，即是完成
			if( !determine && count == N * (N - 1) / 2 ) {
				determine = i; 
			}
		} 
		// 注意可能在全部确认之后引入矛盾，因此矛盾最为优先 
		if( inconsistency )
			printf( "Inconsistency found after %d relations.\n", inconsistency );
		else if( determine ) {
			printf( "Sorted sequence determined after %d relations: ", determine );
			// 一个顶点有 k 各入边，他就排第 k
			char	output[27];
			output[N] = 0;
			for( int i = 0; i < N; i++ ) {
				int	k = 1; 
				for( int j = 0; j < N; j++ )
					k += adj[j][i];
				output[k] = 'A' + i; 
			}
			printf( "%s.\n", output );

		}
		// 否则就是没找到 
		else	printf( "Sorted sequence cannot be determined.\n" ); 
	}
}
