// 简单，规模非常小，只是第一次读错题了
// 点一个窗口的时候不会令它置顶 
#include <iostream>
using namespace std;

struct Window {
    public:
	void input() { cin >> x1 >> y1 >> x2 >> y2; }
	bool inside( int x, int y )
		{ return x >= x1 && x <= x2 && y >= y1 && y <= y2; }
    private:
	int	x1,	y1,	x2,	y2;
};

int main() {
	int	N,	C,	x,	y;
	Window	set[10];
	while( ( cin >> N ) && N ) {
		for( int i = 0; i < N; i++ ) set[i].input();
		cin >> C;
		while( C-- ) {
			cin >> x >> y;
			for( int i = N - 1; i >= 0; i-- ) {
				if( set[i].inside( x, y ) ) {
					cout << i << endl;
					break;
				}
				if( !i ) cout << -1 << endl;
			}
		}
	}
}
