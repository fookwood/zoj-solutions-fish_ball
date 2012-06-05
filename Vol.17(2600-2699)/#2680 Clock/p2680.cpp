// cstdio 的输入输出处理得很爽
// 角度的转化，比较明显，要考虑到时针非整格的情况
// 但千万不要用浮点就是了，宁可整倍扩大，否则会引入精度误差 

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Clock {
	int	x,	y,	angle;
	void getClock();
	void disp();
};

void Clock :: getClock() {
	scanf( "%d:%d", &x, &y ); 
	int	angle1 = y * 12,
		angle2 = ( x % 12 ) * 5 * 12 + y;
	angle = abs( angle1 - angle2 );
	if( angle > 360 ) angle = 720 - angle;
}

void Clock :: disp() {
	printf( "%02d:%02d\n", x, y );
}

bool icmp( Clock c1, Clock c2 ) {
	return	c1.angle <  c2.angle ||
		c1.angle == c2.angle &&
		( c1.x   <  c2.x     ||
		  c1.x   == c2.x     &&
		  c1.y   <  c2.y     );
}

int main() {
	Clock	C[5];
	int	T;
	scanf( "%d", &T );
	while( T-- ) {
		for( int i = 0; i < 5; i++ )
			C[i].getClock();
		sort( C, C + 5, icmp );
		C[2].disp();
	}
}
