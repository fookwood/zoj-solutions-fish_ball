#include <string>
#include <cctype> 
#include <vector>
#include <iostream>
using namespace std;

//////////////////////////  CLASS WINDOW  /////////////////////////////

class Window {
    public: 
	Window() {}	
	Window( char A );
	void disp(); 
	void stretchX( int x );
	void stretchY( int y );
	void mergeX( Window win );
	void mergeY( Window win );
//    private: 
	vector<string>	grid;
	int	X,	Y;	// X 为宽度, Y为高度
};

Window :: Window( char A ) {
	grid.resize(3);
	grid[0] += A;
	grid[0] += "-*";
	grid[1] = "| |";
	grid[2] = "*-*";
	X = Y = 2;
}

void Window :: disp() {
	for( int i = 0; i < grid.size(); i++ )
		cout << grid[i] << endl; 
} 
// 拉伸原来的窗口宽度到指定宽度 x, 记得修改成员 X 的值 
void Window :: stretchX( int x ) {
	vector<int>	pos(0),	val(0);
	for( int i = 0; i <= X ; i++ )
		if( grid[0][i] != '-' )
			pos.push_back( i + 1 );
	int	tot = 0; 
	for( int i = 1; i < pos.size(); i++ ) {
		val.push_back( pos[i] - pos[i - 1] );
		tot += val.back(); 
	}
	pos.pop_back();
	int	j = x - X;
	while( pos.size() ) {
		for( int k = 0; k <= Y; k++ )
		for( int i = 0; i < val.back() * j / tot; i++ ) 
			grid[k].insert( pos.back(), grid[k].substr( pos.back(), 1 ) ); 
		j -= val.back() * j / tot; 
		tot -= val.back();
		val.pop_back(); 
		pos.pop_back(); 
	} 
	X = x; 
}

void Window :: stretchY( int y ) {
	vector<int>	pos(0),	val(0);
	for( int i = 0; i <= Y ; i++ )
		if( grid[i][0] != '|' )
			pos.push_back( i + 1 );
	int	tot = 0; 
	for( int i = 1; i < pos.size(); i++ ) {
		val.push_back( pos[i] - pos[i - 1] );
		tot += val.back(); 
	}
	pos.pop_back();
	int	j = y - Y;
	while( pos.size() ) {
		for( int i = 0; i < val.back() * j / tot; i++ ) 
			grid.insert( grid.begin() + pos.back(), grid[pos.back()] ); 
		j -= val.back() * j / tot; 
		tot -= val.back();
		val.pop_back(); 
		pos.pop_back(); 
	} 
	Y = y; 
}

void Window :: mergeX( Window win ) {
	for( int i = 0; i <= Y; i++ ) {
		if( isupper( win.grid[i][0] ) )
			grid[i][X] = win.grid[i][0];
		win.grid[i].erase( 0, 1 ); 
		grid[i] += win.grid[i]; 
	}
	X = grid[0].size() - 1; 
}

void Window :: mergeY( Window win ) {
	for( int i = 0; i <= X; i++ )
		if( isupper( win.grid[0][i] ) )
			grid[Y][i] = win.grid[0][i];
	for( int i = 1; i <= win.Y; i++ )
		grid.push_back( win.grid[i] ); 
	Y = grid.size() - 1; 
}

//////////////////////////  CLASS TREE  /////////////////////////////

class Tree {
    public:
	void input();
	void disp(); 
	void simplify();
//    private:
	string	preorder;
	Window	subgrid[26];
};

void Tree :: input() {
	cin >> preorder;
	for( int i = 0; i < preorder.size(); i++ )
		if( isupper( preorder[i] ) )
			subgrid[preorder[i] - 'A'] = Window( preorder[i] );
}

void Tree :: disp() {
	subgrid[preorder[0] - 'A'].disp(); 
} 

void Tree :: simplify() {
	while( preorder.size() > 1 )
	for( int i = 0; i < preorder.size() - 2; i++ ) {
		if( !isupper( preorder[i] ) && isupper( preorder[i + 1] ) && isupper( preorder[i + 2] ) ) {
			Window	&winA = subgrid[preorder[i + 1] - 'A'];
			Window	&winB = subgrid[preorder[i + 2] - 'A'];
			if( preorder[i] == '-' ) {
				if( winA.X > winB.X ) winB.stretchX( winA.X );
				else if( winA.X < winB.X ) winA.stretchX( winB.X );
				winA.mergeY( winB );
			}
			else if( preorder[i] == '|' ) {
				if( winA.Y > winB.Y ) winB.stretchY( winA.Y );
				else if( winA.Y < winB.Y ) winA.stretchY( winB.Y );
				winA.mergeX( winB );
			}
			preorder[i] = preorder[i + 1];
			preorder.erase( i + 1, 2 ); 
			if( preorder.size() == 1 ) break;
		}
	}
} 

////////////////////////// MAIN PROCCEDURE //////////////////////////

int main() {
	Tree	T;
	int	N;
	cin >> N; 
	for( int i = 0; i < N; i++ ) {
		T.input();
		T.simplify();
		cout << i + 1 << endl;
		T.disp(); 
	}
} 
