// 仿佛一直在打补丁，难看得要死的程序
// 不过其实还好，他说没有一元的 + - 运算符，也相当简化了 

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	char	equ[256];
	int	T;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%s", equ );
		// i 为当前扫描指针，j 为每节数字串开始的位置 
		int	i = 0,	j = 0;
		// x 为 x 的系数，num 为常数项 
		int	x = 0,	num = 0;
		// 符号，当前符号为 sign，若果已经超过等号，需外加一个负号 
		int	sign = 1, past = 1;
		// 退出标记 
		bool	exit = false;
		// 读取所有等式中的信息 
		while( 1 ) {
			// i 向前走一个项 
			while( equ[i] && equ[i] != '=' &&
			       equ[i] != '-' && equ[i] != '+' ) i++;
			// 先处理好符号问题 
			int	label = sign * past;
			if( equ[i] == '+' ) sign = 1;
			else if( equ[i] == '-' ) sign = -1;
			else if( equ[i] == '=' ) { past = -1; sign = 1; } 
			else if( !equ[i] ) exit = true; 
			// 假如这个是含 x 的项
			if( equ[i - 1] == 'x' ) {
				equ[i - 1] = 0;
				int	temp = atoi( equ + j );
				if( !temp ) temp++;
				x += ( label * temp );
			}
			// 否则就是常数项 
			else {
				equ[i] = 0;
				int	temp = atoi( equ + j );
				num += ( label * temp ); 
			}
			// 退出条件 
			if( exit ) break;
			j = ++i;
		}
		if( !x ) if( num ) printf( "IMPOSSIBLE\n" );
		else printf( "IDENTITY\n" );
		else {
			if( num % x == 0 ) printf( "%d\n", num / -x );
			else {
				int	ans = num / -x;
				if( ans < 0 ) ans--;
				printf( "%d\n", ans );
			} 
		}
	}
}
