// 稍为变通的 BFS 

#include <deque>
#include <iostream>
using namespace std;

struct Piece {
    Piece() {}
    Piece( int xx, int yy, int zz, int s ) :
        x(xx), y(yy), z(zz), step(s) {}
    int     x,  y,  z;
    int     step;
};

int     N;
bool    A[50][50][50];
char    adj[50][50];
Piece   temp;

int main() {
    char    input[2],   color;
    int     x,  y,  z;
    deque<Piece>    Q;
    while( ( cin >> N ) && N ) {
        cin >> temp.x >> temp. y >> temp.z;
        temp.x--;
        temp.y--;
        temp.z--;
        temp.step = 0;
        for( int i = 0; i < N; i++ ) {
            for( int j = 0; j < N; j++ ) {
                cin >> input;
                adj[i][j] = *input;
                for( int k = 0; k < N; k++ )
                    A[i][j][k] = false;
            }
        }
        Q.resize( 0 );
        Q.push_back( temp );
        A[temp.x][temp.y][temp.z] = true;
        while( !Q.empty() ) {
            temp = Q.front();
            Q.pop_front();
            x = temp.x, y = temp.y, z = temp.z;
            if( x == y && x == z )  break;
            color = adj[y][z];
            for( int i = 0; i < N; i++ ) {
                if( adj[x][i] == color && !A[i][y][z] ) {
                    Q.push_back( Piece( i, y, z, temp.step + 1 ) );
                    A[i][y][z] = true;
                }
            }
            color = adj[x][z];
            for( int i = 0; i < N; i++ ) {
                if( adj[y][i] == color && !A[x][i][z] ) {
                    Q.push_back( Piece( x, i, z, temp.step + 1 ) );
                    A[x][i][z] = true;
                }
            }
            color = adj[x][y];
            for( int i = 0; i < N; i++ ) {
                if( adj[z][i] == color && !A[x][y][i] ) {
                    Q.push_back( Piece( x, y, i, temp.step + 1 ) );
                    A[x][y][i] = true;
                }
            }
        }
        if( temp.x == temp.y && temp.x == temp.z )
            cout << temp.step << endl;
        else
            cout << "impossible" << endl;
    }
}
