// 不难，注意输入输出就行 

#include <cstdio>

int main() {
	int	hh,	mm,	ss,	last = 0;
	float	speed = 0,	distance = 0;
	bool	begin = true;
	while( scanf( "%d:%d:%d", &hh, &mm, &ss ) != EOF ) {
		int	time = hh * 3600 + mm * 60 + ss;
		if( begin ) { last = time; begin = false; }
		distance += float( time - last ) * speed / 3600;
		last = time;
		if( getchar() == ' ' )
			scanf( "%f", &speed );
		else	
			printf( "%02d:%02d:%02d %.2f km\n",
			hh, mm, ss, distance );
	}
}
