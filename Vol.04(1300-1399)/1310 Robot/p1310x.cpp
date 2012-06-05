#include <iostream>
#include <string>
#include <deque>
using namespace std;

int     M,  N;
bool    A[52][52],  B[52][52][4];

enum Direction { north = 0, east = 1, south = 2, west = 3 };

struct Robot {
    Robot() {}
    Robot( int x, int y, int l, Direction s ) :
        X(x), Y(y), step(l), D(s) {}
    Robot   forward( int n ) {
        switch( D ) {
            case north:	return	Robot( X - n, Y, step + 1, north );
            case south:	return	Robot( X + n, Y, step + 1, south );
            case east:	return	Robot( X, Y + n, step + 1, east );
            case west:	return	Robot( X, Y - n, step + 1, west );
        }
    }
    Robot   right() { return Robot( X, Y, step + 1, Direction( ( D + 1 ) % 4 ) ); }
    Robot   left()  { return Robot( X, Y, step + 1, Direction( ( D + 3 ) % 4 ) ); }
    bool    isValid() { return !( X < 0 || X >= M || Y < 0 || Y >= N ) && B[X][Y][D]; }
    int	X,	Y;
    int	step;
    Direction	D;
};

int main() {
    deque<Robot>	Q;
    int	B1,	B2,	E1,	E2;
    char	dir[6];
    while( ( cin >> M >> N ) && ( M || N ) ) {
        for( int i = 0; i < M; i++ )
            for( int j = 0; j < N; j++ )
                cin >> A[i][j];
        M--;    N--;
        for( int i = 0; i < M; i++ )
            for( int j = 0; j < N; j++ )
                for( int d = 0; d < 4; d++ )
                    B[i][j][d] = !( A[i][j] || A[i+1][j] || A[i+1][j+1] || A[i][j+1] );
        cin >> B1 >> B2 >> E1 >> E2 >> dir;
        B1--;   B2--;   E1--;   E2--;
        Q.resize( 0 );
        Direction	tD;
        switch( *dir ) {
            case 'n': tD = north;   break;
            case 's': tD = south;   break;
            case 'e': tD = east;    break;
            case 'w': tD = west;    break;
        }
        Q.push_back( Robot( B1, B2, 0, tD ) );
        B[B1][B2][tD] = false;
        Robot   temp,   current;
        while( !Q.empty() ) {
            current = Q.front();
            if( current.X == E1 && current.Y == E2 ) break;
            Q.pop_front();
/*
cout<<"("<<current.X<<","<<current.Y<<")  ";
switch(current.D){case north:puts("north");break;
case east:puts("east");break;
case west:puts("west");break;
case south:puts("south");break;}
cout<<"step = "<<current.step<<endl;
for( int i = 0; i < M; i++ ){
for( int j = 0; j < N; j++ )
cout<<B[i][j]<<' ';cout<<endl;}cout<<endl;
system("pause");
//*/
            temp = current.right();
            if( temp.isValid() ) {
                Q.push_back( temp );
                B[temp.X][temp.Y][temp.D] = false;
            }
            temp = current.left();
            if( temp.isValid() ) {
                Q.push_back( temp );
                B[temp.X][temp.Y][temp.D] = false;
            }
            for( int j = 1; j <= 3; j++ ) {
                temp = current.forward( j );
                if( temp.isValid() ) {
                    Q.push_back( temp );
                    B[temp.X][temp.Y][temp.D] = false;
                }
                else    break;
            }
        }
        if( Q.empty() )	cout << -1 << endl;
        else            cout << current.step <<endl;
    }
}
