// DFS
// 2810740 2008-03-30 01:21:18 Accepted 2100 C++ 00:00.24 840K ELF 

#include <iostream>
using namespace std;

char    A[7][8];
int     M,  N;
int     remain;

const int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

inline bool isValid( const int& x, const int& y ) {
    return  x >= 0 && x < M && y >= 0 && y < N && A[x][y] == '.';
}

void DFS( const int& x, const int& y ) {
    if( remain == 0 )   return;
    for( int i = 0; i < 4; i++ ) {
        if( isValid( x + pos[i][0], y + pos[i][1] ) ) {
            remain--;
            A[x + pos[i][0]][y + pos[i][1]] = 'X';
            DFS( x + pos[i][0], y + pos[i][1] );
            if( remain == 0 )   return;
            A[x + pos[i][0]][y + pos[i][1]] = '.';
            remain++;
        }
    }
}

int main() {
    while( ( cin >> M >> N ) && ( M || N ) ) {
        for( int i = 0; i < M; i++ )
            cin >> A[i];
        remain = -1;
        for( int i = 0; i < M; i++ )
            for( int j = 0; j < N; j++ )
                remain += ( A[i][j] == '.' );
        A[0][0] = 'X';
        DFS( 0, 0 );
        if( !remain )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
